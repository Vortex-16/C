#!/bin/bash

# Backup Script
# Takes backup of folders into .tar.gz

BACKUP_DIR="${BACKUP_DIR:=$HOME/backups}"
TIMESTAMP=$(date +%Y%m%d_%H%M%S)

show_usage() {
    echo "Usage: $0 [OPTIONS]"
    echo ""
    echo "Options:"
    echo "  -s, --source <path>    Source directory to backup"
    echo "  -d, --dest <path>      Backup destination (default: ~/backups)"
    echo "  -n, --name <name>      Backup name (default: backup_<timestamp>)"
    echo "  -c, --cron             Setup automatic daily backup in cron"
    echo "  -l, --list             List all backups"
    echo "  -r, --restore <file>   Restore from backup file"
    echo ""
    echo "Example:"
    echo "  $0 -s ~/Documents -d ~/backups"
    echo "  $0 -c -s ~/Documents"
}

if [ $# -eq 0 ]; then
    show_usage
    exit 1
fi

# Parse command line arguments
SOURCE_DIR=""
BACKUP_NAME="backup_$TIMESTAMP"
CRON_MODE=false
LIST_MODE=false
RESTORE_FILE=""

while [[ $# -gt 0 ]]; do
    case $1 in
        -s|--source)
            SOURCE_DIR="$2"
            shift 2
            ;;
        -d|--dest)
            BACKUP_DIR="$2"
            shift 2
            ;;
        -n|--name)
            BACKUP_NAME="$2"
            shift 2
            ;;
        -c|--cron)
            CRON_MODE=true
            shift
            ;;
        -l|--list)
            LIST_MODE=true
            shift
            ;;
        -r|--restore)
            RESTORE_FILE="$2"
            shift 2
            ;;
        *)
            echo "Unknown option: $1"
            show_usage
            exit 1
            ;;
    esac
done

# List backups
if [ "$LIST_MODE" = true ]; then
    echo "Available Backups:"
    echo "========================"
    if [ -d "$BACKUP_DIR" ]; then
        ls -lhS "$BACKUP_DIR"/*.tar.gz 2>/dev/null | awk '{print $5, $9}' | column -t
        echo "========================"
        echo "Total backups: $(ls -1 "$BACKUP_DIR"/*.tar.gz 2>/dev/null | wc -l)"
    else
        echo "No backups found in $BACKUP_DIR"
    fi
    exit 0
fi

# Restore from backup
if [ -n "$RESTORE_FILE" ]; then
    if [ ! -f "$RESTORE_FILE" ]; then
        echo "Error: Backup file '$RESTORE_FILE' not found!"
        exit 1
    fi
    echo "Restoring from backup: $RESTORE_FILE"
    tar -xzf "$RESTORE_FILE" -C "$HOME"
    echo "Backup restored successfully!"
    exit 0
fi

# Backup mode
if [ -z "$SOURCE_DIR" ]; then
    echo "Error: Source directory not specified!"
    show_usage
    exit 1
fi

if [ ! -d "$SOURCE_DIR" ]; then
    echo "Error: Source directory '$SOURCE_DIR' does not exist!"
    exit 1
fi

# Create backup directory
mkdir -p "$BACKUP_DIR"

BACKUP_FILE="$BACKUP_DIR/${BACKUP_NAME}.tar.gz"

echo "Starting backup process..."
echo "Source: $SOURCE_DIR"
echo "Destination: $BACKUP_FILE"
echo ""

# Create backup
tar -czf "$BACKUP_FILE" -C "$(dirname "$SOURCE_DIR")" "$(basename "$SOURCE_DIR")" 2>/dev/null

if [ $? -eq 0 ]; then
    SIZE=$(du -h "$BACKUP_FILE" | cut -f1)
    echo "Backup completed successfully!"
    echo "Size: $SIZE"
else
    echo "Backup failed!"
    exit 1
fi

# Setup cron job for daily backup
if [ "$CRON_MODE" = true ]; then
    CRON_CMD="0 2 * * * tar -czf $BACKUP_DIR/backup_\$(date +\\%Y\\%m\\%d).tar.gz -C $(dirname "$SOURCE_DIR") $(basename "$SOURCE_DIR")"
    
    # Check if cron job already exists
    if crontab -l 2>/dev/null | grep -q "$SOURCE_DIR"; then
        echo "Cron job for this directory already exists"
    else
        # Add cron job (2 AM daily)
        (crontab -l 2>/dev/null; echo "$CRON_CMD") | crontab - 2>/dev/null
        echo "✓ Cron job scheduled for daily backup at 2:00 AM"
    fi
fi
