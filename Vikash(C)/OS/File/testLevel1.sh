#!/bin/bash

project="MyAPP"
echo "Setting up project: $project"
mkdir -p "$project/bin" "$project/lib" "$project/include" "$project/tests" "$project/src"
touch "$project/LICENSE"
echo "Project structure created."
echo "Project $project setup complete."
touch "$project/src/main.c"
echo " #include <stdio.h>
void main() {
    printf(\"Hello, World!\\n\");
    printf(\"Welcome to $project!\\n\");
}" > "$project/src/main.c"

echo "Main source file created."
echo "Running the main.c"
gcc "$project/src/main.c" -o "$project/bin/main"
"$project/bin/main"
echo "Execution complete."