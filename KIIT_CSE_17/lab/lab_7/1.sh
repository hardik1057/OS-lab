#!/bin/bash
read -p "Enter a number: " num
len=${#num}
for (( i=0; i<len; i++ )); do
  digits[i]=${num:i:1}
done
palindrome=1
for (( i=0; i<len/2; i++ )); do
  if [[ ${digits[i]} != ${digits[len-i-1]} ]]; then
    palindrome=0
    break
  fi
done
if [[ $palindrome -eq 1 ]]; then
  echo "$num is a palindrome"
else
  echo "$num is not a palindrome"
fi