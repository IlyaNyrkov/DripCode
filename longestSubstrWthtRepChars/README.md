# Longest substring without repeating characters
Task: https://leetcode.com/problems/longest-substring-without-repeating-characters/
## Key points
* use array of indexes of last occurance in given string for each ASCII char (127 chars total)
* use start mark, if index of char in ASCII char array is bigger, this char has reoccured
* count index of char in char position array by **string[i] - '_'**
* if we find reoccuring character we move start by one and reassign counter: counter = i - charIndexArr[i]
# Full on explanation