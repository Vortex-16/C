#!/bin/bash

echo "Enter directory name:"
read dir

if [ -d "$dir" ]
then
    count=$(ls "$dir" | wc -l)
    echo "Total files in $dir: $count"
else
    echo "Directory not found"
fi
