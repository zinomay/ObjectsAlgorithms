/****************************************************************************************
* Unit 3 Programming Assignmentf 1
* Heap Insertion Analysis
* Author: Markus Bernal
* Date: 10/27/2024
* 
* Description: Implement two functions
* 
* Input:
* Output: 
****************************************************************************************/
#include <vector>
#include <iostream>
#include <random>
#include "BinaryHeap.h"


int main(){

  
  // Confirm the heaps are correctly built using both approaches
  // 2, 45, 12, 1, 56, 78, 13, 14, 5, 8, 9, 3, 11, 34
  // create array before creating vector
  int myints[] = {2, 45, 12, 1, 56, 78, 13, 14, 5, 8, 9, 3, 11, 34};
  vector<int> myints_vector (myints, myints+sizeof(myints) / sizeof(myints[0])); 
  
  // print vector of integers
  std::cout << "myints_vector: " ;
  for(std::vector<int>::iterator it = myints_vector.begin(); it != myints_vector.end(); ++it){
    std::cout << ' ' << *it;
  }
  std::cout << std::endl;
  BinaryHeap<int> heap_up = BinaryHeap<int>();
  for(int i=0; i< sizeof(myints)/sizeof(myints[0]); i++){
    heap_up.insert(myints[i]);
  }
  std::cout << "Heap up: ";
  heap_up.print();

  // Create Binary heap
  BinaryHeap<int> heap_down = BinaryHeap<int>(myints_vector);
  std::cout << "Heap down: ";
  heap_down.print();  

  // Sorted Array
  int sorted_array[5000];
  for(int i=1; i<5001; i++){
    sorted_array[i-1] = i; 
  }
  BinaryHeap<int> sorted_heapup = BinaryHeap<int>();
  for(int i=0; i<5000; i++){
    sorted_heapup.insert(sorted_array[i]);
  }
  sorted_heapup.print();
  std::cout << std::endl;
  vector<int> sorted_vector( sorted_array, sorted_array+sizeof(sorted_array)/sizeof(sorted_array[0]) );
  BinaryHeap<int> sorted_heapdown = BinaryHeap<int>(sorted_vector);
  sorted_heapdown.print();
  std::cout << std::endl;


  // Reverse-sorted

  int reverse_sorted_array[5000];
  for(int i=0; i<5000; i++){
    reverse_sorted_array[i] = 5000-i; 
  }

  BinaryHeap<int> reverse_sorted_heapup = BinaryHeap<int>();
  for(int i=0; i<5000; i++){
    reverse_sorted_heapup.insert(reverse_sorted_array[i]);
  }
  reverse_sorted_heapup.print();
  std::cout << std::endl;
  vector<int> reverse_sorted_vector( reverse_sorted_array, reverse_sorted_array+sizeof(reverse_sorted_array)/sizeof(reverse_sorted_array[0]) );
  BinaryHeap<int> reverse_sorted_heapdown = BinaryHeap<int>(reverse_sorted_vector);
  reverse_sorted_heapdown.print();
  std::cout << std::endl;

 // Random

  int rand_array[5000];
  uniform_int_distribution<size_t> urand(1,5000);
  default_random_engine e;
  for(int i=0; i<5000; i++){
    rand_array[i] = urand(e); 
    std::cout << rand_array[i] << " ";
  }
  std::cout << std::endl;
  std::cout << std::endl;

  BinaryHeap<int> random_heapup = BinaryHeap<int>();
  for(int i=0; i<5000; i++){
    random_heapup.insert(rand_array[i]);
  }
  random_heapup.print();
  std::cout << std::endl;
  vector<int> rand_vector( rand_array, rand_array+sizeof(rand_array)/sizeof(rand_array[0]) );
  BinaryHeap<int> rand_heapdown = BinaryHeap<int>(rand_vector);
  rand_heapdown.print();
  std::cout << std::endl;

  return 0;
}