/********************************************
* Author: Markus Bernal
* Date: 10/20/2024
*********************************************/

#include <string>
#include <iostream>

class colorObj{
  private:
    std::string color;
    int rank;
  public:
    colorObj(){ color = ""; rank = 0; }
    colorObj( std::string color, int rank ): color(color), rank(rank) {}
    void print(){
      std::cout << "color: " << color << "rank: "<< rank << std::endl;
    }
    bool operator<(const colorObj& other ){
      return ( rank < other.rank );
    }
};

