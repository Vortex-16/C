#!/bin/bash

if [ -z "$(git status --porcelain)" ]; then
  echo "No changes to commit."
  exit 0
fi

echo "Enter commit message:"
read msg

if [ -z "$msg" ]; then
  echo "Commit message required."
  exit 1
fi

git add .

git commit -m "$msg"
git push

echo "Smart commit done!"
