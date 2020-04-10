// header file Database.h
// this is the specification for the Database
// Written by Paul Ologeh
// 03/11/2015

#include <fstream>
#include <iostream>

using namespace std;

// Structure containing all the attritubtes of location
struct location
{
	string city;
	string country;
	int latitude_degree;
	int latitude_minutes;
	char latitude_direction;
	int longitude_degree;
	int longitude_minutes;
	char longitude_direction;
};

class database
{
private:
	ifstream databasefile;
	location locations[120];

	// functions
public:
	void initialiseDatabase();
	bool checkPointDatabase(string &, string &, string &, string &, string &);
	float getLatitudeAtLocation(string &);
	float getLongitudeAtLocation(string &);
};
