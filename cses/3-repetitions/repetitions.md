# Repetitions

**Source**: CSES - Introductory Problems  
**Link**: https://cses.fi/problemset/task/1069  
**Author**: Unknown  
**Date**: 2025-11-01

## Problem Statement

Given a string of characters, find the length of the longest consecutive sequence of the same character.

## Explanation

The problem requires finding the maximum length of consecutive identical characters in a string. This is a straightforward iteration problem where we track the current consecutive count and compare it with the maximum seen so far.

## Pseudocode

```
function findLongestRepetition(sequence):
    max_length = 1
    current_length = 1
    
    for i from 0 to length(sequence) - 2:
        if sequence[i] == sequence[i+1]:
            current_length = current_length + 1
            if current_length > max_length:
                max_length = current_length
        else:
            current_length = 1
    
    return max_length
```

## Complexity Analysis

- **Time Complexity**: O(n) - where n is the length of the input string. We iterate through the string once.
- **Space Complexity**: O(1) - we only use a constant amount of extra space for variables.

## Patterns Used

- **Linear Scan**: Simple iteration through the input to find the maximum consecutive sequence
- **State Tracking**: Maintaining current and maximum length states during traversal
