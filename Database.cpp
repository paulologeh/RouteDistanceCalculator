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

void data::initialiseDatabase()
{
	databasefile.open("locDatabase.txt");  // Opens text file containing location data
	int i;
	for (i=0;i<120;i++)
	{
		databasefile >> locations[i].city >> locations[i].country>> locations[i].latitude_degree >> locations[i].latitude_minutes >> locations[i].latitude_direction >> locations[i].longitude_degree >> locations[i].longitude_minutes >> locations[i].longitude_direction;
		 // outputs data from file into array of struct         
	}
}


int data::checkPointDatabase(string startPoint, string endPoint, string wayPoint1, string wayPoint2, string wayPoint3)
{
	int j,k,l,m,n;
	int i;


        // Check is start point is valid
 
        j=2;
        
		for(i=0;i<120;i++)
		{
			if (startPoint==locations[i].city)
			{
				j=0;
				
			}		
	    }
		
		// Checks if j has changed	
		if (j==2)
		{
			cout << "Start Point is not in Database\n";		// Error message
		}
		else
		{
			cout << "Start Point is in Database.\n";
		}
		
		// Check is end point is valid
		
		k=2;
		for(i=0;i<120;i++)
		{

			if (endPoint==locations[i].city)
			{
				k=0;
			}
	    }
			
		if (k==2)
		{
			cout << "End Point is not in Database\n";   // Error Message
		}
		else
		{
		    cout << "End Point is in Database.\n";
		}
		
		l=2;
		// Check is way point1 is valid
		for(i=0;i<120;i++)
		{
			if (wayPoint1==locations[i].city)
			{
				l=0;
			}
	    }
			
    	if (l==2)
		{
			cout << "Way Point1 is not in Database\n";    // Error message
		}
		else
		{
			cout << "Way Point1 is in Database.\n";
		}
		
		
		// Check is way point2 is valid
        m=2;
		for(i=0;i<120;i++)
		{
	 	if (wayPoint2==locations[i].city)
			{	
				m=0;
			}
	    }
			
		if (m==2)
		{
			cout << "Way Point2 is not in Database\n"; // Error message
		}
		else
		{
			cout << "Way Point2 is in Database.\n";
		}
		
		
		// Check is way point3 is valid
		n=2;
		for(i=0;i<120;i++)
		{
			if (wayPoint3==locations[i].city)
			{
				n=0;
			}
	    }
			
		if (n==2)
		{
			cout << "Way Point3 is not in Database\n";    // Error message
		}
		else
		{
			cout << "Way Point3 is in Database.\n";
		}
		
		// Determine return value
		if (j==2 || k==2 || l==2 || m==2 || n==2)
		{
			return 1; // returns 1 if any point is not in database
		}
		else
		{
			return 0; // returns 0 if all are in database
		}
}


float data::getLatitudeAtLocation(string point)
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
float data::getLongitudeAtLocation(string point)
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
