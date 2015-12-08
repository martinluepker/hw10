/*
Martin Luepker
11/15/15
J
Leopold
creates 3 classes
*/
#include "header.h"
#include "road.h"
using namespace std;
Road::Road()
{
  m_width = INIT_WIDTH;
  for (int i = 0; i < MAX_WIDTH; i++)
  {
    m_sectors[i].car=EMPTY;
    m_sectors[i].ped=EMPTY;
    m_sectors[i].ani=EMPTY;
  }
}

void Road::placeObj(const int width, 
                    const int leftmostPosition,
                    const char mark)
{
  int endPos;

  if ((width < 0) || (width >= MAX_WIDTH))
    endPos= 0;
  else endPos = leftmostPosition + width - 1;
  for (int i = 0; i < MAX_WIDTH; i++)
  {
    if ((i >= leftmostPosition) && (i <= endPos))
      switch(mark)
      {
        case a:
        m_sectors[i].ani = mark;
        break;
        case c:
        m_sectors[i].car = mark;
        break;
        case p:
        m_sectors[i].ped = mark;
        break;    
        default:
        cout<<"nope";
      }
    else m_sectors[i] = EMPTY;
  }
  return;
}


ostream& operator << (ostream& outs, const Road& r) 
{
  for (int i = 0; i < r.m_width; i++)
    outs << "|" << r.m_sectors[i];  
  outs << "|\n";
  return(outs);
}
