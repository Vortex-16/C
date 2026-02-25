#!/bin/bash

# Linux Resource Monitor - Like htop but simpler
# Uses /proc filesystem for real-time system monitoring

set -e

# Color 
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
WHITE='\033[1;37m'
NC='\033[0m' 

# Configuration
REFRESH_INTERVAL=2
TOP_PROCESSES=10

# Function to clear screen
clear_screen() {
    clear
}

# Function to get CPU usage
get_cpu_usage() {
    local cpu_info=$(cat /proc/stat | grep "^cpu " | awk '{print $2+$3+$4+$5+$6+$7+$8, $5}')
    local user=$(echo $cpu_info | awk '{print $1}')
    local idle=$(echo $cpu_info | awk '{print $2}')
    local total=$((user + idle))
    
    if [ -z "$PREV_TOTAL" ]; then
        PREV_TOTAL=$total
        PREV_IDLE=$idle
        echo "CPU: Calculating..."
        return
    fi
    
    local total_diff=$((total - PREV_TOTAL))
    local idle_diff=$((idle - PREV_IDLE))
    local usage=$(( (total_diff - idle_diff) * 100 / total_diff ))
    
    PREV_TOTAL=$total
    PREV_IDLE=$idle
    
    echo $usage
}

# Function to get RAM usage
get_ram_usage() {
    local mem_info=$(grep -E 'MemTotal|MemAvailable' /proc/meminfo | awk '{print $2}')
    local mem_total=$(echo "$mem_info" | head -1)
    local mem_avail=$(echo "$mem_info" | tail -1)
    local mem_used=$((mem_total - mem_avail))
    
    echo "$mem_used:$mem_total"
}

# Function to format memory in human readable format
format_memory() {
    local kb=$1
    if [ $kb -gt 1048576 ]; then
        echo "$((kb / 1048576)) GB"
    elif [ $kb -gt 1024 ]; then
        echo "$((kb / 1024)) MB"
    else
        echo "$kb KB"
    fi
}

# Function to get top processes
get_top_processes() {
    local count=0
    echo -e "${CYAN}─────────────────────────────────────────────────────${NC}"
    echo -e "${CYAN}TOP PROCESSES (by CPU usage)${NC}"
    echo -e "${CYAN}─────────────────────────────────────────────────────${NC}"
    echo -e "${BLUE}PID${NC}    ${BLUE}CPU%${NC}    ${BLUE}MEM(MB)${NC}    ${BLUE}CMD${NC}"
    echo -e "${CYAN}─────────────────────────────────────────────────────${NC}"
    
    # Parse /proc to get process information
    for pid in $(ls -1 /proc 2>/dev/null | grep '^[0-9]\+' | sort -n); do
        if [ -f "/proc/$pid/stat" ] && [ -f "/proc/$pid/status" ]; then
            # Get CPU usage from /proc/stat
            local stat=$(cat "/proc/$pid/stat" 2>/dev/null)
            local utime=$(echo $stat | awk '{print $14}')
            local stime=$(echo $stat | awk '{print $15}')
            local cpu_ticks=$((utime + stime))
            
            # Get memory from /proc/status
            local vmrss=$(grep VmRSS "/proc/$pid/status" 2>/dev/null | awk '{print $2}')
            [ -z "$vmrss" ] && vmrss=0
            
            # Get command name
            local cmd=$(cat "/proc/$pid/comm" 2>/dev/null)
            [ -z "$cmd" ] && cmd="unknown"
            
            # Store in array for sorting (format: cpu_ticks:pid:mem:cmd)
            processes+=("$cpu_ticks:$pid:$vmrss:$cmd")
            
            count=$((count + 1))
            if [ $count -ge 100 ]; then
                break
            fi
        fi
    done
    
    # Sort by CPU usage (descending) and display top processes
    printf "%s\n" "${processes[@]}" | sort -t: -k1 -rn | head -n $TOP_PROCESSES | while IFS=: read -r cpu_ticks pid mem cmd; do
        local mem_mb=$((mem / 1024))
        printf "%-8s %-10s %-12s %-20s\n" "$pid" "$cpu_ticks" "$mem_mb MB" "$cmd"
    done
}

