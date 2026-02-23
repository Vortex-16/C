# 🛠️ Shell Script Utilities Collection

A comprehensive collection of 5 powerful shell scripts for file management, backups, system monitoring, password generation, and note management.

---

## 📋 Table of Contents

1. [Smart File Organizer](#smart-file-organizer)
2. [Backup Script](#backup-script)
3. [System Info Tool](#system-info-tool)
4. [Password Generator](#password-generator)
5. [Notes Manager (CLI)](#notes-manager-cli)

---

## 🗂️ Smart File Organizer

**File:** `smartFileManager.sh`

Auto-sorts files into folders (PDFs, Images, Videos, Code, Documents, Archives, Audio, Executables, and Others).

### Usage
```bash
./smartFileManager.sh <path-to-organize>
```

### Examples
```bash
# Organize Downloads folder
./smartFileManager.sh ~/Downloads

# Organize Desktop
./smartFileManager.sh ~/Desktop

# Organize current directory
./smartFileManager.sh .
```

### Features
- ✅ Automatic categorization by file type
- ✅ Creates folders if they don't exist
- ✅ Moves uncategorized files to "Others" folder
- ✅ Displays summary of organized files
- ✅ Safe operation with error checking

### Supported Categories
- **PDF**: .pdf files
- **Images**: .jpg, .jpeg, .png, .gif, .bmp, .svg, .webp
- **Videos**: .mp4, .mkv, .avi, .mov, .flv, .wmv
- **Audio**: .mp3, .wav, .flac, .aac, .m4a, .wma
- **Documents**: .doc, .docx, .xls, .xlsx, .ppt, .pptx, .txt, .odt
- **Archives**: .zip, .rar, .7z, .tar, .gz
- **Code**: .c, .cpp, .h, .hpp, .js, .py, .java, .rb, .go, .rs, .sh, .php
- **Executables**: .exe, .bin, .sh, .bat
- **Others**: Any uncategorized files

---

## 💾 Backup Script

**File:** `backupScript.sh`

Takes backups of folders into compressed .tar.gz archives with optional automatic daily scheduling via cron.

### Usage
```bash
./backupScript.sh [OPTIONS]
```

### Options
```
-s, --source <path>    Source directory to backup (required for backup)
-d, --dest <path>      Backup destination (default: ~/backups)
-n, --name <name>      Backup name (default: backup_<timestamp>)
-c, --cron             Setup automatic daily backup in cron (2:00 AM)
-l, --list             List all existing backups
-r, --restore <file>   Restore from backup file
```

### Examples
```bash
# Single backup
./backupScript.sh -s ~/Documents -d ~/backups

# Backup with custom name
./backupScript.sh -s ~/Projects -d ~/backups -n "project_backup"

# Setup automatic daily backup
./backupScript.sh -s ~/Documents -c

# List all backups
./backupScript.sh -l

# Restore from backup
./backupScript.sh -r ~/backups/backup_20260223_102030.tar.gz
```

### Features
- ✅ Create compressed .tar.gz backups
- ✅ Automatic daily scheduling with cron
- ✅ List all existing backups
- ✅ Restore from backup archives
- ✅ Display backup size
- ✅ Timestamp-based naming
- ✅ Safe duplicate checks

### Daily Backup Setup
When using `-c` flag, backups are scheduled at **2:00 AM daily**. The cron job can be managed with:
```bash
crontab -l    # View scheduled jobs
crontab -e    # Edit scheduled jobs
crontab -r    # Remove all jobs
```

---

## 🖥️ System Info Tool

**File:** `systemInfoTool.sh`

Displays comprehensive system information similar to neofetch, including RAM, CPU, Disk, and Uptime.

### Usage
```bash
./systemInfoTool.sh
```

### Information Displayed
- **OS Information**: Hostname, OS Type, Kernel Version
- **CPU Information**: Model, Number of Cores, Max Frequency, Current Usage
- **Memory Information**: Total RAM, Used RAM, Available RAM, Usage Percentage
- **Swap Information**: Total Swap, Used Swap
- **Disk Information**: Per-filesystem breakdown with usage percentages
- **System Uptime**: Total uptime and boot time
- **Load Average**: 1-minute, 5-minute, and 15-minute load averages
- **User Information**: Current user and number of logged-in users
- **Network Information**: IP address and gateway

### Example Output
```
╔════════════════════════════════════════╗
║        SYSTEM INFORMATION REPORT       ║
╚════════════════════════════════════════╝

━━━━━━ OS Information ━━━━━━
  Hostname:     ubuntu-machine
  OS:           Linux
  Kernel:       6.5.0-1017-azure

━━━━━━ CPU Information ━━━━━━
  Model:        Intel Core i7-10700K
  Cores:        8
  Max Freq:     3800 MHz
  CPU Usage:    15%
```

### Features
- ✅ Color-coded output for easy reading
- ✅ Real-time CPU usage percentage
- ✅ Detailed memory breakdown
- ✅ Per-filesystem disk usage
- ✅ System load information
- ✅ Network configuration details

---

## 🔐 Password Generator

**File:** `passwordGenerator.sh`

Generates strong random passwords using `/dev/urandom` with various complexity levels and options.

### Usage
```bash
./passwordGenerator.sh [OPTIONS]
```

### Options
```
-l, --length <number>   Password length (default: 16)
-c, --count <number>    Generate multiple passwords (default: 1)
-t, --type <type>       Password type:
                        - basic    (alphanumeric only)
                        - strong   (alphanumeric + symbols)
                        - complex  (all characters)
-s, --special           Include special characters
-C, --clipboard         Copy password to clipboard
-h, --help              Show help message
```

### Examples
```bash
# Generate single 16-character strong password
./passwordGenerator.sh

# Generate 32-character password
./passwordGenerator.sh -l 32

# Generate 5 different passwords
./passwordGenerator.sh -c 5

# Generate basic alphanumeric password (length 20)
./passwordGenerator.sh -l 20 -t basic

# Generate complex password and copy to clipboard
./passwordGenerator.sh -l 24 -t complex -C

# Generate multiple passwords of different length
./passwordGenerator.sh -l 40 -c 3 -t complex
```

### Password Types
1. **Basic**: `a-zA-Z0-9` (Alphanumeric only)
2. **Strong**: `a-zA-Z0-9!@#$%^&*` (Default - recommended)
3. **Complex**: `a-zA-Z0-9!@#$%^&*()_+-={}[]|:;<>,.?/~` (Maximum characters)

### Strength Indicators
- 🔴 **Weak**: Only 1-2 character types
- 🟡 **Good**: 3 character types
- 🟢 **Strong**: 4 character types
- 💚 **Very Strong**: All types + 16+ characters

### Features
- ✅ Uses cryptographically secure `/dev/urandom`
- ✅ Multiple complexity levels
- ✅ Generate multiple passwords at once
- ✅ Clipboard integration (xclip/xsel)
- ✅ Password strength indicator
- ✅ Customizable length and type
- ✅ Minimum 4 characters

---

## 📝 Notes Manager (CLI)

**File:** `notesManager.sh`

Simple yet powerful command-line note management system with add, view, search, delete, and tagging capabilities.

### Usage
```bash
./notesManager.sh <command> [arguments]
```

### Commands
```
add <text>              Add a new note
add-file <file>         Add notes from a file (one per line)
view, list, show        View all notes
view <number>           View specific note by ID
search <keyword>        Search notes by keyword
delete <number>         Delete a note by ID
clear                   Delete all notes (with confirmation)
export <file>           Export notes to external file
tag <number> <tag>      Add tag to a note
tags                    View all tags and their frequency
help                    Show help message
```

### Examples
```bash
# Add a new note
./notesManager.sh add "Study OS concepts"
./notesManager.sh add "Meeting at 3 PM"

# View all notes
./notesManager.sh view
./notesManager.sh list

# View specific note
./notesManager.sh view 1

# Search for notes
./notesManager.sh search "OS"
./notesManager.sh search "Meeting"

# Add tags to notes
./notesManager.sh tag 1 "important"
./notesManager.sh tag 2 "urgent"

# View all tags
./notesManager.sh tags

# Delete a note
./notesManager.sh delete 3

# Export notes to file
./notesManager.sh export ~/my_notes.txt

# Add notes from a file
./notesManager.sh add-file notes_list.txt

# Clear all notes (with confirmation)
./notesManager.sh clear
```

### Note Storage
Notes are stored in `~/.notes_manager/notes.txt` with the following format:
```
[ID] [TIMESTAMP] [TEXT]
```

Example:
```
[1] [2026-02-23 10:30:45] Study OS concepts [tag:important]
[2] [2026-02-23 11:15:20] Meeting at 3 PM [tag:urgent]
```

### Features
- ✅ Add notes with timestamps
- ✅ View all notes or specific notes
- ✅ Search notes by keyword (case-insensitive)
- ✅ Delete individual notes
- ✅ Clear all notes (with safety confirmation)
- ✅ Tag notes for organization
- ✅ View tags with frequency count
- ✅ Export notes to external files
- ✅ Import notes from files
- ✅ Persistent storage in home directory
- ✅ User-friendly interface with emojis

---

## 📚 Installation & Setup

### Prerequisites
- Bash 4.0 or later
- Standard Unix utilities: `tar`, `find`, `grep`, `tr`, `head`, `cut`, `awk`

### Optional Prerequisites
- For clipboard support in password generator: `xclip` or `xsel`
- For system info tool: `lscpu`, `free`, `df` (usually pre-installed)

### Installation
```bash
# Clone or download all scripts
cd ~/your-project-path

# Make scripts executable
chmod +x smartFileManager.sh backupScript.sh systemInfoTool.sh passwordGenerator.sh notesManager.sh

# Optional: Add scripts directory to PATH
export PATH="$PATH:$(pwd)"

# Verify scripts are working
./smartFileManager.sh -h 2>/dev/null || echo "Smart File Organizer ready"
```

### Creating Symlinks (Optional)
For easier access from anywhere:
```bash
# Linux/macOS
sudo ln -s /path/to/smartFileManager.sh /usr/local/bin/organize
sudo ln -s /path/to/backupScript.sh /usr/local/bin/backup
sudo ln -s /path/to/systemInfoTool.sh /usr/local/bin/sysinfo
sudo ln -s /path/to/passwordGenerator.sh /usr/local/bin/genpass
sudo ln -s /path/to/notesManager.sh /usr/local/bin/notes
```

Then use directly:
```bash
organize ~/Downloads
backup -s ~/Documents
sysinfo
genpass -l 32
notes add "Remember this!"
```

---

## 🚀 Quick Start Guide

### 1. Organize your Downloads
```bash
./smartFileManager.sh ~/Downloads
```

### 2. Set up automatic daily backup
```bash
./backupScript.sh -s ~/Documents -c
```

### 3. Check your system
```bash
./systemInfoTool.sh
```

### 4. Generate a secure password
```bash
./passwordGenerator.sh -l 32 -C
```

### 5. Add a quick note
```bash
./notesManager.sh add "Remember to update password"
./notesManager.sh tag 1 "security"
```

---

## 💡 Tips & Tricks

### Smart File Organizer
- Run regularly on Downloads folder to keep it organized
- Creates only necessary folders, doesn't clutter directory
- Great for photo and video management

### Backup Script
```bash
# Create weekly backups
0 2 * * 0 /path/to/backupScript.sh -s ~/Documents

# Backup multiple directories
for dir in ~/Documents ~/Pictures ~/Projects; do
    ./backupScript.sh -s "$dir" -d ~/backups
done
```

### System Info Tool
- Useful for monitoring system health
- Find bottlenecks in CPU/RAM usage
- Check disk space before large operations

### Password Generator
```bash
# Generate and save password securely
./passwordGenerator.sh -l 32 >> ~/.passwords

# Generate multiple passwords for different services
./passwordGenerator.sh -c 3 -l 24 -t complex

# Generate basic passwords (easier to remember)
./passwordGenerator.sh -l 12 -t basic
```

### Notes Manager
```bash
# Morning routine
./notesManager.sh add "Check emails"
./notesManager.sh add "Daily standup at 10 AM"

# Later view
./notesManager.sh view

# Organize with tags
./notesManager.sh tag 1 "morning"
./notesManager.sh tag 2 "meeting"
```

---

## 📖 Script Details & Concepts

### Shell Scripting Concepts Used

1. **Smart File Organizer**
   - Conditional statements (`if`, case)
   - File operations (`find`, `mv`)
   - Arrays and loops
   - Pattern matching with globs

2. **Backup Script**
   - `tar` and compression (`tar -czf`)
   - Date/time handling
   - Cron job scheduling
   - Command-line argument parsing

3. **System Info Tool**
   - System calls (`/proc` filesystem)
   - Text processing (`awk`, `cut`, `grep`)
   - Color codes for formatting
   - Conditional logic

4. **Password Generator**
   - `/dev/urandom` for randomness
   - `tr` for character translation
   - `head` for data truncation
   - Character set manipulation

5. **Notes Manager**
   - File I/O operations
   - Text manipulation and searching
   - String parsing and formatting
   - Case statement for command routing

---

## 🔧 Troubleshooting

### Permission Denied
```bash
chmod +x scriptname.sh
./scriptname.sh
```

### File Not Found Errors
```bash
# Use absolute paths
./smartFileManager.sh /home/username/Downloads
```

### Cron Jobs Not Working
```bash
# Check cron logs
grep CRON /var/log/syslog

# Verify cron is running
systemctl status cron

# Check crontab entries
crontab -l
```

### Clipboard Not Working
```bash
# Install clipboard tools
sudo apt-get install xclip   # For Debian/Ubuntu
# or
sudo apt-get install xsel
```

---

## 📄 License

These scripts are provided as-is for educational and personal use.

---

## 🤝 Contributing

Feel free to modify and improve these scripts for your needs!

---

## 📞 Support

For issues or questions, refer to the help commands:
```bash
./smartFileManager.sh
./backupScript.sh --help
./systemInfoTool.sh
./passwordGenerator.sh --help
./notesManager.sh help
```

---

**Last Updated**: February 23, 2026
**Version**: 1.0
