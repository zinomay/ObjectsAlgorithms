#ifndef EXT_HASHTABLE
#define EXT_HASHTABLE
#include <vector>
#include <bitset>

class Bucket {
    public:
        Bucket(int N): N(N) {  }

        void insert(int value){
        
        };

        int findPos( const int & x ){
            int currentPos = buckethash(x);
        }

        std::size_t buckethash( const int & x) const {
            return x % array.size();
        };
    private:
    int N;
    std::vector<int> array;

};

template<typename Bucket>
class ExtendibleHashTable
{
    public:
        ExtendibleHashTable(){
            
        };
        void makeEmpty(){
            size = 0;
            for( auto & Bucket : array){
                delete Bucket;
                Bucket = nullptr;
            }
        }
        void insert(){};
        void find(){};
        void remove(){};
        void display(){};
    private:
        std::vector<Bucket*> array;
        int size;
        void rehash(){
            std::vector<Bucket*> prev_array = array;
            array.resize(2*size);
            for( auto & bucket : array ){
                bucket = nullptr;
            }
            for( auto & bucket : prev_array){
                if( bucket != nullptr ){
                    insert ( std::move(bucket) );
                }
            }
        }
};
#endif