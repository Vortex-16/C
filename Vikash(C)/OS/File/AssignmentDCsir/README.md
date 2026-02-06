# Student Data Management System

A comprehensive student record management system implemented in both **C** and **Shell Script** that handles data persistence, duplicate detection, and dynamic updates.

## 📋 Overview

This project manages student records (Roll Number, Name, Department, CGPA) with intelligent duplicate handling and data persistence across multiple program executions.

---

## 🚀 Features

### Core Functionality
- ✅ **Data Persistence**: Preserves existing data across multiple runs
- ✅ **Duplicate Detection**: Identifies existing students by roll number
- ✅ **Smart Updates**: Options to modify CGPA only or entire record
- ✅ **Auto-Sorting**: Sorts all records by roll number in ascending order
- ✅ **Formatted Output**: Clean pipe-delimited table format in file

### User Options on Duplicate
When a student with the same roll number exists:
1. **Modify Marks Only**: Update CGPA while keeping other details
2. **Modify Entire Record**: Update all fields (name, dept, CGPA)
3. **Skip Entry**: Leave existing record unchanged

---

## 📁 Files

| File | Description |
|------|-------------|
| `student_data.c` | C implementation with dynamic memory allocation |
| `student_data.sh` | Shell script implementation using text processing |
| `datafile.txt` | Output file storing all student records |
| `README.md` | This documentation file |

---

## 🔧 Compilation & Execution

### C Version

**Compile:**
```bash
gcc student_data.c -o student_data
```

**Run:**
```bash
./student_data
```

### Shell Script Version

**Make executable (first time only):**
```bash
chmod +x student_data.sh
```

**Run:**
```bash
./student_data.sh
```

---

## 📖 How It Works

### Workflow Diagram

```
START
  ├─→ Read existing data from datafile.txt (if exists)
  ├─→ Display count of existing students
  ├─→ Ask for number of new students to add
  │
  └─→ FOR each new student:
       ├─→ Input Roll Number
       ├─→ Check if Roll Number exists
       │
       ├─→ IF EXISTS:
       │    ├─→ Display current details
       │    ├─→ Ask user choice:
       │    │    ├─→ [1] Update CGPA only
       │    │    ├─→ [2] Update entire record
       │    │    └─→ [3] Skip this entry
       │    └─→ Apply selected action
       │
       └─→ IF NEW:
            └─→ Input Name, Department, CGPA
            └─→ Add to student list
  │
  ├─→ Sort all students by Roll Number (Ascending)
  ├─→ Write header to datafile.txt
  ├─→ Write all sorted records to datafile.txt
  └─→ Display success message
END
```

---

## 💻 Code Structure - C Version

### Data Structure
```c
struct Student {
    int roll;        // Roll number (unique identifier)
    char name[50];   // Student name
    char dept[50];   // Department name
    float cgpa;      // CGPA (marks)
};
```

### Key Functions

#### 1. `readExistingData(struct Student **students)`
**Purpose**: Reads existing student records from file into memory

**Process**:
- Opens `datafile.txt` in read mode
- Returns 0 if file doesn't exist (first run)
- Allocates dynamic memory for 100 students
- Skips 2 header lines
- Parses pipe-delimited format: `Roll | Name | Dept | CGPA`
- Trims trailing spaces from strings
- Returns count of students read

**Memory**: Uses `malloc()` for dynamic allocation

---

#### 2. `findStudent(struct Student *students, int count, int roll)`
**Purpose**: Searches for a student by roll number

**Process**:
- Linear search through student array
- Compares each student's roll number with target
- Returns index if found, -1 if not found

**Time Complexity**: O(n) where n = number of students

---

#### 3. `main()`
**Purpose**: Main program logic and workflow

**Step-by-Step Execution**:

**Step 1: Load Existing Data**
```c
int existingCount = readExistingData(&allStudents);
```
- Reads all existing students from file
- Stores count and pointer to student array

**Step 2: Memory Allocation**
```c
allStudents = realloc(allStudents, (existingCount + n) * sizeof(struct Student));
```
- Expands memory to accommodate new students
- Preserves existing data using `realloc()`

**Step 3: Input Loop with Duplicate Check**
```c
int index = findStudent(allStudents, total, roll);
if (index != -1) {
    // Duplicate found - show options
    // 1. Modify CGPA: allStudents[index].cgpa = new_value
    // 2. Modify All: Update all fields at existing index
    // 3. Skip: Do nothing
} else {
    // New student - add to end
    allStudents[total++] = newStudent;
}
```

**Step 4: Bubble Sort by Roll**
```c
for (i = 0; i < total - 1; i++) {
    for (j = i + 1; j < total; j++) {
        if (allStudents[i].roll > allStudents[j].roll) {
            // Swap students
            temp = allStudents[i];
            allStudents[i] = allStudents[j];
            allStudents[j] = temp;
        }
    }
}
```
- Simple bubble sort algorithm
- Compares roll numbers
- Swaps entire struct when needed

