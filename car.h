/*
Martin Luepker
11/15/15
J
Leopold
creates 3 classes
*/

#ifndef CAR_H
#define CAR_H
#include "road.h"
#include <string.h>

class Car 
{
  private:
    static const int BATTERY_RATE = 5;    // amt to divide 
                                          //  weight when
                                          //  incr'ing battery                
    static const int DAMAGE_RATE = 10;    // amt to divide 
                                          //  weight when
                                          //  incr'ing damage
    static const char SYMBOL='c';   
    int m_width;                   // # of road sectors
    float m_damage;                // accumulate % of damage
    float m_battery;               // % remaining battery power
    int m_escore;                  //total mass of hit animals
    int m_pos;
    
  public:
    static const int BATTERY_MAX = 100;   // max battery value
    static const int DAMAGE_MAX = 100;    // max damage value
    // Default constructor for Car
    // Preconditions: None
    // Postconditions: m_width set to 4, m_damage set to 0,
    // between 90 and 100 (inclusive)
    Car() : m_width(4), m_damage(0), m_escore(0)
     { m_battery = rand() % 26 + 50; }

    // Accessor for m_width
    // Preconditions: None
    // Postconditions: Value of m_width is returned
    int getWidth() const { return(m_width); }
    int getPos() const {return m_pos;}
    char getSymbol() const { return (SYMBOL);}
    // Accessor for m_damage
    // Preconditions: None
    // Postconditions: Value of m_damage is returned
    float getDamage() const { return(m_damage); }

    // Accessor for m_battery
    // Preconditions: None
    // Postconditions: Value of m_battery is returned
    float getBattery() const { return(m_battery); }

    
    // Increment the battery power by the weight of some road
    // obstacle.
    // Preconditions: weight > 0
    // Postconditions: m_battery incremented by
    // weight/BATTERY_RATE, to maximum value BATTERY_MAX 
    void incrBattery(const int weight);

    // Increment the damage by the weight of some road
    // obstacle.
    // Preconditions: weight > 0
    // Postconditions: m_damage incremented by
    // weight/DAMAGE_RATE, to maximum value DAMAGE_MAX
    void incrDamage(const int weight);
    //Pre:
    //damage is a float
    //Post:
    //Memeber of m_damage is set to the value of damage.
    void changeDamage(const float damage){m_damage+=damage;}
    void changeBattery(const float charge){m_battery+=charge;}
    void incrEscore(const int weight){m_escore+=weight;}
    //Pre:
    //battery is a float variable
    //Post:
    //the value of m_battery is now equal to the argument battery
    void setBattery(const float battery){m_battery = battery;}

    void amble();
 
    // Overloaded operator for << 
    // Preconditions: None
    // Postconditions: State of Car will be output to outs,
    // thereby modifying ostream outs
    friend ostream& operator <<(ostream& outs, const Car& c);
    
};

#endif
