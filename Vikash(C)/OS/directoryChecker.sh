#!/bin/bash

echo "Enter Directory Name: "
read dir

if [ -d "$dir" ]
then 
echo "Directory exixt"
else
echo "Directory not found in Current path"
fi