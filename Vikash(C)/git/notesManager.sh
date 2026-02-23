#!/bin/bash

# Notes Manager (CLI)
# Simple note management system with add, view, and delete functionality
# Usage: ./notes.sh add "Study OS"
#        ./notes.sh view
#        ./notes.sh delete 3

# Configuration
NOTES_DIR="$HOME/.notes_manager"
NOTES_FILE="$NOTES_DIR/notes.txt"

# Create notes directory if it doesn't exist
mkdir -p "$NOTES_DIR"

# Initialize notes file if it doesn't exist
if [ ! -f "$NOTES_FILE" ]; then
    echo "# Notes Manager - Created: $(date)" > "$NOTES_FILE"
fi

show_usage() {
    echo "Notes Manager - CLI Note Management"
    echo ""
    echo "Usage: $0 <command> [arguments]"
    echo ""
    echo "Commands:"
    echo "  add <text>              Add a new note"
    echo "  add-file <file>         Add notes from a file"
    echo "  view, list, show        View all notes"
    echo "  view <number>           View specific note"
    echo "  search <keyword>        Search notes by keyword"
    echo "  delete <number>         Delete a note"
    echo "  clear                   Delete all notes"
    echo "  export <file>           Export notes to file"
    echo "  tags                    View all tags"
    echo "  tag <number> <tag>      Add tag to a note"
    echo "  help                    Show this help message"
    echo ""
    echo "Examples:"
    echo "  $0 add \"Study OS concepts\""
    echo "  $0 view"
    echo "  $0 search \"OS\""
    echo "  $0 delete 2"
    echo "  $0 tag 1 important"
}

# Function to add a note
add_note() {
    local note_text="$1"
    local timestamp=$(date +"%Y-%m-%d %H:%M:%S")
    local note_number=$(get_note_count)
    
    if [ -z "$note_text" ]; then
        echo "Error: Note text cannot be empty!"
        return 1
    fi
    
    echo "[$note_number] [$timestamp] $note_text" >> "$NOTES_FILE"
    echo "✓ Note added successfully! (ID: $note_number)"
}

# Function to add notes from file
add_from_file() {
    local input_file="$1"
    
    if [ ! -f "$input_file" ]; then
        echo "Error: File '$input_file' not found!"
        return 1
    fi
    
    local count=0
    while IFS= read -r line; do
        if [ -n "$line" ] && [[ ! "$line" =~ ^# ]]; then
            add_note "$line"
            ((count++))
        fi
    done < "$input_file"
    
    echo "✓ Imported $count notes from file"
}

# Function to get total number of notes
get_note_count() {
    grep -c "^\[" "$NOTES_FILE"
}

# Function to view all notes
view_all_notes() {
    echo "All Notes:"
    echo "════════════════════════════════════════════════════"
    
    if [ $(get_note_count) -eq 0 ]; then
        echo "No notes found. Add your first note with: $0 add \"Your note\""
        return
    fi
    
    local line_num=0
    local note_num=0
    while IFS= read -r line; do
        if [[ $line =~ ^\[ ]]; then
            ((note_num++))
            # Extract note number, timestamp, and text
            if [[ $line =~ \[([0-9]+)\]\ \[([^]]+)\]\ (.*) ]]; then
                local id="${BASH_REMATCH[1]}"
                local timestamp="${BASH_REMATCH[2]}"
                local text="${BASH_REMATCH[3]}"
                
                printf "%s%-3d %s | %s\n" "  " "$id" "$timestamp" "$text"
            fi
        fi
    done < "$NOTES_FILE"
    
    echo "════════════════════════════════════════════════════"
    echo "Total notes: $(get_note_count)"
}

# Function to view specific note
view_note() {
    local note_id="$1"
    
    if ! [[ "$note_id" =~ ^[0-9]+$ ]]; then
        echo "Error: Note ID must be a number"
        return 1
    fi
    
    local found=false
    while IFS= read -r line; do
        if [[ $line =~ \[([0-9]+)\]\ \[([^]]+)\]\ (.*) ]]; then
            if [ "${BASH_REMATCH[1]}" -eq "$note_id" ]; then
                echo "Note #$note_id:"
                echo "Time: ${BASH_REMATCH[2]}"
                echo "Text: ${BASH_REMATCH[3]}"
                found=true
                break
            fi
        fi
    done < "$NOTES_FILE"
    
    if [ "$found" = false ]; then
        echo "Error: Note #$note_id not found!"
        return 1
    fi
}

# Function to search notes
search_notes() {
    local keyword="$1"
    
    if [ -z "$keyword" ]; then
        echo "Error: Search keyword cannot be empty!"
        return 1
    fi
    
    echo "Search Results for: \"$keyword\""
    echo "════════════════════════════════════════════════════"
    
    local found=false
    while IFS= read -r line; do
        if [[ $line =~ \[([0-9]+)\]\ \[([^]]+)\]\ (.*) ]]; then
            local text="${BASH_REMATCH[3]}"
            if [[ "$text" =~ [Ii]$keyword ]]; then
                printf "%s%-3d %s | %s\n" "  " "${BASH_REMATCH[1]}" "${BASH_REMATCH[2]}" "$text"
                found=true
            fi
        fi
    done < "$NOTES_FILE"
    
    if [ "$found" = false ]; then
        echo "No notes found matching: \"$keyword\""
    fi
}