# Function to display CPU usage with visual bar
display_cpu_bar() {
    local usage=$1
    local filled=$((usage / 5))
    local empty=$((20 - filled))
    
    printf "["
    for ((i = 0; i < filled; i++)); do
        printf "${GREEN}█${NC}"
    done
    for ((i = 0; i < empty; i++)); do
        printf "░"
    done
    printf "] %d%%\n" "$usage"
}

# Function to display RAM usage
display_ram_bar() {
    local used=$1
    local total=$2
    local usage=$((used * 100 / total))
    local filled=$((usage / 5))
    local empty=$((20 - filled))
    
    printf "["
    if [ $usage -lt 50 ]; then
        for ((i = 0; i < filled; i++)); do
            printf "${GREEN}█${NC}"
        done
    elif [ $usage -lt 80 ]; then
        for ((i = 0; i < filled; i++)); do
            printf "${YELLOW}█${NC}"
        done
    else
        for ((i = 0; i < filled; i++)); do
            printf "${RED}█${NC}"
        done
    fi
    
    for ((i = 0; i < empty; i++)); do
        printf "░"
    done
    printf "] %d%%\n" "$usage"
}

# Function to display uptime
get_uptime() {
    local uptime_seconds=$(cat /proc/uptime | awk '{print $1}' | cut -d. -f1)
    local days=$((uptime_seconds / 86400))
    local hours=$(((uptime_seconds % 86400) / 3600))
    local minutes=$(((uptime_seconds % 3600) / 60))
    
    if [ $days -gt 0 ]; then
        echo "${days}d ${hours}h ${minutes}m"
    elif [ $hours -gt 0 ]; then
        echo "${hours}h ${minutes}m"
    else
        echo "${minutes}m"
    fi
}

# Function to get system load avg
get_load_average() {
    cat /proc/loadavg | awk '{print $1, $2, $3}'
}

# Function to get number of running processes
get_proc_count() {
    cat /proc/stat | grep "^procs_running" | awk '{print $2}'
}

# Function to display header
show_header() {
    echo -e "${BLUE}═════════════════════════════════════════════════════${NC}"
    echo -e "${BLUE}        LINUX RESOURCE MONITOR${NC}"
    echo -e "${BLUE}═════════════════════════════════════════════════════${NC}"
}

# Function to display footer
show_footer() {
    echo -e "${BLUE}═════════════════════════════════════════════════════${NC}"
    echo -e "${YELLOW}Press CTRL+C to exit${NC}"
}

# Function to display system info
show_system_info() {
    echo -e "${CYAN}Hostname:${NC} $(hostname)"
    echo -e "${CYAN}Kernel:${NC} $(uname -r)"
    echo -e "${CYAN}Uptime:${NC} $(get_uptime)"
    echo ""
}

# Main monitoring loop
main() {
    PREV_TOTAL=""
    PREV_IDLE=""
    
    trap 'echo -e "\n${YELLOW}Exiting Resource Monitor...${NC}"; exit 0' INT TERM
    
    while true; do
        clear_screen
        show_header
        show_system_info
        echo -e "${CYAN}─────────────────────────────────────────────────────${NC}"
        echo -e "${CYAN}CPU USAGE${NC}"
        echo -e "${CYAN}─────────────────────────────────────────────────────${NC}"
        cpu_usage=$(get_cpu_usage)
        if [ "$cpu_usage" != "CPU: Calculating..." ]; then
            display_cpu_bar $cpu_usage
        else
            echo "Calculating..."
        fi
        load_avg=$(get_load_average)
        echo -e "${CYAN}Load Average (1m, 5m, 15m):${NC} $load_avg"
        echo ""

        echo -e "${CYAN}─────────────────────────────────────────────────────${NC}"
        echo -e "${CYAN}MEMORY USAGE${NC}"
        echo -e "${CYAN}─────────────────────────────────────────────────────${NC}"
        ram=$(get_ram_usage)
        mem_used=$(echo "$ram" | cut -d: -f1)
        mem_total=$(echo "$ram" | cut -d: -f2)
        
        used_formatted=$(format_memory $mem_used)
        total_formatted=$(format_memory $mem_total)
        
        echo -e "${CYAN}Used:${NC} $used_formatted / ${CYAN}Total:${NC} $total_formatted"
        display_ram_bar $mem_used $mem_total
        echo ""
        
        processes=()
        get_top_processes
        echo ""
        
        show_footer
        
        sleep $REFRESH_INTERVAL
    done
}

main
