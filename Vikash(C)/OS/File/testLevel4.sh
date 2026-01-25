#!/bin/bash

echo "Enter project name:"
read project
echo "Enter Author name:"
read author

if [ -z "$project" ]; then
  echo "No project name given. Exiting."
  exit 1
fi

echo "Creating project: $project"

mkdir -p "$project/src" "$project/include" "$project/build" "$project/$author"

touch "$project/src/main.c"
touch "$project/include/utils.h"
touch "$project/README.md"
# touch "$project/$author/README.md"

echo "# $project" > "$project/$author/README.md"
echo "Author: $author" >> "$project/$author/README.md"
echo "Date: $(date)" >> "$project/$author/README.md"
echo "Project $project initialized successfully!"