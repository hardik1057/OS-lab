#!/bin/bash
echo "Enter the elements- "
read -a array
len=${#array[@]}
for ((i=len-1; i>=0; i--))
do
  echo "${array[i]}"
done