#!/bin/bash

echo "Enter a number:"
read n

temp=$n
rev=0

while [ $n -gt 0 ]
do
  digit=$((n % 10))
  rev=$((rev * 10 + digit))
  n=$((n / 10))
done

if [ $rev -eq $temp ]
then
  echo "Palindrome number"
else
  echo "Not a palindrome number"
fi
