#!/bin/bash
# count leaves

count=$(find . -type d \
    -not -path './.git*' | while read -r dir; do
    subdirs=$(find "$dir" -mindepth 1 -maxdepth 1 -type d \
        -not -path "$dir/.git*" | wc -l)
    if [ "$subdirs" -eq 0 ]; then
        echo "$dir"
    fi
done | wc -l)

# use qalc locally for percentage
# -2 for acmsguru (since no code yet) & problem 0 in proj euler
result=$(echo "($count-3)/60686*100" | qalc)

echo "$result"
