#!/bin/bash

# Smart File Organizer
# Auto-sorts files into folders (PDFs, Images, Videos, Code, etc.)

if [ $# -eq 0 ]; then
    echo "Usage: $0 <path-to-organize>"
    echo "Example: $0 ~/Downloads"
    exit 1
fi

TARGET_DIR="$1"

# Check if directory exists
if [ ! -d "$TARGET_DIR" ]; then
    echo "Error: Directory '$TARGET_DIR' does not exist!"
    exit 1
fi

echo "Organizing files in: $TARGET_DIR"
echo "================================================"

# Define file categories
declare -A CATEGORIES=(
    [PDF]="*.pdf"
    [Images]="*.{jpg,jpeg,png,gif,bmp,svg,webp}"
    [Videos]="*.{mp4,mkv,avi,mov,flv,wmv}"
    [Audio]="*.{mp3,wav,flac,aac,m4a,wma}"
    [Documents]="*.{doc,docx,xls,xlsx,ppt,pptx,txt,odt}"
    [Archives]="*.{zip,rar,7z,tar,gz,tar.gz}"
    [Code]="*.{c,cpp,h,hpp,js,py,java,rb,go,rs,sh,php}"
    [Executables]="*.{exe,bin,sh,bat}"
)

# Create folders and move files
for category in "${!CATEGORIES[@]}"; do
    pattern="${CATEGORIES[$category]}"
    
    # Create category folder if it doesn't exist
    mkdir -p "$TARGET_DIR/$category"
    
    # Find and move files matching the pattern
    cd "$TARGET_DIR"
    find . -maxdepth 1 -type f \( -iname "${pattern}" \) -exec mv {} "$category/" \; 2>/dev/null
    
    # Count files in category
    file_count=$(find "$category" -maxdepth 1 -type f 2>/dev/null | wc -l)
    if [ $file_count -gt 0 ]; then
        echo "✓ $category: $file_count file(s) organized"
    fi
done

# Move uncategorized files to "Others" folder
mkdir -p "$TARGET_DIR/Others"
cd "$TARGET_DIR"
find . -maxdepth 1 -type f -not -path "." -exec mv {} Others/ \; 2>/dev/null

other_count=$(find Others -maxdepth 1 -type f 2>/dev/null | wc -l)
if [ $other_count -gt 0 ]; then
    echo "✓ Others: $other_count uncategorized file(s)"
fi

echo "================================================"
echo "File organization completed!"
