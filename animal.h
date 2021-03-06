

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string.h>
#include <cstdlib>
#include "Road.h"
using namespace std;

class Animal 
{
  private:
    static const int MAX_STUPIDITY = 100;  // Limits on
    static const int MIN_STUPIDITY = 0;    //  m_stupidity
    static const char SYMBOL='a';
    int m_weight;                  // weight in kg

    string m_species;              // e.g., "deer", "possum"

    int m_width;                   // # sectors of road that 
                                   //  animal occupies

    int m_stupidity;               // % (0..100) that determines
                                   //  whether animal runs onto
                                   //  road
    bool m_hit;
    int m_pos;
  public:

    Animal();

    // Accessor for m_width
    // Preconditions: None
    // Postconditions: Value of m_width is returned
    int getWidth() const { return(m_width); }

    // Accessor for m_weight
    // Preconditions: None
    // Postconditions: Value of m_weight is returned
    int getWeight() const { return(m_weight); }

    // Determine whether this animal chooses to run.
    // Preconditions: MIN_STUPIDITY  <= stupidity <= 
    // MAX_STUPIDITY 
    // Postconditions: Returns true if m_stupidity >=
    // stupidity; otherwise, return false 
    bool chooseToRun(const int random) const 
     { return(m_stupidity >= random); }

    // Overloaded operator for << 
    // Preconditions: None
    // Postconditions: State of Animal will be output to outs,
    // thereby modifying ostream outs
    friend ostream& operator <<(ostream& outs, const Animal& a);

    // Mutator for m_stupidity
    // Preconditions: 0 <= stupidity <= 100
    // Postconditions: m_stupidity set to stupidity, not
    // to exceed boundary conditions
    void setStupidity(const int stupidity);

    // Mutator for m_weight
    // Preconditions: weight > 0
    // Postconditions: m_weight set to weight (minimum 1)
    void setWeight(const int weight);

    // Mutator for m_width
    // Preconditions: 0 < width < Road::MAX_WIDTH
    // Postconditions: m_weight set to weight (minimum 1)
    void setWidth(const int width);
    //Mutator for m_pos
    //Pre: none.
    //Post: value of m_pos = pos
    void setPos(const int pos){m_pos = pos;}
    //Accessor for m_pos
    //Pre: none
    //Post: returns value of m_pos
    int getPos(){return m_pos;}
    //Function to change the hit state of the animal class
    //Pre: m_hit is still initilized to false.
    //Post: m_hit is now true.
    void hit(){m_hit = true;}
    //An accessor for the m_hit member.
    //Pre:none.
    //Post:value of m_hit is returned.
    bool gethit(){return m_hit;}
    //A Mutator for the species member.
    //Pre: none.
    //Post: value of string species is now m_species
    void setSpecies(const string species);
    //Accessor for the m_species member
    //Pre: none.
    //Post: value of m_species is returned.
    string getSpecies()const {return(m_species);}
    //Accessor for SYMBOl member
    //Pre: none
    //Post: value of SYMBOL is returned.
    char getSymbol() const { return (SYMBOL);}
};

#endif
