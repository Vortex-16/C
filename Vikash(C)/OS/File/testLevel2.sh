#!/bin/bash

project="MyApp"
folder="$project/shell_files"

mkdir -p "$folder"

echo "Creating shell files in $folder..."
for i in {1..30}
do
  touch "$folder/Day_$i.sh"
  echo "Day file $i created"
done

echo "All Shell files created!"
