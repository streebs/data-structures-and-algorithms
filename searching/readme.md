# Searching

### Overview 

This program that implements multiple searching algorithms in a sorted array. This program implements 3 searching algorithms runs each algorithm 4 times. 1 search for a value at the beginning, middle, and end of the array. 3 addition searches for values not in the arrays. 12 searches in total. each search is timed and the duration is printed.

### Searching Algorithms and Speed

The main idea of this project is to compare the speed of different sorting algorithms. mainly, to display time complexity of each algorithm. For example, when searching the beginning of the array, sequential search is faster. whereas, when the value is in the middle or the end of the array, sequential search is 10,000 times slower! (based on the output below)

```
sequential search(beginning): 135ns
iterative binary search(beginning): 2166ns
recursive binary search(beginning): 481ns
--------------------------------------------
sequential search(middle): 10935798ns
iterative binary search(middle): 56ns
recursive binary search(middle): 75ns
--------------------------------------------
sequential search(end): 21079295ns
iterative binary search(end): 595ns
recursive binary search(end): 685ns
--------------------------------------------
sequential search(not in array): 21057705ns
iterative binary search(not in array): 853ns
recursive binary search(not in array): 498ns
```

### Run This Program
This program has been compiled on a linux os for x86 architecture. The executable is located in this directory as search.exe you can run it with the following command:
```sh
./searching/search.exe
```