/*
Programmers: Martin Luepker and Ben Krueger
date: 12/1/15
Section: J
ID: mcld 35 and bokkw4
file:Main.cpp
Description: a program to simulate a self driving car. 
 */

#include "header.h"
using namespace std;
#define STUPID_LEVELS 99

int main()
{
	srand(time(NULL));
	for(int times = 0; times < 3 ; times ++)
	{
	Car c;
	Road r;
	Animal animals[NUM_ANIMALS];
	
	int dist = 0;
	makeAnimals(animals);//fills the animal array
	c.setPos(Road::INIT_WIDTH /2);
	bool driving=true;
	while(driving)
	{
	  r.placeObj(Road::INIT_WIDTH,0,' ');//clears
	  c.amble(); //move the car around
	  r.placeObj(c.getWidth(),c.getPos(),'c');
	  if(rand() % 20 == 1)//5% chance to have pedestrian with 
	    {
	      Pedestrian p;
	      cout<<"\n"<<p.getName()<<" appears with BAC of "<<p.getBac()<<endl;
	      while(p.getPos()< Road::INIT_WIDTH)
		{

		  r.placeObj(1,p.getPos(),'p');
		  p.walk(r,c);
		  cout <<r;
		}
	      cout<<endl;
	    }
	  else//if no pedestrian in street have animal try to cross
	    {
	      int animalIndex = rand() % NUM_ANIMALS;
	      if(animals[animalIndex].chooseToRun(rand() % STUPID_LEVELS))
		{
		  animals[animalIndex].setPos(rand() % Road::INIT_WIDTH);
	    
		}
	  
	      //COLLISIONS PART
	      if(animals[animalIndex].getPos() >= c.getPos() && 
		 animals[animalIndex].getPos() +animals[animalIndex].getWidth() <= c.getPos()+ c.getWidth())
		// if hit add dammage and battery switch animal hit bool
		{
		  c.incrDamage(animals[animalIndex].getWeight());
		  c.incrBattery(animals[animalIndex].getWeight());
		  animals[animalIndex].hit();
		  // say comment
		  lonestar(animals[animalIndex]);
		  // add escore
		  c.incrEscore(animals[animalIndex].getWeight());
		  r.placeObj(animals[animalIndex].getWidth(),animals[animalIndex].getPos(),animals[animalIndex].getSymbol());
		}
	  
	    }
       	
	  c.changeBattery(-1);//sub battery
	  dist++;
	
	  //Output road state
	  cout<<r;
	  cout<<"Car damage: "<< c.getDamage()
		<<"% and Remaining battery life: "
		<<c.getBattery()<<"%"<<endl;	
	  cout<<endl;
	  //end conds
	  if(c.getDamage() >= Car::DAMAGE_MAX)	//damage 
	    {
	      cout<<"\nCar too damaged to go on. Exiting.\n";
	      driving = false;
	    }	
	  else if(dist >= MAX_DIST)//dist
	    {
	      cout<<"\nCar has reached its destination \n";
	      driving =false;
	    }
	  else if(c.getBattery() <= 0)//battery empty
	    {
	      cout<<"\nBattery ran out.\n";
	      driving = false;
	    }
	
	
	}//while
	//print 
		//list of animals hit
	

	//battery left
cout<<"Simulation terminated with:"<<endl;
cout<<"- Remaining car battery life: "<<c.getBattery()<<"%"<<endl;
cout<<"- Car damage: "<<c.getDamage()<<"%"<<endl;
cout<<"- Car's e-score: "<<c.getEscore()<<endl;
cout<<"- Distance traveled: "<<dist<<"km"<<endl;
cout<<"- Animals hit:"<<endl;
	for(int i = 0; i < NUM_ANIMALS; i ++)
	{
   	  if(animals[i].gethit())
	  {
	    cout<<animals[i];
	  }
	}
	}
	return 0;
}
/*

*/
