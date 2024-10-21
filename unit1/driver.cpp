/************************************
* Markus Bernal
* 10/15/2024
* 
* Unit 1 assignment 1 
* Input:
* Output:
***********************************/
#include <vector>
#include <iostream>

// Given code in assignment 
template <typename Comparable>
int original_binarySearch( const std::vector<Comparable> & a, const Comparable & x){
  int low = 0, high = a.size()-1;
  int compare =0;
  while(low <= high) {
    int mid = (low + high)/2;
    
    if( a[mid] < x){
      low = mid+1;
      compare++;
      compare++;
    } else if( a[mid] > x) {
      high = mid -1;
      compare++;
      compare++;
    }else {
      std::cout << "Compares: " << compare << std::endl; 
      return mid;
    }
  }
  std::cout << "Compares: " << compare << std::endl; 
  return -1;
}

template<typename Comparable>
int new_binarySearch( const std::vector<Comparable> & a, const Comparable & x){
  int low =0, high = a.size()-1;
  int mid; 
  int compare = 0;
  while(low<high){
    mid = (low+high)/2;
    if( a[mid] < x ){
      compare = compare+1;
      low = mid+1;
    } else {
      high = mid;
    }
  }
  std::cout << "Compares: " << compare << std::endl; 
  if(a[mid] == x){
    return mid;
  } else { return -1; }
}

int main() { 
  
  /* what is the count of comparisons of binary_search given an input array of size N for the original version?
     The first algorithm in a worst case scenario, 2N comparisons
     
     what is the count of comparisons of binary_serch given an input array of size N for the updated and improved version?
     The new count of comparisons is N comparisons.
  */
  std::vector<int> test;
  for(int i=0; i<20; i++){
    test.push_back(i);
  }

  int position ;
  position = original_binarySearch<int>(test, 20);
  std::cout << "twenty is at position " << position << std::endl;
  position = new_binarySearch<int>(test, 20);
  std::cout << "twenty is at position " << position << std::endl;


  return 0;
}
