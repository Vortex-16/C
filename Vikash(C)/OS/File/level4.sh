#!/bin/bash

echo "Enter project name:"
read project

if [ -z "$project" ]; then
  echo "No project name given. Exiting."
  exit 1
fi

echo "Creating project: $project"

mkdir -p "$project/src" "$project/include" "$project/build"

touch "$project/src/main.c"
touch "$project/include/utils.h"
touch "$project/README.md"

echo "# $project" > "$project/README.md"
echo "Project $project initialized successfully!"
