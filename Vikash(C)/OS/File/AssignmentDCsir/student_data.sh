#!/bin/bash

# File to store student data
DATAFILE="datafile.txt"
TEMPFILE="tempfile.txt"

# Function to read existing data
read_existing_data() {
    if [[ -f "$DATAFILE" ]]; then
        # Count existing students (skip first 2 header lines)
        count=$(tail -n +3 "$DATAFILE" | wc -l)
        echo "$count"
    else
        echo "0"
    fi
}

# Function to find student by roll number
find_student() {
    local roll=$1
    if [[ -f "$DATAFILE" ]]; then
        # Skip first 2 header lines and search for roll number
        grep -n "^$roll " "$DATAFILE" | tail -n +3 | cut -d: -f1
    fi
}

# Function to get student details by line number
get_student_details() {
    local line_num=$1
    sed -n "${line_num}p" "$DATAFILE"
}

# Function to extract field from student record
extract_field() {
    local record="$1"
    local field=$2
    
    case $field in
        1) echo "$record" | awk -F'|' '{print $1}' | xargs ;;
        2) echo "$record" | awk -F'|' '{print $2}' | xargs ;;
        3) echo "$record" | awk -F'|' '{print $3}' | xargs ;;
        4) echo "$record" | awk -F'|' '{print $4}' | xargs ;;
    esac
}

# Function to update student record
update_record() {
    local line_num=$1
    local new_record="$2"
    
    # Create temp file with updated record
    if [[ $line_num -eq 1 ]]; then
        echo "$new_record" > "$TEMPFILE"
        tail -n +2 "$DATAFILE" >> "$TEMPFILE"
    else
        head -n $((line_num - 1)) "$DATAFILE" > "$TEMPFILE"
        echo "$new_record" >> "$TEMPFILE"
        tail -n +$((line_num + 1)) "$DATAFILE" >> "$TEMPFILE"
    fi
    
    mv "$TEMPFILE" "$DATAFILE"
}

# Function to add new student
add_student() {
    local roll=$1
    local name="$2"
    local dept="$3"
    local cgpa=$4
    
    # Format record
    printf "%-4s | %-19s | %-18s | %.2f\n" "$roll" "$name" "$dept" "$cgpa" >> "$TEMPFILE"
}

# Initialize temp file for new data
> "$TEMPFILE"

# Check existing data
existing_count=$(read_existing_data)

if [[ $existing_count -gt 0 ]]; then
    echo "Found $existing_count existing student(s) in file."
    echo
    # Copy existing data to temp file (skip headers)
    tail -n +3 "$DATAFILE" >> "$TEMPFILE"
fi

# Get number of students to add
echo -n "Enter number of students to add: "
read n

# Input new students
for ((i=1; i<=n; i++)); do
    echo
    echo "Enter details of student $i"
    
    echo -n "Roll: "
    read roll
    
    # Check if student exists
    if [[ $existing_count -gt 0 ]]; then
        existing_line=$(tail -n +3 "$DATAFILE" | grep -n "^$roll " | cut -d: -f1)
        
        if [[ -n "$existing_line" ]]; then
            # Student exists
            echo
            echo "Student with Roll $roll already exists!"
            
            # Get current details
            current_record=$(tail -n +3 "$DATAFILE" | sed -n "${existing_line}p")
            current_name=$(echo "$current_record" | awk -F'|' '{print $2}' | xargs)
            current_dept=$(echo "$current_record" | awk -F'|' '{print $3}' | xargs)
            current_cgpa=$(echo "$current_record" | awk -F'|' '{print $4}' | xargs)
            
            echo "Current Details:"
            echo "Name: $current_name"
            echo "Department: $current_dept"
            echo "CGPA: $current_cgpa"
            
            echo
            echo "Do you want to:"
            echo "1. Modify marks (CGPA) only"
            echo "2. Modify entire record"
            echo "3. Skip this entry"
            echo -n "Enter choice: "
            read choice
            
            case $choice in
                1)
                    echo -n "Enter new CGPA: "
                    read cgpa
                    # Update only CGPA in temp file
                    sed -i "${existing_line}s/|[^|]*$/| $cgpa/" "$TEMPFILE"
                    echo "CGPA updated!"
                    ;;
                2)
                    echo -n "Name: "
                    read name
                    echo -n "Department: "
                    read dept
                    echo -n "CGPA: "
                    read cgpa
                    # Update entire record in temp file
                    new_record=$(printf "%-4s | %-19s | %-18s | %.2f" "$roll" "$name" "$dept" "$cgpa")
                    sed -i "${existing_line}s/.*/$new_record/" "$TEMPFILE"
                    echo "Record updated!"
                    ;;
                3)
                    echo "Skipped."
                    ;;
                *)
                    echo "Invalid choice. Skipped."
                    ;;
            esac
            continue
        fi
    fi
    
    # Add new student
    echo -n "Name: "
    read name
    echo -n "Department: "
    read dept
    echo -n "CGPA: "
    read cgpa
    
    printf "%-4s | %-19s | %-18s | %.2f\n" "$roll" "$name" "$dept" "$cgpa" >> "$TEMPFILE"
done

# Sort by roll number
{
    echo "Roll | Name                | Department          | CGPA"
    echo "------------------------------------------------------------"
    sort -n "$TEMPFILE"
} > "$DATAFILE"

# Clean up
rm -f "$TEMPFILE"

# Count total students
total=$(tail -n +3 "$DATAFILE" | wc -l)
echo
echo "Total $total student(s) saved in $DATAFILE (Pipe Format)"
