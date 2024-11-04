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

template<class T>
struct skipListNode {
    private:
        int key;  // key for the node
        int level;
        T value;
        skipListNode* next[]; // pointers to the next nodes in different levesls
    public:
        skipListNode(int max_lvl){
            skipListNode* array[max_lvl];
            next = array; 
        };
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

        skipList(int max_level, float probability): max_level(max_level), probability(probability) {
            // initialize pointers
            head = nullptr ;
        };

        bool search(int key){ return false; }
        void insert(int key, T value){
            // generate a random level for new node
            // if generated value is less than threshold, add one (1) to level
            // repeat until threshold or max level is reached
            if( head == nullptr ){
                head = new skipListNode();
                for(int i=0; i<max_lvl; i++){
                    head->next[i] = nullptr;
                }
                head ->key = key;
                head->level = max_lvl; // To do: add random level
            } else {
                // begin at beginning of list
                skipListNode* current = head;
                skipListNode* new_node = new skipListNode();
                new_node -> level = max_lvl // To do: generate new level
                current_lvl = new_node->level; 
                // traverse skip list
                while(current != nullptr ){
                    // key is great than current
                    if( current->key < key ){
                        // check next node
                        if( current->next[current_lvl]->key < key){
                            current = current->next[current_lvl]
                        } else {
                            current_lvl--; // move to next level
                        }
                    } else {
                        if( current_lvl > 0 ){
                            current_lvl--; // decrement level
                        } else {
                            // create new node
                            skipListNode* temp = new skipListNode(); // Insert

                            // update pointers
                            for(int i=0; i < new_node->level; i++){
                                new_node->next[i] = current->next[i]; // connect new node to next node
                                current->next[i] = new_node;
                            }
                            break;
                        }
                        
                    }
                }
            }
        };
        void remove(int key){};
        void print(){
            skipListNode* current = head;
            current_lvl = max_lvl;
            for(int i=max_lvl; i>=0; i--){
                if( current == nullptr ){
                    std::cout << "nullptr" << std::endl;
                    current = head;
                    continue;
                } else {
                    current = current->next[current_lvl];
                    std::cout << current->key << "->";
                }
            }
        };
};


#endif