#!/bin/bash

################################################################################
# Log Archive Tool
# 
# A utility to archive logs by compressing them and storing them in a new 
# directory. This helps remove old logs while maintaining them in compressed 
# format for future reference.
#
# Usage: ./log-archive <log-directory>
# Example: ./log-archive /var/log
################################################################################

set -euo pipefail

# Color codes for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Configuration
ARCHIVE_DIR="./logs_archive"
LOG_FILE="${ARCHIVE_DIR}/archive.log"

################################################################################
# Function: Display usage information
################################################################################
usage() {
    echo "Usage: $0 <log-directory>"
    echo ""
    echo "Arguments:"
    echo "  <log-directory>  Path to the directory containing logs to archive"
    echo ""
    echo "Examples:"
    echo "  $0 /var/log"
    echo "  $0 ./logs"
    exit 1
}

################################################################################
# Function: Display error message and exit
################################################################################
error_exit() {
    echo -e "${RED}[ERROR]${NC} $1" >&2
    exit 1
}

################################################################################
# Function: Display success message
################################################################################
success_msg() {
    echo -e "${GREEN}[SUCCESS]${NC} $1"
}

################################################################################
# Function: Display info message
################################################################################
info_msg() {
    echo -e "${BLUE}[INFO]${NC} $1"
}

################################################################################
# Function: Display warning message
################################################################################
warning_msg() {
    echo -e "${YELLOW}[WARNING]${NC} $1"
}

################################################################################
# Function: Initialize archive directory and log file
################################################################################
initialize() {
    if [ ! -d "$ARCHIVE_DIR" ]; then
        mkdir -p "$ARCHIVE_DIR"
        info_msg "Created archive directory: $ARCHIVE_DIR"
    fi
    
    if [ ! -f "$LOG_FILE" ]; then
        touch "$LOG_FILE"
        echo "Log Archive Tool - Archive History" > "$LOG_FILE"
        echo "===================================" >> "$LOG_FILE"
        echo "" >> "$LOG_FILE"
    fi
}

################################################################################
# Function: Log an archive operation
################################################################################
log_operation() {
    local timestamp="$1"
    local source_dir="$2"
    local archive_file="$3"
    local file_size="$4"
    local status="$5"
    
    {
        echo "Archive Date/Time: $(date '+%Y-%m-%d %H:%M:%S')"
        echo "Archive Timestamp: $timestamp"
        echo "Source Directory: $source_dir"
        echo "Archive File: $archive_file"
        echo "File Size: $file_size"
        echo "Status: $status"
        echo "---"
        echo ""
    } >> "$LOG_FILE"
}

################################################################################
# Function: Format file size for display
################################################################################
format_size() {
    local bytes=$1
    if [ $bytes -lt 1024 ]; then
        echo "${bytes}B"
    elif [ $bytes -lt 1048576 ]; then
        echo "$(( bytes / 1024 ))KB"
    elif [ $bytes -lt 1073741824 ]; then
        echo "$(( bytes / 1048576 ))MB"
    else
        echo "$(( bytes / 1073741824 ))GB"
    fi
}

################################################################################
# Main Script
################################################################################

# Check if log directory argument is provided
if [ $# -eq 0 ]; then
    error_exit "No log directory provided."
fi

if [ "$1" == "-h" ] || [ "$1" == "--help" ]; then
    usage
fi

LOG_DIR="$1"

# Validate that the log directory exists
if [ ! -d "$LOG_DIR" ]; then
    error_exit "Log directory does not exist: $LOG_DIR"
fi

# Validate that the log directory is readable
if [ ! -r "$LOG_DIR" ]; then
    error_exit "Log directory is not readable: $LOG_DIR"
fi

# Initialize archive directory
initialize

# Generate timestamp in the format: YYYYMMDD_HHMMSS
TIMESTAMP=$(date '+%Y%m%d_%H%M%S')
ARCHIVE_FILENAME="logs_archive_${TIMESTAMP}.tar.gz"
ARCHIVE_PATH="${ARCHIVE_DIR}/${ARCHIVE_FILENAME}"

info_msg "Starting log archive process..."
echo ""
echo "Source Directory: $LOG_DIR"
echo "Archive Directory: $ARCHIVE_DIR"
echo "Archive File: $ARCHIVE_FILENAME"
echo ""

# Create the tar.gz archive
info_msg "Compressing logs..."
if tar -czf "$ARCHIVE_PATH" -C "$(dirname "$LOG_DIR")" "$(basename "$LOG_DIR")" 2>/dev/null; then
    success_msg "Archive created successfully"
else
    error_exit "Failed to create archive"
fi

# Get the size of the created archive
ARCHIVE_SIZE=$(stat -f%z "$ARCHIVE_PATH" 2>/dev/null || stat -c%s "$ARCHIVE_PATH" 2>/dev/null)
FORMATTED_SIZE=$(format_size "$ARCHIVE_SIZE")

# Log the operation
log_operation "$TIMESTAMP" "$LOG_DIR" "$ARCHIVE_FILENAME" "$FORMATTED_SIZE" "SUCCESS"

# Display final summary
echo ""
echo "=========================================="
success_msg "Archive operation completed!"
echo "=========================================="
echo "Archive File: $ARCHIVE_PATH"
echo "Compressed Size: $FORMATTED_SIZE"
echo "Timestamp: $TIMESTAMP"
echo ""
info_msg "Archive log saved to: $LOG_FILE"
echo ""
echo "Recent archive entries:"
tail -n 15 "$LOG_FILE"
