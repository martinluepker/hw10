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
    
      switch(mark)
      {
        case 'a':
          if ((i >= leftmostPosition) && (i <= endPos))
            m_sectors[i].ani = mark;
          else m_sectors[i].ani = EMPTY;
        break;
        case 'c':
          if ((i >= leftmostPosition) && (i <= endPos))
            m_sectors[i].car = mark;
          else m_sectors[i].car = EMPTY;
        break;
        case 'p':
          if ((i >= leftmostPosition) && (i <= endPos))
            m_sectors[i].ped = mark;
          else m_sectors[i].ped = EMPTY;
        break;    
        default:
        cout<<"nope";
      }
      
  }
  return;
}


ostream& operator << (ostream& outs, const Road& r) 
{
  for (int i = 0; i < r.m_width; i++)
  {
      if(r.m_sectors[i].ped==' '&&r.m_sectors[i].ani==' ')
        outs << "|" << r.m_sectors[i].car; 
      if(r.m_sectors[i].ped=='p')
        outs << "|" << r.m_sectors[i].ped;
      if(r.m_sectors[i].ani=='a')
        outs << "|" << r.m_sectors[i].ani;
  }
  outs << "|\n"<<endl;
  return(outs);
}