**Step 5: File Writing**
```c
FILE *fp = fopen("datafile.txt", "w");  // Overwrite mode
fprintf(fp, "Roll | Name | Department | CGPA\n");
fprintf(fp, "--------------------\n");
for (i = 0; i < total; i++) {
    fprintf(fp, "%-4d | %-19s | %-18s | %.2f\n", ...);
}
```
- Opens in write mode (rewrites entire file)
- Formats with fixed column widths
- `%-4d`: Left-aligned, 4-character roll number
- `%-19s`: Left-aligned, 19-character name
- `%.2f`: Float with 2 decimal places

**Step 6: Cleanup**
```c
free(allStudents);  // Free dynamically allocated memory
```

---

## 🐚 Code Structure - Shell Script Version

### Key Components

#### 1. File Variables
```bash
DATAFILE="datafile.txt"    # Main storage file
TEMPFILE="tempfile.txt"    # Temporary working file
```

#### 2. `read_existing_data()`
**Purpose**: Count existing students in file

**Implementation**:
```bash
tail -n +3 "$DATAFILE" | wc -l
```
- `tail -n +3`: Skip first 2 header lines
- `wc -l`: Count remaining lines

---

#### 3. `find_student()`
**Purpose**: Search for student by roll number

**Implementation**:
```bash
grep -n "^$roll " "$DATAFILE" | tail -n +3 | cut -d: -f1
```
- `grep -n`: Search with line numbers
- `^$roll `: Pattern matches roll at start of line
- `cut -d: -f1`: Extract line number

---

#### 4. Main Logic Flow

**Step 1: Load Data to Temp File**
```bash
tail -n +3 "$DATAFILE" >> "$TEMPFILE"
```
- Copies existing records (without headers) to temp file

**Step 2: Duplicate Detection**
```bash
existing_line=$(tail -n +3 "$DATAFILE" | grep -n "^$roll " | cut -d: -f1)
```
- Searches for roll number in existing data

**Step 3: Record Update with `sed`**

**Update CGPA only:**
```bash
sed -i "${existing_line}s/|[^|]*$/| $cgpa/" "$TEMPFILE"
```
- `s/|[^|]*$/`: Matches last pipe and content after it
- Replaces with new CGPA value

**Update entire record:**
```bash
new_record=$(printf "%-4s | %-19s | %-18s | %.2f" "$roll" "$name" "$dept" "$cgpa")
sed -i "${existing_line}s/.*/$new_record/" "$TEMPFILE"
```
- Replaces entire line at specified line number

**Step 4: Sorting**
```bash
sort -n "$TEMPFILE" > "$DATAFILE"
```
- `sort -n`: Numeric sort (by roll number)
- Redirects to final data file

---

## 🎯 Usage Examples

### Example 1: First Run (No Existing Data)

**Input:**
```
Enter number of students to add: 2

Enter details of student 1
Roll: 101
Name: Alice Johnson
Department: Computer Science
CGPA: 8.5

Enter details of student 2
Roll: 102
Name: Bob Smith
Department: Mechanical
CGPA: 7.8
```

**Output File (`datafile.txt`):**
```
Roll | Name                | Department          | CGPA
------------------------------------------------------------
101  | Alice Johnson       | Computer Science    | 8.50
102  | Bob Smith           | Mechanical          | 7.80
```

---

### Example 2: Second Run (Adding Student with Existing Roll)

**Input:**
```
Found 2 existing student(s) in file.

Enter number of students to add: 2

Enter details of student 1
Roll: 101

Student with Roll 101 already exists!
Current Details:
Name: Alice Johnson
Department: Computer Science
CGPA: 8.50

Do you want to:
1. Modify marks (CGPA) only
2. Modify entire record
3. Skip this entry
Enter choice: 1
Enter new CGPA: 9.2
CGPA updated!

Enter details of student 2
Roll: 103
Name: Charlie Brown
Department: Electrical
CGPA: 8.1
```

**Output File (`datafile.txt`):**
```
Roll | Name                | Department          | CGPA
------------------------------------------------------------
101  | Alice Johnson       | Computer Science    | 9.20
102  | Bob Smith           | Mechanical          | 7.80
103  | Charlie Brown       | Electrical          | 8.10
```

**Note**: Alice's CGPA updated from 8.50 to 9.20, Charlie added as new student.

---

### Example 3: Modifying Entire Record

**Input:**
```
Found 3 existing student(s) in file.

Enter number of students to add: 1

Enter details of student 1
Roll: 102

Student with Roll 102 already exists!
Current Details:
Name: Bob Smith
Department: Mechanical
CGPA: 7.80

Do you want to:
1. Modify marks (CGPA) only
2. Modify entire record
3. Skip this entry
Enter choice: 2
Name: Robert Smith
Department: Civil Engineering
CGPA: 8.5
Record updated!
```

**Output File (`datafile.txt`):**
```
Roll | Name                | Department          | CGPA
------------------------------------------------------------
101  | Alice Johnson       | Computer Science    | 9.20
102  | Robert Smith        | Civil Engineering   | 8.50
103  | Charlie Brown       | Electrical          | 8.10
```

**Note**: Bob's complete record updated to Robert with new department and CGPA.

