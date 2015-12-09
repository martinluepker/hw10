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

void Car::amble()
{
  if(m_pos!=0||m_pos!=Road::INIT_WIDTH)-1)
    rand()%2?m_pos++:m_pos--;
  else if(m_pos==0)
    m_pos++;
  else
    m_pos--;
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

ostream& operator << (ostream& outs, const Car& c) 
{
  outs << "Car width = " << c.m_width << ", damage = "
       << c.m_damage << ", battery = " << c.m_battery
       << ", symbol = " << c.SYMBOL << endl;
  return(outs);
}

