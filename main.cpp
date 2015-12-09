/*

 */

#include "header.h"
using namespace std;
#define STUPID_LEVELS 99

int main()
{
	srand(time(NULL));
	Car c;
	Road r;
	Animal animals[NUM_ANIMALS];
	
	int dist;
	makeAnimals(animals);//fills the animal array
	
	
	bool driving=true;
	while(driving)
	{
	r.placeObj(Road::INIT_WIDTH,0,' ');//clears
	if(rand() % 20 == 1)//5% chance to have pedestrian with 
	{
	  Pedestrian p;
	  cout<<"\nA pedestrian appears.\n";
	  while(p.getPos()< Road::INIT_WIDTH)
	  {
	    p.walk(r,c);
	  }
	}
	else//if no pedestrian in street have animal try to cross
	{
	  int animalIndex = rand() % NUM_ANIMALS;
	  if(animals[animalIndex].chooseToRun(rand() % STUPID_LEVELS))
	  {
	    animals[animalIndex].setPos(rand() % Road::INIT_WIDTH);
	    
	  }
	  
	  //COLLISIONS PART
	  if(animals[animalIndex].getPos() >= c.getPos() || 
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
	    r.placeObj(animals[animalIndex].getWidth(),animals[animalIndex].getPos(),'a');
	  }
	  
	}
       	r.placeObj(c.getWidth(),c.getPos(),'c');
	c.changeBattery(-1);//sub battery
	dist++;
	c.amble();
	//Output road state
	cout<<r;
       
	//end conds
	if(c.getDamage() > Car::DAMAGE_MAX)	//damage 
	  {
	    cout<<"\nCar too damaged to go on. Exiting.\n";
	    driving = false;
	  }	
	else if(dist >= MAX_DIST)//dist
	  {
	    cout<<"\nCar has completed \n";
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
		//damage level
		//e-score
		//distance traveled
	return 0;
}
/*

*/
