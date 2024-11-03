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

#include<map>
#include<set>
#include<string>
#include<iostream>

class Inverted {

  private:
    std::map< std::string, std::set<int> > invertedMap; 

  public:

    Inverted(){ std::cout << "New Inverted Index" << std::endl; }
    void insert( std::string word, int page ){
      if( invertedMap.count( word )){ // word exists
        std::set<int>* temp = &invertedMap.at( word );
        temp->insert( page );
      } else { // New word
        std::set<int> temp ; 
        temp.insert(page);
        invertedMap.insert( {word, temp});
      }
    }

    std::set<int> lookup( std::string word ){
      std::set<int> temp;
      return temp;
    }; 
    bool exists(){return false;}

    void print(){
      if( invertedMap.empty() ) {
        std::cout << "Inverted Index" << std::endl;
      } else{
        for (const auto& word : invertedMap){
          std::cout << word.first << " " ;
          for( const auto& number : word.second){
            std::cout << number <<  " " ; 
          }
          std::cout << std::endl;
        }
      }

    }
};

