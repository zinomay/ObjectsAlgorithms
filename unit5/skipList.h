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
            if( head == nullptr ){
                head = new skipListNode<T>();
                for(int i=0; i<=max_lvl; i++){
                    head->next.push_back(nullptr);
                }
                head ->key = key;
                head->level = max_lvl; // To do: add random level
            } else {
                // begin at beginning of list
                skipListNode<T>* current = head;
                skipListNode<T>* new_node = new skipListNode<T>();
                new_node -> level = max_lvl; // To do: generate new level
                new_node -> key = key;
                for(int i=0; i<=max_lvl; i++){
                    new_node->next.push_back(nullptr);
                }
                int current_lvl = new_node->level; 
                // traverse skip list
                while(current_lvl >=0 && current != nullptr){
                    // key is great than current
                    std::cout << "insert" << std::endl;
                    if( current->key < key ){
                        // check next node
                        std::cout << "greater" << std::endl;
                        if( current->next[current_lvl] != nullptr ){
                            std::cout << "next" << std::endl;
                            if(current->next[current_lvl]->key < key){
                                current = current->next[current_lvl];
                            } else{ 
                                if( current_lvl == 0){
                                    for(int i=0; i<= new_node->level; i++){
                                        std::cout << i << std::endl;
                                        new_node->next[i] = current->next[i];
                                        current->next[i] = new_node;
                                    }
                                }
                                current_lvl--; 
                            }
                        } else {
                            std::cout << "else" << std::endl;
                            if(current_lvl == 0){
                                for(int i=0; i<= new_node->level; i++){
                                    std::cout << i << std::endl;
                                    new_node->next[i] = current->next[i];
                                    current->next[i] = new_node;
                                }
                            } 
                            std::cout << current_lvl << std::endl;
                            current_lvl--; // move to next level
                        }
                    } else {
                        std::cout << "less equal" << std::endl;
                        if( current_lvl == 0 ){
                            // create new node
                            // update pointers
                            for(int i=0; i <= new_node->level; i++){
                                std::cout << "else" << i << std::endl;
                                new_node->next[i] = current->next[i]; // connect new node to next node
                                current->next[i] = new_node;
                            }
                        } 
                        current_lvl--; // decrement level
                    }
                }
            }
        };
        void remove(int key){};
        void print(){
            skipListNode<T>* current = head;
            int current_lvl = max_lvl;
            std::cout << max_lvl << " nullptr -> ";
            int i =max_lvl;
            while(i >= 0){
                if( current == nullptr ){
                    std::cout << "nullptr" << std::endl;
                    if( i != 0) {std::cout << i-1 << " nullptr -> ";}
                    current = head;
                    i--;
                } else {
                    std::cout << current->key << " -> ";
                    current = current->next.at(i);
                }
            }
        };
};


#endif