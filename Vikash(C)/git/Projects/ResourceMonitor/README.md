# Linux Resource Monitor

A simple, lightweight system resource monitor for Linux similar to `htop` but with a minimal, easy-to-understand interface.

## Features

- **Real-time CPU Usage**: Displays current CPU utilization with visual progress bar
- **Memory Usage**: Shows RAM consumption with color-coded indicators
  - Green: < 50%
  - Yellow: 50-80%
  - Red: > 80%
- **Top Processes**: Lists the top 10 processes by CPU usage with their memory consumption
- **System Information**: Shows hostname, kernel version, and uptime
- **Load Average**: Displays 1, 5, and 15-minute load averages

## Requirements

- Linux system with `/proc` filesystem
- Bash shell
- Standard utilities: `grep`, `awk`, `sort`

## Usage

```bash
./ResourceMonitor.sh
```

The monitor will display system information and update every 2 seconds. Press `CTRL+C` to exit.

## What It Shows

```
═════════════════════════════════════════════════════
        LINUX RESOURCE MONITOR
═════════════════════════════════════════════════════

Hostname: your-machine
Kernel: 5.10.0-...
Uptime: 12d 5h 30m

─────────────────────────────────────────────────────
CPU USAGE
─────────────────────────────────────────────────────
[████████░░░░░░░░░░░░] 44%
Load Average (1m, 5m, 15m): 1.23 0.95 0.87

─────────────────────────────────────────────────────
MEMORY USAGE
─────────────────────────────────────────────────────
Used: 8 GB / Total: 15 GB
[██████░░░░░░░░░░░░░░] 54%

─────────────────────────────────────────────────────
TOP PROCESSES (by CPU usage)
─────────────────────────────────────────────────────
PID     CPU%       MEM(MB)      CMD
─────────────────────────────────────────────────────
1234    5432       256          firefox
...
```

## How It Works

The monitor reads system information directly from the Linux `/proc` filesystem:

- **CPU Usage**: `/proc/stat` - Reads total and idle CPU ticks
- **Memory Usage**: `/proc/meminfo` - Reads MemTotal and MemAvailable
- **Process Info**: `/proc/[pid]/stat` - Individual process statistics
- **Process Memory**: `/proc/[pid]/status` - VmRSS (resident memory)
- **System Info**: `/proc/uptime` - System uptime
- **Load Average**: `/proc/loadavg` - Load information

## Configuration

Edit the script to change these variables:

```bash
REFRESH_INTERVAL=2        # Update interval in seconds
TOP_PROCESSES=10          # Number of top processes to display
```

## Performance Notes

- The script reads `/proc` filesystem which has minimal performance impact
- Calculating top processes iterates through active process directories
- On systems with many processes (1000+), the display update may take 1-2 seconds

## Troubleshooting

**Script won't run**: Make sure it's executable
```bash
chmod +x ResourceMonitor.sh
```

**Permission denied**: May need elevated privileges to see all process details
```bash
sudo ./ResourceMonitor.sh
```

**Inaccurate CPU calculations**: The first reading initializes the calculation. CPU percentage stabilizes after 2+ refreshes.

## Differences from htop

| Feature | Resource Monitor | htop |
|---------|------------------|------|
| Complexity | Simple, minimal | Full-featured |
| Dependencies | Only bash/proc | Requires htop package |
| Learning curve | Easy | Steeper |
| Customization | Edit script | Interactive |
| Memory footprint | Minimal | Moderate |

## License

Public Domain / Feel free to modify and use freely