---

## 🔍 Technical Details

### Memory Management (C Version)

| Function | Purpose | Note |
|----------|---------|------|
| `malloc()` | Initial allocation | Allocates space for 100 students initially |
| `realloc()` | Expand memory | Adds space for new students while preserving old data |
| `free()` | Cleanup | Prevents memory leaks by freeing allocated memory |

### File Operations

**C Version:**
- Uses `FILE *` pointer and `fprintf()`
- Format specifiers: `%-4d`, `%-19s`, `%-18s`, `%.2f`
- Mode: `"r"` for reading, `"w"` for writing

**Shell Version:**
- Uses text processing tools: `awk`, `sed`, `grep`, `sort`
- Temporary file for safe operations
- `printf` for formatting

### Time Complexity Analysis

| Operation | C Version | Shell Version |
|-----------|-----------|---------------|
| Read existing data | O(n) | O(n) |
| Find student | O(n) | O(n) |
| Sort students | O(n²) bubble sort | O(n log n) built-in sort |
| Write to file | O(n) | O(n) |

**Overall**: O(n²) for C version, O(n log n) for Shell version per run

---

## 🛡️ Error Handling

### C Version
- Checks if file opening fails: `if (fp == NULL)`
- Memory allocation check (implicit)
- Input validation via `scanf()` return value

### Shell Version
- File existence check: `[[ -f "$DATAFILE" ]]`
- Invalid choice handling in case statement
- Automatic cleanup of temp files

---

## 🎨 Output Format

### Pipe-Delimited Table
```
Column 1: Roll Number (4 characters, left-aligned)
|
Column 2: Name (19 characters, left-aligned)
|
Column 3: Department (18 characters, left-aligned)
|
Column 4: CGPA (Float with 2 decimal places)
```

**Example:**
```
Roll | Name                | Department          | CGPA
------------------------------------------------------------
101  | Alice Johnson       | Computer Science    | 8.50
```

---

## 🔄 Data Flow

```
┌─────────────────┐
│  datafile.txt   │
│  (Persistent)   │
└────────┬────────┘
         │
         ├──── Read ────┐
         │              │
         │         ┌────▼─────┐
         │         │  Memory  │
         │         │  Array   │
         │         └────┬─────┘
         │              │
         │         Add/Modify
         │         Students
         │              │
         │         ┌────▼─────┐
         │         │  Sort    │
         │         │  by Roll │
         │         └────┬─────┘
         │              │
         └──── Write ───┘
```

---

## 📊 Advantages & Use Cases

### Advantages
1. **No Data Loss**: Accumulates data across runs
2. **Duplicate Prevention**: Avoids accidental duplicate entries
3. **Flexible Updates**: Granular control over what to modify
4. **Always Sorted**: Maintains order automatically
5. **Two Implementations**: Choose C (performance) or Shell (portability)

### Use Cases
- Academic record management
- Student information systems
- Grade book applications
- Any system requiring persistent record storage with updates

---

## 🧪 Testing Scenarios

### Test Case 1: Empty File (First Run)
- **Input**: 3 students with rolls 103, 101, 102
- **Expected**: File created with students sorted as 101, 102, 103

### Test Case 2: Duplicate Roll - Update CGPA
- **Input**: Roll 101 exists, user chooses option 1, new CGPA 9.5
- **Expected**: Only CGPA changes, name and dept remain same

### Test Case 3: Duplicate Roll - Update All
- **Input**: Roll 102 exists, user chooses option 2, new name/dept/CGPA
- **Expected**: All fields updated for roll 102

### Test Case 4: Duplicate Roll - Skip
- **Input**: Roll 103 exists, user chooses option 3
- **Expected**: No changes to roll 103 record

### Test Case 5: Multiple Runs
- **Run 1**: Add 2 students
- **Run 2**: Add 3 more students
- **Expected**: File contains all 5 students sorted by roll

---

## 🐛 Common Issues & Solutions

### Issue 1: File Not Found on First Run
**Solution**: This is normal. Program creates the file automatically.

### Issue 2: Data Gets Overwritten
**Cause**: Using old version that opens file with "w" mode without reading first
**Solution**: Ensure you're using the updated version that reads existing data

### Issue 3: Duplicate Students Despite Check
**Cause**: Roll numbers entered with extra spaces
**Solution**: Code trims spaces during read operation

### Issue 4: Shell Script Not Running
**Cause**: No execute permission
**Solution**: Run `chmod +x student_data.sh`

---

## 📝 Future Enhancements

- [ ] Search functionality by name or department
- [ ] Delete student records
- [ ] Export to CSV format
- [ ] GUI interface
- [ ] Database backend (MySQL/SQLite)
- [ ] Multi-user support with authentication
- [ ] Validation for CGPA range (0.0-10.0)
- [ ] Binary search after sorting (O(log n) lookup)

---

## 👨‍💻 Author

Vikash

## 📄 License

This project is open-source and available for educational purposes.

---

## 📞 Support

For issues or questions, please refer to the code comments or contact the development team.

---

**Last Updated**: February 6, 2026
