/*
Martin Luepker
11/15/15
J
Leopold
creates 3 classes
*/
#include "header.h"
#include "pedestrian.h"

Pedestrian::Pedestrian()
{
	m_bac=(rand()%3)/10;
	m_name=names[rand()%NAME_NUM];
	m_pos=0;
}

void Pedestrian::walk(Road r, Car c)
{
	bool drunk=bac>=0.1?1:0;
	if(drunk)
	{
		rand()%100>=75?pos++:pos--;
		if(r.getSector(pos).ped==SYMBOL)
			
	}
	else
	{
		pos++;
	}
	return;
}