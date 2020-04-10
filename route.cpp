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

    while (run) // exists loop only if all cities are entered correctly
    {
        // enter starting city
        cout << "Enter Starting city: ";
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

        run = checking.checkPointDatabase(startPoint, endPoint, wayPoint1, wayPoint2, wayPoint3); // returns 0 if all cities are correct or 1 if all cities are incorrect
                                                                                                  // returns false to exit the loop
    }
}

float journey::haversineFormula(float startlong, float startlat, float endlong, float endlat)
{
    float Q = sin(0.5 * endlong - 0.5 * startlong);
    float K = sin(0.5 * endlat - 0.5 * startlat);
    float X = Q * Q;
    float Z = K * K;
    float Y = cos(endlong) * cos(startlong);
    float U = X + (Y * Z);
    float T = sqrt(U);
    float S = asin(T);
    const float r = 6371;
    float distance = 2 * r * S;
    return distance;
}

void journey::getTotalDistance()
{
    // get latitude and longitude of all points
    float startlong = checking.getLatitudeAtLocation(startPoint);
    float startlat = checking.getLongitudeAtLocation(startPoint); // Calls Latitude and Longitude function for each inputted point
    float endlong = checking.getLatitudeAtLocation(endPoint);
    float endlat = checking.getLongitudeAtLocation(endPoint);
    float distanceStartEnd = haversineFormula(startlong, startlat, endlong, endlat);
    cout << "\n";
    cout << "Distance between " << startPoint << " and " << endPoint << " is " << distanceStartEnd << endl;
    ;

    float way1long = checking.getLatitudeAtLocation(wayPoint1);
    float way1lat = checking.getLongitudeAtLocation(wayPoint1);
    float distanceStartWay1 = haversineFormula(startlong, startlat, way1long, way1lat);
    cout << "Distance between " << startPoint << " and " << wayPoint1 << " is " << distanceStartWay1 << endl;
    ;

    float way2long = checking.getLatitudeAtLocation(wayPoint2);
    float way2lat = checking.getLongitudeAtLocation(wayPoint2);
    float distanceWay1Way2 = haversineFormula(way1long, way1lat, way2long, way2lat);
    cout << "Distance between " << wayPoint1 << " and " << wayPoint2 << " is " << distanceWay1Way2 << endl;

    float way3long = checking.getLatitudeAtLocation(wayPoint3);
    float way3lat = checking.getLongitudeAtLocation(wayPoint3);
    float distanceWay2Way3 = haversineFormula(way2long, way2lat, way3long, way3lat);
    cout << "Distance between " << wayPoint2 << " and " << wayPoint3 << " is " << distanceWay2Way3 << endl;

    float distanceWay3End = haversineFormula(way3long, way3lat, endlong, endlat);
    cout << "Distance between " << wayPoint3 << " and " << endPoint << " is " << distanceWay3End << endl;
    // Total distance from start point to end point through way points
    float distanceTotal = distanceWay3End + distanceWay2Way3 + distanceWay1Way2 + distanceStartWay1;
    cout << "Total Distance through way points is " << distanceTotal << endl;
}
