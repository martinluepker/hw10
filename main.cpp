#include "header.h"
using namespace std;

int main()
{
	srand(time(NULL));
	Car c;
	Road r;
	Animal a[NUM_ANIMALS];
	
	int dist;
	makeAnimals(a);//fills the animal array
	
	
	bool driving=1;
	while(driving)
	{
	if(rand() % 100 < 5 )//5% chance to have pedestrian with 
	{
	  Pedestrian P;
	}
	else//if no pedestrian in street have animal try to cross
	{
	  Animal a;
	}
	
		// if hit add dammage and battery switch animal hit bool
		// say comment
		// add escore
		//else nothing
		
	
	
	//sub battery
	dist++;
	//change pos on track using switch
	
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
