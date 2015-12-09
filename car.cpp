
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
  if(m_pos==0)
    m_pos++;
  else if(m_pos==Road::INIT_WIDTH-m_width)
    m_pos--;
  else
    rand()%2?m_pos++:m_pos--;
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

