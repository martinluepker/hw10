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
	
	
	bool driving=1;
	while(driving)
	{
	if(rand() % 20 == 1)//5% chance to have pedestrian with 
	{
	  Pedestrian p;
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
	  
	  
	  if(animals[animalIndex].getPos() >= c.getPos() || 
	     animals[animalIndex].getPos() +animals[animalIndex].getWidth() <= c.getPos()+ c.getWidth())
	    // if hit add dammage and battery switch animal hit bool
	  {
	    c.incrDamage(animals[animalIndex].getWeight());
	    c.incrBattery(animals[animalIndex].getWeight());
	    animals[animalIndex].hit();
	    lonestar(animals[animalIndex]);
	  }
	  
	  // say comment
	  
	  // add escore
	  c.incrEscore(animals[animalIndex].getWeight());
	}
       	
	//c.changeBattery();//sub battery
	dist++;
	//change pos on track using switch
	cout<<r;
	//end conds
		//damage 
		//dist
		//battery empty
	//print 
		//end reason
	}
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
