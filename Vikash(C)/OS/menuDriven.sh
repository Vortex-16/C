#!/bin/bash

echo "1. Show Date"
echo "2. Show Files"
echo "3. Show Current Directory"
echo "Choose an option:"
read choice

case $choice in
    1) date ;;
    2) ls ;;
    3) pwd ;;
    *) echo "Invalid choice" ;;
esac
