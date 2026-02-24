#!/bin/bash

# System Info Tool
# Shows RAM, CPU, Disk, Uptime (like a mini neofetch)

show_system_info() {
    # Color codes
    RED='\033[0;31m'
    GREEN='\033[0;32m'
    BLUE='\033[0;34m'
    YELLOW='\033[1;33m'
    CYAN='\033[0;36m'
    WHITE='\033[1;37m'
    NC='\033[0m' # No Color
    
    clear
    
    echo -e "${CYAN}╔════════════════════════════════════════╗${NC}"
    echo -e "${CYAN}║        SYSTEM INFORMATION REPORT       ║${NC}"
    echo -e "${CYAN}╚════════════════════════════════════════╝${NC}"
    echo ""
    
    # OS Information
    echo -e "${BLUE}━━━━━━ OS Information ━━━━━━${NC}"
    OS=$(uname -s)
    KERNEL=$(uname -r)
    HOSTNAME=$(hostname)
    
    echo -e "  ${GREEN}Hostname:${NC}     $HOSTNAME"
    echo -e "  ${GREEN}OS:${NC}            $OS"
    echo -e "  ${GREEN}Kernel:${NC}        $KERNEL"
    echo ""
    
    # CPU Information
    echo -e "${BLUE}━━━━━━ CPU Information ━━━━━━${NC}"
    CPU_MODEL=$(lscpu | grep 'Model name' | cut -d':' -f2- | xargs)
    CPU_CORES=$(nproc)
    CPU_FREQ=$(lscpu | grep 'CPU max MHz' | cut -d':' -f2- | xargs)
    
    echo -e "  ${GREEN}Model:${NC}         $CPU_MODEL"
    echo -e "  ${GREEN}Cores:${NC}         $CPU_CORES"
    if [ -n "$CPU_FREQ" ]; then
        echo -e "  ${GREEN}Max Freq:${NC}      $CPU_FREQ MHz"
    fi
    echo ""
    
    # CPU Usage
    CPU_USAGE=$(top -bn1 | grep "Cpu(s)" | awk '{print 100 - $8}' | cut -d'.' -f1)
    echo -e "  ${GREEN}CPU Usage:${NC}      ${RED}${CPU_USAGE}%${NC}"
    echo ""
    
    # RAM Information
    echo -e "${BLUE}━━━━━━ Memory Information ━━━━━━${NC}"
    RAM_TOTAL=$(free -h | grep Mem | awk '{print $2}')
    RAM_USED=$(free -h | grep Mem | awk '{print $3}')
    RAM_AVAILABLE=$(free -h | grep Mem | awk '{print $7}')
    RAM_PERCENT=$(free | grep Mem | awk '{printf("%.0f", ($3/$2)*100)}')
    
    echo -e "  ${GREEN}Total RAM:${NC}     $RAM_TOTAL"
    echo -e "  ${GREEN}Used RAM:${NC}      $RAM_USED"
    echo -e "  ${GREEN}Available:${NC}     $RAM_AVAILABLE"
    echo -e "  ${GREEN}Usage:${NC}         ${RED}${RAM_PERCENT}%${NC}"
    echo ""
    
    # Swap Information
    SWAP_TOTAL=$(free -h | grep Swap | awk '{print $2}')
    SWAP_USED=$(free -h | grep Swap | awk '{print $3}')
    
    echo -e "  ${GREEN}Swap Total:${NC}    $SWAP_TOTAL"
    echo -e "  ${GREEN}Swap Used:${NC}     $SWAP_USED"
    echo ""
    
    # Disk Information
    echo -e "${BLUE}━━━━━━ Disk Information ━━━━━━${NC}"
    df -h | grep -E '^/dev/' | while read line; do
        MOUNT=$(echo "$line" | awk '{print $NF}')
        SIZE=$(echo "$line" | awk '{print $2}')
        USED=$(echo "$line" | awk '{print $3}')
        AVAILABLE=$(echo "$line" | awk '{print $4}')
        PERCENT=$(echo "$line" | awk '{print $5}')
        
        echo -e "  ${GREEN}$MOUNT${NC}"
        echo -e "    Total: $SIZE | Used: $USED | Available: $AVAILABLE (${RED}$PERCENT${NC})"
    done
    echo ""
    
    # Uptime Information
    echo -e "${BLUE}━━━━━━ System Uptime ━━━━━━${NC}"
    UPTIME=$(uptime -p | sed 's/up //')
    BOOT_TIME=$(date -d "$(uptime -s)" '+%Y-%m-%d %H:%M:%S')
    
    echo -e "  ${GREEN}Uptime:${NC}        $UPTIME"
    echo -e "  ${GREEN}Boot Time:${NC}     $BOOT_TIME"
    echo ""
    
    # Load Average
    echo -e "${BLUE}━━━━━━ System Load ━━━━━━${NC}"
    LOAD=$(cat /proc/loadavg | awk '{print "1min: "$1" | 5min: "$2" | 15min: "$3}')
    echo -e "  ${GREEN}Load Average:${NC}  $LOAD"
    echo ""
    
    # User Information
    echo -e "${BLUE}━━━━━━ User Information ━━━━━━${NC}"
    CURRENT_USER=$(whoami)
    USER_COUNT=$(who | wc -l)
    
    echo -e "  ${GREEN}Current User:${NC}  $CURRENT_USER"
    echo -e "  ${GREEN}Users Logged:${NC}  $USER_COUNT"
    echo ""
    
    # Network Information
    echo -e "${BLUE}━━━━━━ Network Information ━━━━━━${NC}"
    IP_ADDR=$(hostname -I | awk '{print $1}')
    GATEWAY=$(ip route | grep default | awk '{print $3}')
    
    echo -e "  ${GREEN}IP Address:${NC}    $IP_ADDR"
    echo -e "  ${GREEN}Gateway:${NC}       $GATEWAY"
    echo ""
    
    echo -e "${CYAN}════════════════════════════════════════${NC}"
}

show_system_info
