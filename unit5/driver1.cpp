/*******************************************************************************************
* Unit 5: Assignment1 
* Inverted File
*
* Author: Markus Bernal
* Date: 11/2/2024
* 
* Description: Create an inverted file (inverted index) data structure for
*              maintaining the index of a book
* Input: Text file of any book
* Output:
* 
*******************************************************************************************/
#include<iostream>
#include "invertedFile.h"

using namespace std;

int main(){


  // I is a map where keys are distinct words in B, and values will be a set of associated page numbers
  // i.e. a list of integers
  Inverted inverted_index = Inverted();

  inverted_index.print();

  inverted_index.insert("Big",5);
  inverted_index.insert("Big",8);

  inverted_index.print();

  // Assume each page has 250 words

  return 0;
}
