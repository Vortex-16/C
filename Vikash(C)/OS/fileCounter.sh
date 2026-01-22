#!/bin/bash

echo "Enter directory name:"
read dir

if [ -d "$dir" ]
then
    echo "Files in the directory $dir are:"
    ls "$dir"
else
    echo "Directory does not exist!"
fi
