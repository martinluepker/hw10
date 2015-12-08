/*
Martin Luepker
11/15/15
J
Leopold
creates 3 classes
*/
#include "header.h"
#include "car.h"
using namespace std;

void Car::incrBattery(const int weight) 
{
  if (weight > 0) 
  {
    m_battery = m_battery + 
                static_cast<float>(weight)/BATTERY_RATE;
    if (m_battery > BATTERY_MAX)
      m_battery = BATTERY_MAX;
  }
  return;
}

void Car::incrDamage(const int weight) 
{
  if (weight > 0) 
  {
    m_damage = m_damage + 
               static_cast<float>(weight)/DAMAGE_RATE;
    if (m_damage > DAMAGE_MAX)
      m_damage = DAMAGE_MAX;
  }
  return;
}

void Car::enterRoad(Road &r,const int leftmostpos) const
{
  if ((leftmostpos >= 0) &&
      (leftmostpos <= r.getWidth() - m_width))
    r.placeCar(m_width, leftmostpos,SYMBOL);
  else cout << "Error: Car:enterRoad cannot place a"
            << " car of width " << m_width 
            << " at position " << leftmostpos
            << " of a road of width " 
            << r.getWidth() << endl;
  return;
}

ostream& operator << (ostream& outs, const Car& c) 
{
  outs << "Car width = " << c.m_width << ", damage = "
       << c.m_damage << ", battery = " << c.m_battery
       << ", symbol = " << c.SYMBOL << endl;
  return(outs);
}

