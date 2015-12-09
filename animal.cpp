/*
Martin Luepker
11/15/15
J
Leopold
creates 3 classes
*/
#include "header.h"
#include "animal.h"

Animal::Animal(){
  
}

ostream& operator << (ostream& outs, const Animal& a) 
{
  outs << a.m_species << ", " << a.m_weight << " kg,"
       << " occupies " << a.m_width << " road sector(s),"
       << " stupidity level " << a.m_stupidity << endl;
  return(outs);
}

void Animal::setStupidity(const int stupidity)
{
  m_stupidity = stupidity > MAX_STUPIDITY? MAX_STUPIDITY: 
                stupidity;
  m_stupidity = stupidity < MIN_STUPIDITY? MIN_STUPIDITY: 
                stupidity;
  return;
}

void Animal::setWeight(const int weight)
{
  m_weight = weight < 0? 1: weight;
  return;
}

void Animal::setWidth(const int width)
{
  m_width = width < 0? 1: width;
  m_width = width > Road::MAX_WIDTH? Road::MAX_WIDTH: width;
  return;
}

 void Animal::setSpecies(const string species)
 {
   m_species=species;
   return;
 }
