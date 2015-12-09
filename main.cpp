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
	      cout<<"\nA pedestrian appears.\n";
	      while(p.getPos()< Road::INIT_WIDTH)
		{

		  p.walk(r,c);
		  r.placeObj(1,p.getPos(),'p');
		  cout <<r;
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
		  r.placeObj(animals[animalIndex].getWidth(),animals[animalIndex].getPos(),animals[animalIndex].getSymbol());
		}
	  
	    }
       	
	  c.changeBattery(-1);//sub battery
	  dist++;
	
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
	  cout<<"\nPosition of car:"<<c.getPos()
	      <<"Escore:"<<c.getEscore()<<endl;
	}//while
	//print 
		//list of animals hit
	cout<<"Finals report\nYou hit:"<<endl;
	for(int i = 0; i < NUM_ANIMALS; i ++)
	{
	  cout<<animals[i]<<endl;
	}
	//battery left
	cout<<"You have :"<<c.getBattery() << " left."<<endl;
	//damage level
	cout<<"The damage level is:"<<c.getDamage()<<endl;
	//e-score
	cout<<"The e score is :"<<c.getEscore()<<endl;
	//distance traveled
	cout<<"The distance traveled was :"<< dist;
	return 0;
}
/*

*/
