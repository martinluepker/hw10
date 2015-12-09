
#ifndef FUNC_H
#define FUNC_H
#include "header.h"
using namespace std;

//A function to get all of the animal information out of animals.dat
//Preconditions: An animal.dat file exists.
//Post: Every animal object in a is initilized to information in animals.dat
void makeAnimals(Animal a[]);
//A function to output the loserstar system comments
//Pre: An comments.dat file exists and lonestar is passed a refernce to an animal object.
//Post: a comment with a the name of the animal is printed to the screen.
void lonestar(Animal & a);

#endif
