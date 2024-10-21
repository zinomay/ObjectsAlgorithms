/*
* Author: Markus Bernal
* Date: 10/21/2024
* Unit 1 assignment 2
* Description:
* Part A. 1) Binary max heap using rank as priority
*         2) Hash Table of size 11 with linear probing
*         3) Binary search tree for color
* Part B. 1) Read input file PatriotAct. HashTable will use quadratic probing and have size 1723
*         2) Compute the run time to find the most freq word for each data structure
*         3) computer runtime to find the word terrorists, the, and freedom
*/

#include "BinaryHeap.h"
#include "colorObj.cpp"

int main(){

 // Part A Create colors used for each data structure
  colorObj orange = colorObj("orange",  4); // 4
  colorObj blue   = colorObj("blue"  ,  7); // 7
  colorObj pink   = colorObj("pink"  ,  5); // 5
  colorObj black  = colorObj("black" ,  6); // 6
  colorObj green  = colorObj("green" ,  8); // 8
  colorObj yellow = colorObj("yellow",  1); // 1
  colorObj brown  = colorObj("brown" ,  2); // 2
  colorObj red    = colorObj("red"   ,  3); // 3
  colorObj purple = colorObj("purple", 10); // 10
  colorObj white  = colorObj("white" ,  9); // 9

  // 1) binary max heap using rank as priority
  BinaryHeap<colorObj> heap = BinaryHeap<colorObj>(100);
  heap.insert(orange);  
  heap.insert(blue  );  
  heap.insert(pink  );  
  heap.insert(black );  
  heap.insert(green );  
  heap.insert(yellow);  
  heap.insert(brown );  
  heap.insert(red   );  
  heap.insert(purple);  
  heap.insert(white );  
  
  colorObj temp = heap.findMin();
  temp.print();
  return 0;
}
