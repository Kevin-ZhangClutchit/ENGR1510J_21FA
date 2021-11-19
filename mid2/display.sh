#!/usr/bin/bash
make clean
make all
echo $((${RANDOM}%1999999)) > test.txt
echo "Linear Search Starts!"
time ./linear_search < test.txt
echo "Linear Search Ends!"
echo "Binary Search Starts!"
time ./binary_search < test.txt
echo "Binary Search Ends!"
echo "Selection Sort Starts!"
time ./selection_sort
echo "Selection Sort Ends!"
