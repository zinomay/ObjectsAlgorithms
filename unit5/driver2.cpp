/*******************************************************************************************
* Unit 5: Assignment2 
* Skip Lists 
*
* Author: Markus Bernal
* Date: 11/2/2024
* 
* Description: Driver file to Test skip lists class 
*              
*              
* Input: No input file 
* Output: Results displayed on console
* 
*******************************************************************************************/
#include "skipList.h"
#include<time.h>
int main(){
    float p = 0.5;
    // create new skiplist
    skipList<int> skip_list = skipList<int>(3,p);

    int size = 10;
    float i = 0;
    srand(time(NULL)) ;
    int key = rand()%1999 +1;
    int find = key;
    while (i< size+1){
        skip_list.insert(key, p+i);
        key = rand()%1999 +1;
        i++;
    }
    if(skip_list.search(find)) {
        std::cout << "value found" << std::endl;
    } else {
        std::cout << "value not found" << std::endl;
    }
    skip_list.print();
    std::cout << "Remove: " << find << std::endl;
    skip_list.remove(find);
    skip_list.print();

    
    
/*******************************************************************************************
*  1) Yes, this is a probabilistic structure. Top level would have the lowest probability
*      for key to be there. The expected number of pointers would be N at the lowest, 
*      N/2 at level 1 , N/4 at level 2 and so on. With the expected size the maximum levels
*      can be calculated.
*  2) max level = log2(N)
*  3) using modulus for random values doesn't give a uniform probability distribution for all values
*     using #include<random> will allow for uniform distribution of values giving it equal probability
*  4) The larger the number of nodes in a skip lists decreases the probability of worst case scenario
*
*******************************************************************************************/
    return 0;
}