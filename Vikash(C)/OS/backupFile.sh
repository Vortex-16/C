#!/bin/bash

echo "Enter Your File Name To Generate a backup: "
read file

if [ -f "$file" ]
then 
cp "$file" "$file.$(date +%F).bak"
echo "BackUp File Done"
else
echo "Backup Failed 404!!"
fi