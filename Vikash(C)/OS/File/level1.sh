#!/bin/bash

project="DemoProject"

echo "Creating project: $project"

mkdir -p "$project/src" "$project/docs" "$project/build"

touch "$project/README.md"

echo "# $project" > "$project/README.md"

echo "Done."
