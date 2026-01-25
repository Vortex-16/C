#!/bin/bash

file="important.txt"

if [ ! -f "$file" ]; then
  echo "File not found. Creating $file..."
  echo "This is a protected file." > "$file"
else
  echo "$file already exists. Not touching it."
fi
