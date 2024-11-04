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
* Output: text file with extension .rtf
* 
*******************************************************************************************/
#include<iostream>
#include<fstream>
#include<string>
#include "inverted.h"

using namespace std;

int main(){


  // I is a map where keys are distinct words in B, and values will be a set of associated page numbers
  // i.e. a list of integers
  Inverted inverted_index = Inverted();
  inverted_index.print();

  // Assume each page has 250 words
  ifstream inFile ("Orwell 1984.txt");
  string word;
  int count = 1;
  int page = 0;
  while( inFile >> word){
    inverted_index.insert(word, page);
    count++;
    if (count == 250){
      count = 0;
      page++;
    }
  }
  // Test index
  ofstream outFile ("Orwell 1984 Index.rtf"); 
  inverted_index.create_index(outFile);

  // Test empty index 
  ofstream oFile ("Empty index.txt");
  Inverted empty_index = Inverted();
  empty_index.create_index(oFile);

  return 0;
}
