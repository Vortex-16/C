#!/bin/bash

file="ai.exe"

if [ -f "$file" ]
then
    echo "File exists"
else
    echo "File does not exist"
fi
