// header file route.h
// this is the specification for the journey routes
// Written by Paul Ologeh
// 03/11/2015

#include "Database.h"

using namespace std;

class journey
{
	private:
		string startPoint;
		string endPoint;
		string wayPoint1;
		string wayPoint2;
		string wayPoint3;
		database checking;
    public:
		//public functions
		void inputPoints();
		void getTotalDistance();
};
