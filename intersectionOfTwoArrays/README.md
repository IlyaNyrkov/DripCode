# Intersection of two arrays
Task: https://leetcode.com/problems/intersection-of-two-arrays/
## Key points
* two ways:
  1) just use two hash_sets
  2) make arrays with 1000 elements (because maximum number in array is 1000) where we set index = value that this value occured in arr2. Then we traverse through second array and check by index in array of 1000 elements and add this element in result.