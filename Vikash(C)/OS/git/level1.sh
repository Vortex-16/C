#!/bin/bash

echo "Enter commit message:"
read msg

if [ -z "$msg" ]; then
  echo "Commit message required."
  exit 1
fi

git add .

git commit -m "$msg"

git push

echo "All changes committed & pushed!"
