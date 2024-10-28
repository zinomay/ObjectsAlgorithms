/******************************************************************************************
* Unit 4 Programming Assignment 1
* Collisions
* Author: Markus Bernal
* Date: 10/28/2024
* 
* Description: array based hash table using linear probing, quadratic probing, and 
*              double hashing techniques
* 
* Input: 
* 
* Output: 
*****************************************************************************************/

#include <random>
#include <iostream>
#include "QuadraticProbing.cpp"
#include "linearProbing.h"
#include "doubleHashProbing.h"

class new_hashObj {
    public:
        new_hashObj(unsigned long long int key): key(key){};
        new_hashObj(): key(0){};

        const unsigned long long int & getValue() const {
            return key;
        }

        bool operator==( const new_hashObj & rhs ) const {
            return key == rhs.getValue();
        }
        bool operator!=( const new_hashObj & rhs ) const {
            return key != rhs.getValue();
        }
        
    private:
        unsigned long long int key;
};

template<>
class std::hash<new_hashObj>
{
    public:
        size_t operator()(const new_hashObj & item ){
            static std::hash<unsigned long long int> hf;
            return hf(item.getValue());
        }
};

void randomize( std::vector<unsigned long long int>  & rand_vector ){
    // random see from os
    std::random_device rd;
    std::mt19937_64 eng(rd());
    std::uniform_int_distribution<unsigned long long int> distr;

    for(int i=0; i<1000; i++){
        rand_vector.push_back(distr(eng));
    }
    std::cout << std::endl;
}

int main(){

    // Create vector of random integers of type unsigned long long int  
    std::vector<unsigned long long int> rand_vector;
    randomize(rand_vector);
    
    // All three hash techniques use h1(k) = kmode M as initial hash

    /********************************************************************* 
    * Linear probing 
    **********************************************************************/
    HashTable<new_hashObj> linear_hashTable = HashTable<new_hashObj>(1231);

    for (int i=0; i<1000; i++){
        new_hashObj temp = new_hashObj(rand_vector[i]); 
        linear_hashTable.insert(temp);
    }
    std::cout << std::endl;
    std::cout << "Linear Probing Collisions " << linear_hashTable.getCollisions() << std::endl;

    /********************************************************************* 
    * Quadratic probing ith value (h1(k) +i^2) mod M
    **********************************************************************/
    QuadraticHashTable<new_hashObj> quadratic_hashTable = QuadraticHashTable<new_hashObj>(1231);
    for(int i=0; i<1000; i++) {
        new_hashObj temp = new_hashObj(rand_vector[i]);
        quadratic_hashTable.insert(temp);
    }
    std::cout << std::endl;
    std::cout << "Quadratic Probing Collisions " << quadratic_hashTable.getCollisions() << std::endl;

    // double hashing [h1(k) + i*h2(k) ]mod M  h2(k) = 1+(kmode(m-1)), M size of hash table
    /********************************************************************* 
    * Quadratic probing ith value (h1(k) +i^2) mod M
    **********************************************************************/
    DoubleHashTable<new_hashObj> double_hashTable = DoubleHashTable<new_hashObj>(1231);
    for(int i=0; i<1000; i++) {
        new_hashObj temp = new_hashObj(rand_vector[i]);
        double_hashTable.insert(temp);
    }
    std::cout << std::endl;
    std::cout << "Double Probing Collisions " << double_hashTable.getCollisions() << std::endl;


    return 0;
}
