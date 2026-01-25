#!/bin/bash

if [ -z "$(git status --porcelain)" ]; then
  echo "No changes to commit."
  exit 0
fi

time=$(date +"%Y-%m-%d %H:%M")

msg="Auto-commit: $time"

git add .
git commit -m "$msg"
git push

echo "Auto commit pushed: $msg"
