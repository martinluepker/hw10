#include "header.h"
using namespace std;

void makeAnimals(Animal a[])
{
	ifstream fin;
	fin.open("animal.dat");
	for(int i=0;i<NUM_ANIMALS;i++)
	{
		int weight;
		string species;
		int width;
		int stupidity;
		fin>>species;
		fin>>width;
		fin>>weight;
		fin>>stupidity;
		a[i].setStupidity(stupidity);
    	a[i].setWeight(weight);
		a[i].setWidth(width);
    	a[i].setSpecies(species);
	}
	fin.close();
}

void lonestar()
{
	ifstream fin;
	fin.open("lonestar.dat");
	string sent;
	for(int i=0;i<=rand()%NUM_COMMENTS;i++)
	{
		getline(cin,sent);
	}
	cout<<sent;
	fin.close();
}

