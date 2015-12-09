#ifndef pedestrian_H
#define pedestrian_H

#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

const int NAME_NUM=27;
const string names[NAME_NUM]={"Bruce Wayne","Bruce Banner",
"Peter Parker","Steve Rodgers","Scott Summers","Natasha Romanova","Tony Stark",
"Matthew Murdock","Peter Quill","Scott Lang","Hank McCoy","Clint Barton",
"Charles Xavier","Erik Lehnsherr","Jean-Luc Picard","James Kirk","Benjamin Sisko",
"Kathryn Janeway","Noonien Soong","William Riker","Geordi La Forge","Deanna Troi",
"Ezri Dax","Julian Bashir","Miles O'Brien","Harry Kim","Wesley Crusher"};

class Pedestrian
{
	private:
		static const int WIDTH=1;
		static const char SYMBOL='p';
		int m_pos;
		float m_bac;
		string m_name;
		
	public:
		Pedestrian();
		void walk(Road,Car);
		int getPos()const {return m_pos;}
		void setPos(int pos){ m_pos = pos;}
		char getSymbol()const{ return (SYMBOL);}
};

#endif