# Function to delete a note
delete_note() {
    local note_id="$1"
    
    if ! [[ "$note_id" =~ ^[0-9]+$ ]]; then
        echo "Error: Note ID must be a number"
        return 1
    fi
    
    local temp_file="$NOTES_DIR/notes.tmp"
    local found=false
    
    while IFS= read -r line; do
        if [[ $line =~ \[([0-9]+)\] ]]; then
            if [ "${BASH_REMATCH[1]}" -eq "$note_id" ]; then
                found=true
                continue
            fi
        fi
        echo "$line" >> "$temp_file"
    done < "$NOTES_FILE"
    
    if [ "$found" = true ]; then
        mv "$temp_file" "$NOTES_FILE"
        echo "✓ Note #$note_id deleted successfully!"
    else
        rm -f "$temp_file"
        echo "Error: Note #$note_id not found!"
        return 1
    fi
}

# Function to clear all notes
clear_all_notes() {
    read -p "Are you sure you want to delete ALL notes? (yes/no): " confirm
    
    if [ "$confirm" = "yes" ]; then
        echo "# Notes Manager - Created: $(date)" > "$NOTES_FILE"
        echo "✓ All notes have been deleted!"
    else
        echo "Operation cancelled."
    fi
}

# Function to export notes
export_notes() {
    local output_file="$1"
    
    if [ -z "$output_file" ]; then
        output_file="$HOME/notes_export_$(date +%Y%m%d_%H%M%S).txt"
    fi
    
    cp "$NOTES_FILE" "$output_file"
    echo "✓ Notes exported to: $output_file"
}

# Function to view all tags
view_tags() {
    echo "Tags:"
    echo "════════════════════════════════════════════════════"
    
    local tags=$(grep -oP '\[tag:\K[^]]+' "$NOTES_FILE" | sort | uniq -c | sort -rn)
    
    if [ -z "$tags" ]; then
        echo "No tags found. Use: $0 tag <number> <tag>"
    else
        echo "$tags"
    fi
}

# Function to add tag to note
tag_note() {
    local note_id="$1"
    local tag="$2"
    
    if [ -z "$note_id" ] || [ -z "$tag" ]; then
        echo "Error: Note ID and tag name required!"
        return 1
    fi
    
    local temp_file="$NOTES_DIR/notes.tmp"
    local found=false
    
    while IFS= read -r line; do
        if [[ $line =~ \[([0-9]+)\] ]] && [ "${BASH_REMATCH[1]}" -eq "$note_id" ]; then
            line="$line [tag:$tag]"
            found=true
        fi
        echo "$line" >> "$temp_file"
    done < "$NOTES_FILE"
    
    if [ "$found" = true ]; then
        mv "$temp_file" "$NOTES_FILE"
        echo "✓ Tag '$tag' added to note #$note_id"
    else
        rm -f "$temp_file"
        echo "Error: Note #$note_id not found!"
        return 1
    fi
}

# Main command handler
case "${1:-help}" in
    add)
        add_note "$2"
        ;;
    add-file)
        add_from_file "$2"
        ;;
    view|list|show)
        if [ -n "$2" ]; then
            view_note "$2"
        else
            view_all_notes
        fi
        ;;
    search)
        search_notes "$2"
        ;;
    delete)
        delete_note "$2"
        ;;
    clear)
        clear_all_notes
        ;;
    export)
        export_notes "$2"
        ;;
    tags)
        view_tags
        ;;
    tag)
        tag_note "$2" "$3"
        ;;
    help|-h|--help)
        show_usage
        ;;
    *)
        echo "Unknown command: $1"
        show_usage
        exit 1
        ;;
esac
