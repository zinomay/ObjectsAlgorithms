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
#include<fstream>

class Inverted {

  private:
    std::map< std::string, std::set<int> > invertedMap; 

  public:

    Inverted(){ std::cout << "New Inverted Index" << std::endl; }
    void insert( std::string word, int page ){
      // function: inserts word and page
      // input:
      // output:
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
      // function: Searches for key in map and returns set
      // input:
      // output:
      std::set<int> temp;
      return temp;
    }; 

    bool exists( std::string word ){
      // function: Check if key exists in map
      // input:
      // output:
      if( invertedMap.count( word )){
        return true;
      }
      return false;
    }

    void print(){
      // function: Searches for key in map and returns set
      // input:
      // output:
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

    void create_index( std::ofstream &oFile ){
      // function: Searches for key in map and returns set
      // input:
      // output:
      if( invertedMap.empty() ){
        std::cout << "Index is empty" << std::endl;
        return;
      }
      for( const auto& word : invertedMap ) {
        oFile << word.first << " ";
        std::set<int>::iterator last = word.second.end();
        for( auto it = word.second.begin(); it != word.second.end()--; ++it){
          oFile << *it << " ";
        }
        oFile << "\n";
        
      }
    }
};

