/*******************************************************************************************
* Unit 5: Assignment2 
* Skip Lists 
*
* Author: Markus Bernal
* Date: 11/2/2024
* 
* Description: Class that implements a skip list data structure that stores keys in 
*              ascending order and allows repeats 
*              
* Input: 
* Output:
* 
*******************************************************************************************/
#ifndef SKIPLIST_H
#define SKIPLIST_H
#include<iostream>
#include<vector>
#include<random>

template<class T>
struct skipListNode {
    int key;  // key for the node
    int level;
    T value;
    std::vector<skipListNode*> next; // pointers to the next nodes in different levesls
};


template<class T>
class skipList{
    private:
        skipListNode<T>* head;
        int max_lvl;
        float probability; // probability for a node to be included at a higher level

        float randomize(){
            std::random_device rd;
            std::mt19937 mt(rd());
            std::uniform_real_distribution<float> dist(0.0, 1.0);
            return dist(mt);
        };
    public:
        skipList(){
            // initialize pointers
            head        = nullptr ;
            max_lvl     = 0 ;
            probability = 0.0 ;
        };

        skipList(int max_lvl, float probability): max_lvl(max_lvl), probability(probability) {
            // initialize pointers
            head = nullptr ;
        };

        bool search(int key){ return false; }

        void insert(int key, T value){
            // generate a random level for new node
            // if generated value is less than threshold, add one (1) to level
            // repeat until threshold or max level is reached

            // generate new node
            skipListNode<T>* new_node = new skipListNode<T>();
            bool randomize_lvl = true;
            new_node -> level = 0; // initialize to lvl 0 
            new_node -> key = key;
            new_node -> value = value;

            // generate random level for node
            while( randomize_lvl ){
                if( randomize() < probability ){
                    new_node->level++;
                } else { randomize_lvl = false; }
            }            
            // Initialize new node pointers
            for(int i=0; i<=max_lvl; i++){
                new_node->next.push_back(nullptr);
            }


            if( head == nullptr ){
                head = new_node;
                return;
            } 


            // insert at beginning of list
            if(head->key > key){
                for(int i=0; i<=new_node->level;i++){
                    new_node->next[i] = head;
                }
                head = new_node;
                return;
            }
            skipListNode<T>* current = head;
            int current_lvl = head->level; 
            // traverse skip list
            while(current_lvl >=0 ){
                if( current->next[current_lvl] != nullptr){
                    if( current->next[current_lvl]->key < key ){
                        current = current->next[current_lvl];
                    } else {
                        if( current_lvl == 0 ){
                            for( int i=0; i<=new_node->level; i++ ){
                                new_node->next[i] = current->next[i];
                                current->next[i] = new_node;
                            }
                        }
                        current_lvl--;
                    }
                } else { // insert at end of list
                    for(int i=0; i<=new_node->level; i++){
                        new_node->next[i] = current->next[i];
                        current->next[i] = new_node;
                    }
                    return;
                }
            }
        };
        void remove(int key){};
        void print(){
            skipListNode<T>* current = head;
            int current_lvl = max_lvl;
            std::cout << max_lvl << " inf- -> ";
            int i =max_lvl;
            while(i >= 0){
                if( current == nullptr ){
                    std::cout << "inf+" << std::endl;
                    if( i != 0) {std::cout << i-1 << " inf- -> ";}
                    current = head;
                    i--; // decrement level
                } else {
                    if( current->level >= i ){
                        std::cout << current->key << " -> ";
                    } 
                    current = current->next.at(i);
                }
            }
        };
};


#endif