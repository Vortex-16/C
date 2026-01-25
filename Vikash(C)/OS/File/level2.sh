#!/bin/bash

project="MyApp"
folder="$project/logs"

mkdir -p "$folder"

echo "Creating log files in $folder..."

for i in {1..10}
do
  touch "$folder/log_$i.sh"
  echo "Log file $i created"
done

echo "All log files created!"
