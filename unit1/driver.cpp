/************************************
* Markus Bernal
* 10/15/2024
* 
* Unit 1 assignment 1 
* Input:
* Output:
***********************************/

// Given code in assignment 
/*template <TypeName Comparable>
int binarySearch( const vector<Comparable> & a, const Comparable & x){
  int low = 0, high = a.size()-1;
  while(low <= high) {
    int mid = (low + high)/2;
    
    if( a[mid] == x ){
      return mid; 
    }
    if( a[mid] < x){
      low = mid+1;
    } else {
      high = mid-1;
    }
  }
}*/

int main() { 
  
  /* what is the count of comparisons of binary_search given an input array of size N for the original version?
     what is the count of comparisons of binary_serch given an input array of size N for the updated and improved version?
  */
  int low = 0;
  int high = a.size()-1;
  int mid = (low + high)/2;
  while(low <= high) {
    mid = (low + high);
    if( a[mid] < x){
      low = mid+1;
    } else {
      high = mid;
    }
  }
  if (a[mid] == x){
    return mid; 
  }
  return 0;
}
