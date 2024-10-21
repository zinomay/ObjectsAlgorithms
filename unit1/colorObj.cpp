/********************************************
* Author: Markus Bernal
* Date: 10/20/2024
*********************************************/

#include <string>

class colorObj{
  private:
    string color;
    int rank;
  public:
    colorObj( string color, int rank ): color(color), rank(rank) {}
    operator<(const colorObj& other ){
      return ( rank < other.rank );
    }
}
