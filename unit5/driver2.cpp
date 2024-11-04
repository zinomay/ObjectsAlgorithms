#include "skipList.h"

int main(){
    float p = 0.5;
    // create new skiplist
    skipList<int> test = skipList<int>(5,p);
    test.print();
    test.insert(0,5);
    test.print();
    
    test.insert(0,10);
    test.print();
    test.insert(2,10);
    test.print();
    test.insert(1,10);
    test.print();
    
    return 0;
}