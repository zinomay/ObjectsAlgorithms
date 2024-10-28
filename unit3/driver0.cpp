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
#include "BinaryHeap.h"


int main(){

  
  // Confirm the heaps are correctly built using both approaches
  // 2, 45, 12, 1, 56, 78, 13, 14, 5, 8, 9, 3, 11, 34
  // create array before creating vector
  int myints[] = {2, 45, 12, 1, 56, 78, 13, 14, 5, 8, 9, 3, 11, 34};
  vector<int> myints_vector (myints, myints+sizeof(myints) / sizeof(int)); 
  
  // print vector of integers
  std::cout << "myints_vector: " ;
  for(std::vector<int>::iterator it = myints_vector.begin(); it != myints_vector.end(); ++it){
    std::cout << ' ' << *it;
  }
  std::cout << std::endl;

  // Sorted
  // Reverse-sorted
  // Random
  return 0;
}