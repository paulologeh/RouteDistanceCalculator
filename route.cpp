// implementation file route.cpp
// this is the implementation of the class journey
// Written by Paul Ologeh
// 03/11/2015

#include "route.h"
#include <iostream>
#include <string.h>
#include <math.h>
#include <iomanip>

using namespace std;

void journey::inputPoints()
{
	bool run = true;
	checking.initialiseDatabase(); // calls function to initialise the database
		
	while (run)   // exists loop only if all cities are entered correctly
	{
		// enter starting city
	cout << "\nEnter Starting city: ";
	cin >> startPoint;

	// enter destination city
	cout << "Enter destination city: ";
	cin >> endPoint;
	
	//enter three cities that are way points
	cout << "Please enter three cities enroute this journey\n";
	cout << "Enter first city: ";
	cin >> wayPoint1;
	cout << "Enter next city: ";
	cin >> wayPoint2;
	cout << "Enter last city: ";
	cin >> wayPoint3;
	
	run = checking.checkPointDatabase(startPoint, endPoint, wayPoint1, wayPoint2, wayPoint3);  // returns 0 if all cities are correct or 1 if all cities are incorrect
	// returns false to exit the loop
    cout << "Returning " << run << endl;	
	}

}

void journey::getTotalDistance()
{
	// instantiations
	float start_end, start_way1, way1_way2, way2_way3, way3_end, total_route;
	float startlong, endlong, way1long, way2long, way3long;
	float startlat, endlat, way1lat, way2lat, way3lat;
	float X,Y,Z,U,T,S,Q,K;
	float r= 6371; // earth's radius
	
	// get latitude and longitude of all points	
	startlong=checking.getLatitudeAtLocation(startPoint);
	startlat=checking.getLongitudeAtLocation(startPoint);  // Calls Latitude and Longitude function for each inputted point
	endlong=checking.getLatitudeAtLocation(endPoint);
	endlat=checking.getLongitudeAtLocation(endPoint);
	way1long=checking.getLatitudeAtLocation(wayPoint1);
	way1lat=checking.getLongitudeAtLocation(wayPoint1);
	way2long=checking.getLatitudeAtLocation(wayPoint2);
	way2lat=checking.getLongitudeAtLocation(wayPoint2);
	way3long=checking.getLatitudeAtLocation(wayPoint3);
	way3lat=checking.getLongitudeAtLocation(wayPoint3);
	
	// Haversine formula..
	 
	// Distance between start point and end point
    Q=sin(0.5*endlong-0.5*startlong);   K=sin(0.5*endlat-0.5*startlat);
    X=Q*Q;  Z=K*K;
    Y=cos(endlong)*cos(startlong);
    U=X+(Y*Z);
    T=sqrt(U);
    S=asin(T);
    start_end=2*r*S;
    cout<<"\n";
    cout<<"Distance between start point and end point is ";
    cout << start_end;
    
    // Distance between start point and way point 1
    Q=sin(0.5*way1long-0.5*startlong);  K=sin(0.5*way1lat-0.5*startlat);
    X=Q*Q;  Z=K*K;
    Y=cos(way1long)*cos(startlong);
    U=X+(Y*Z);
    T=sqrt(U);
    S=asin(T);
    start_way1=2*r*S;
    cout<<"\n";
    cout<<"Distance between start point and way point 1 is ";
    cout << start_way1;
    
    // Distance between way point 1 and way point 2
    Q=sin(0.5*way2long-0.5*way1long);  K=sin(0.5*way2lat-0.5*way1lat);
    X=Q*Q;  Z=K*K;
    Y=cos(way2long)*cos(way1long);
    U=X+(Y*Z);
    T=sqrt(U);
    S=asin(T);
    way1_way2=2*r*S;
    cout<<"\n";
    cout<<"Distance between way point 1 and way point 2 is ";
    cout << way1_way2;
	
	 // Between way point 2 and way point 3
    Q=sin(0.5*way3long-0.5*way2long);  K=sin(0.5*way3lat-0.5*way2lat);
    X=Q*Q;  Z=K*K;
    Y=cos(way3long)*cos(way2long);
    U=X+(Y*Z);
    T=sqrt(U);
    S=asin(T);
    way2_way3=2*r*S;
    cout<<"\n";
    cout<<"Distance between way point 2 and way point 3 is ";
    cout << way2_way3;
	
	 // Distance between way point 3 and end point
    Q=sin(0.5*endlong-0.5*way3long);  K=sin(0.5*endlat-0.5*way3lat);
    X=Q*Q;  Z=K*K;
    Y=cos(endlong)*cos(way3long);
    U=X+(Y*Z);
    T=sqrt(U);
    S=asin(T);
    way3_end=2*r*S;
    cout<<"\n";
    cout<<"Distance between way point 3 and the end point is ";
    cout << way3_end;
	
	// Total distance from start point to end point through way points
	total_route= start_way1 + way1_way2 + way2_way3 + way3_end;  // Adds all way points
	cout << "\nTotal Distance through way points is " << total_route << endl;
	
}
