#include "skipList.h"
#include<time.h>
int main(){
    float p = 0.95;
    // create new skiplist
    skipList<int> skip_list = skipList<int>(500,p);

    int size = 10;
    float i = 1;
    srand(time(NULL)) ;
    while (i< size+1){
        int key = rand()%1999 +1;
        skip_list.insert(key, p+i);
        i++;
    }
    /*if(skip_list.search(10)) {
        std::cout << "value found" << std::endl;
    } else {
        std::cout << "value not found" << std::endl;
    }*/
    skip_list.print();
    return 0;
}