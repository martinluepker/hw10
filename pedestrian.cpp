
#include "header.h"
#include "pedestrian.h"

Pedestrian::Pedestrian()
{
	m_bac=static_cast<float>(rand()%3)/10;
	m_name=names[rand()%NAME_NUM];
	m_pos=0;
}

void Pedestrian::walk(Road r, Car c)
{
	if(m_bac>=0.1)
	{
	  rand()%4<3?m_pos++:m_pos--;

	}
	else
	{
		m_pos++;
	}
	if(r.getSector(m_pos).ped == 'p' && r.getSector(m_pos).car  == 'c')
	{
	  if(m_bac >= 0.1)
	  {
	    c.changeDamage(-1);
	  }
	  else
	  {
	    c.changeDamage(1);
	  }
	}
	return;
}
