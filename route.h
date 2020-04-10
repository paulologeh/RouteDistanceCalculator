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
	float haversineFormula(float, float, float, float);
	void getTotalDistance();
};
