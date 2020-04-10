//  C++ program to find distance along a route with cities as start point and end points and way points
// Written by Paul Ologeh
// 03/11/2015

#include "route.h"

int main()
{
	journey myJourney;

	std::cout << " Route Distance Calculator\n";
	std::cout << "Calculates distance between 2 points\n";

	myJourney.inputPoints();	  // call function to input points
	myJourney.getTotalDistance(); // call funtion to calculate the distances between inputted points

	return 0;
}
