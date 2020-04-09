// implementation file database.cpp
//this is the implementation of the class 
// Written by Paul Ologeh
// 03/11/2015

#include "Database.h"
#include <iostream>
#include <string.h>
#include <math.h>
#include <iomanip>

using namespace std;

void database::initialiseDatabase()
{
	databasefile.open("locDatabase.txt");  // Opens text file containing location data
	for (int i=0; i<120; i++)
	{
		databasefile >> locations[i].city >> locations[i].country>> locations[i].latitude_degree >> locations[i].latitude_minutes >> locations[i].latitude_direction >> locations[i].longitude_degree >> locations[i].longitude_minutes >> locations[i].longitude_direction;
		 // outputs data from file into array of struct         
	}
}


bool database::checkPointDatabase(string startPoint, string endPoint, string wayPoint1, string wayPoint2, string wayPoint3)
{
	bool validStart = false, validEnd = false, validWay1 = false, validWay2 = false, validWay3 = false;

	for(int i=0; i<120; i++)
	{
		if (locations[i].city == startPoint)
		{
			validStart = true;
		}
		if (locations[i].city == endPoint)
		{
			validEnd = true;
		}
		if (locations[i].city == wayPoint1)
		{
			validWay1 = true;
		}
		if (locations[i].city == wayPoint2)
		{
			validWay2 = true;
		}
		if (locations[i].city == wayPoint3)
		{
			validWay3 = true;
		}
	}

	if (!validStart)
	{
		cout << startPoint << " is not in Database\n";
	}
	
	if (!validEnd)
	{
		cout << endPoint << " is not in Databse\n";
	}

	if(!validWay1)
	{
		cout << wayPoint1 << " is not in Databse\n";
	}

	if(!validWay2)
	{
		cout << wayPoint2 << " is not in Databse\n";
	}

	if(!validWay3)
	{
		cout << wayPoint3 << " is not in Databse\n";
	}

	if (!validStart || !validEnd || !validWay2 || !validWay1 || !validWay3)
	{
		return true;
	}

	return false;
}


float database::getLatitudeAtLocation(string point)
 {
	int i;
	float a,b,d;
	char c;
	for(i=0;i<120;i++)
	{
		if(point==locations[i].city)
		{
			// Read latitude values
			a=locations[i].latitude_degree;
			b=locations[i].latitude_minutes;
			c=locations[i].latitude_direction;
		}
	}
	b=b*0.000291; // converts minutes to radians
    a=a*0.01745; // converts degrees to radians
	
	d=a+b;   // total angle in degrees
	if(c=='S')
	{
	  d=-1*d;	// Makes angle negative because of south
	            // North is positive, South is negative, East is positive, West is negative                 
	}
	return d;
}
float database::getLongitudeAtLocation(string point)
{
	int i;
	float a,b,d;
	char c;
	for(i=0;i<120;i++)
	{
		if(point==locations[i].city)
		{
			// Reads latitude values
			a=locations[i].longitude_degree;
			b=locations[i].longitude_minutes;
			c=locations[i].longitude_direction;
		}
	}
	b=b*0.000291; // converts minutes to radians
	a=a*0.01745; // converts degrees to radians
	d=a+b;  // total angle in degrees

	if(c=='W')
	{
		d= -1*d;  // Makes angle negative because of West
	            // North is positive, South is negative, East is positive, West is negative   
	}
	return d;
}
