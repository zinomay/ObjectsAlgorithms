/****************************************************************************************
* Unit 3 Programming Assignment 2
* Sorting Comparisons
*
* Description: Driver to compare the following sorting algorithms
*              heap sort, insertion sort, merge sort, and quick sort
* 
* Input:
* Output: 
****************************************************************************************/
#include <iostream>
#include <stdlib.h>
#include <chrono>
#include "Sort.h"

int main(){

    // Generate array of 5000 integers
    int array[5000];
    for(int i=0; i<5000;i++){
        array[i] = rand();
    }
    /*
    for(int i=0;i<5000; i++){
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    */ 
    // heap sort
    vector<int> heap_vector (array, array+sizeof(array)/sizeof(array[0]));
    auto t1 = std::chrono::high_resolution_clock::now();
    heapsort(heap_vector);
    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,std::milli> ms_double = t2-t1;
    std::cout << "heapsort took " << ms_double.count() << " ms" << std::endl;

    // insertion sort
    vector<int> insertion_vector (array, array+sizeof(array)/sizeof(array[0]));
    auto insertion_t1 = std::chrono::high_resolution_clock::now();
    insertionSort(insertion_vector);
    auto insertion_t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,std::milli> insertion_ms_double = insertion_t2-insertion_t1;
    std::cout << "insertion sort took " << ms_double.count() << " ms" << std::endl;
    
    // merge sort
    vector<int> merge_vector (array, array+sizeof(array)/sizeof(array[0]));
    auto merge_t1 = std::chrono::high_resolution_clock::now();
    mergeSort(merge_vector);
    auto merge_t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,std::milli> merge_ms_double = merge_t2-merge_t1;
    std::cout << "merge sort took " << merge_ms_double.count() << " ms" << std::endl;
    
    // quick sort
    vector<int> quick_vector (array, array+sizeof(array)/sizeof(array[0]));
    auto quick_t1 = std::chrono::high_resolution_clock::now();
    quicksort(quick_vector);
    auto quick_t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,std::milli> quick_ms_double = quick_t2-quick_t1;
    std::cout << "quick sort took " << quick_ms_double.count() << " ms" << std::endl;
    
    return 0;
}