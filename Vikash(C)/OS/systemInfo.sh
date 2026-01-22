#!/bin/bash

echo "===== SYSTEM STATUS ====="

echo "Hostname: $(hostname)"
echo "User: $(whoami)"
echo "OS Info: $(uname -o)"
echo "Kernel Version: $(uname -r)"

echo
echo "===== CPU INFO ====="
lscpu | grep "Model name"

echo
echo "===== MEMORY (RAM) ====="
free -h

echo
echo "===== DISK USAGE ====="
df -h /

echo
echo "===== SYSTEM UPTIME ====="
uptime
