//  C++ program to find distance along a route with cities as start point and end points and way points
// Written by Paul Ologeh
// 03/11/2015

#include "route.h"
#include <string.h>
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

int main()
{
	journey Ajourney;

	cout << "Welcome to my program \n";
	Ajourney.inputPoints();  // call function to input points
    Ajourney.getTotalDistance();  // call funtion to calculate the distances between inputted points
	system("pause");
	
}
