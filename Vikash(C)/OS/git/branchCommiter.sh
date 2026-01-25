#!/bin/bash

branch=$(git branch --show-current)

if [ -z "$branch" ]; then
  echo "Not on a branch."
  exit 1
fi

if [ -z "$(git status --porcelain)" ]; then
  echo "No changes to commit."
  exit 0
fi

msg="Auto-commit on $branch at $(date +"%Y-%m-%d %H:%M")"

git add .
git commit -m "$msg"
git push origin "$branch"

echo "Pushed to $branch"
