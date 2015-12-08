/*
Martin Luepker
11/15/15
J
Leopold
creates 3 classes
*/
#ifndef ROAD_H
#define ROAD_H

#include <string.h>
using namespace std;

struct segment
{
  char car;
  char ped;
  char ani;
};

class Road 
{
  public:
    static const int MAX_WIDTH = 15;      // specifications for
    static const int INIT_WIDTH = 10;     //  width of road

  private:
    static const char EMPTY = ' ';        // represents
                                          //  unoccupied sector
    int m_width;                   // actual # of road sectors
    segment m_sectors[MAX_WIDTH];     // what is in each sector

  public:
    // Default constructor for Road
    // Preconditions: None
    // Postconditions: m_width set to 10, all positions of
    // m_sectors set to EMPTY 
    Road();

    // Accessor for m_width
    // Preconditions: None
    // Postconditions: Value of m_width is returned
    int getWidth() const { return(m_width); }
    segment getSector(int num) const { return(m_sectors[num]); }
    // Mark appropriate sectors of the road to indicate that
    // a car is there.
    // Preconditions: 0 < carWidth < MAX_WIDTH,
    // 0 <= leftmostCarPosition < MAX_WIDTH, and mark is some
    // printable ASCII character.
    // Postconditions: m_sectors[leftmostCarPosition..
    // leftmostCarPosition+carWidth] = mark; all other sectors
    // are EMPTY 
    void placeObj(const int width, 
                  const int leftmostPosition,
                  const char mark);

    // Overloaded operator for << 
    // Preconditions: None
    // Postconditions: State of Road will be output to outs,
    // thereby modifying ostream outs
    friend ostream& operator <<(ostream& outs, const Road& r);
};


#endif