# Log Archive Tool

A powerful CLI utility for archiving and compressing log files on Unix-based systems. This tool automates the process of backing up logs, keeping your system clean while maintaining compressed archives for future reference.

## Features

✅ **Command-line Interface** - Simple, intuitive CLI with proper error handling  
✅ **Timestamp-based Naming** - Automatically generates archive names with date/time (e.g., `logs_archive_20240816_100648.tar.gz`)  
✅ **Automatic Compression** - Uses tar.gz for efficient compression  
✅ **Archive Management** - Stores all archives in a dedicated directory  
✅ **Operation Logging** - Maintains a log file tracking all archive operations with dates, times, and file sizes  
✅ **Color-coded Output** - Clear visual feedback with success, error, info, and warning messages  
✅ **Input Validation** - Verifies directory exists and is readable before archiving  

## Installation

1. **Download the script** to your desired location:
   ```bash
   cp Project2.sh /usr/local/bin/log-archive
   chmod +x /usr/local/bin/log-archive
   ```

2. **Or use it directly** from the current directory:
   ```bash
   chmod +x Project2.sh
   ```

## Usage

### Basic Usage

```bash
./log-archive <log-directory>
```

### Examples

Archive system logs:
```bash
./log-archive /var/log
```

Archive logs from a specific application:
```bash
./log-archive ./application_logs
```

Get help:
```bash
./log-archive --help
./log-archive -h
```

## How It Works

1. **Validates Input** - Checks if the provided log directory exists and is readable
2. **Creates Archive Directory** - If it doesn't exist, creates a `logs_archive` folder
3. **Generates Timestamp** - Creates a timestamp in format `YYYYMMDD_HHMMSS`
4. **Compresses Files** - Uses `tar -czf` to create a `.tar.gz` archive
5. **Records Operation** - Logs the archive operation with date, time, size, and status
6. **Provides Feedback** - Displays colored output showing success/status information

## Output

### Archive Files
Archives are stored in `logs_archive/` with timestamped names:
```
logs_archive/
├── logs_archive_20260219_143504.tar.gz  (218B)
├── logs_archive_20260219_144235.tar.gz  (256B)
└── archive.log  (operation history)
```

### Archive Log
The `archive.log` file tracks all operations:
```
Log Archive Tool - Archive History
===================================

Archive Date/Time: 2026-02-19 14:35:04
Archive Timestamp: 20260219_143504
Source Directory: test_logs
Archive File: logs_archive_20260219_143504.tar.gz
File Size: 218B
Status: SUCCESS
---
```

## Configuration

You can modify the archive directory by editing the script:

```bash
# Default: stores archives in ./logs_archive
ARCHIVE_DIR="./logs_archive"

# Change to:
ARCHIVE_DIR="/var/log/archives"  # Or any path you prefer
```

## Common Use Cases

### 1. Scheduled Daily Archives (Cron)
Add to your crontab to archive mails daily at 2 AM:
```bash
0 2 * * * /usr/local/bin/log-archive /var/log
```

### 2. Archive Multiple Directories
Create a wrapper script:
```bash
#!/bin/bash
/usr/local/bin/log-archive /var/log
/usr/local/bin/log-archive /var/www
/usr/local/bin/log-archive /home/user/app_logs
```

### 3. Automatic Cleanup (Archive + Delete)
```bash
#!/bin/bash
./log-archive /var/log
rm -rf /var/log/*  # Remove old logs (be careful!)
```

## Error Handling

The script handles various error scenarios:

| Error | Message | Cause |
|-------|---------|-------|
| No directory provided | `No log directory provided` | Missing argument |
| Directory not found | `Log directory does not exist` | Invalid path |
| Permission denied | `Log directory is not readable` | Insufficient permissions |
| Archive failed | `Failed to create archive` | Permission or disk space issue |

## Advanced Features

The tool includes:

- **Size Formatting** - Displays archive sizes in B, KB, MB, or GB
- **Color Output** - Green for success, red for errors, blue for info, yellow for warnings
- **Comprehensive Logging** - Tracks every operation with full details
- **Error Exit Codes** - Returns proper exit codes for scripting integration

## Future Enhancements

Potential improvements to the tool:

- [ ] Email notifications when archives are complete
- [ ] Send archives to remote server (FTP, SCP, cloud storage)
- [ ] Automatic cleanup of old archives (keep only last N)
- [ ] Backup status reporting
- [ ] Encryption support for sensitive logs
- [ ] Parallel compression for multiple directories
- [ ] Bandwidth throttling for remote uploads

## Testing

The included test setup creates sample logs:

```bash
mkdir -p test_logs
echo "Sample log 1" > test_logs/system.log
echo "Sample log 2" > test_logs/access.log

./log-archive test_logs
ls -la logs_archive/
```

## Requirements

- Bash shell (4.0+)
- `tar` command
- `gzip` utility
- Read permissions on the log directory
- Write permissions in the current directory

## Troubleshooting

**Q: "Permission denied" error**  
A: Run with sudo if needed: `sudo ./log-archive /var/log`

**Q: Archive is very large**  
A: Consider filtering specific files in the source directory before archiving

**Q: Want to verify archive contents**  
A: Use: `tar -tzf logs_archive/logs_archive_*.tar.gz | head`

## License

Free to use and modify. Created for educational and practical Linux administration purposes.

---

**Author**: Created for log management automation  
**Version**: 1.0  
**Last Updated**: February 19, 2026
