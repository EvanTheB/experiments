#!/bin/bash


while [[ "$(shuf $1 | tee group | paste - fam | awk '$1 == $2 {print}' | wc -l)" != 0 ]]; do
    echo fail
done

while read -r e1 e2; do
    echo "your person is $e2" | mail -s "secret santa" "$e1"
done < <(paste $1 group)
