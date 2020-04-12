# RouteDistanceCalculator

C++ program that finds distances along a route with cities as start and end points and way points.
The user inputs the names of the cities on the route from the keyboard at runtime.
This includes the start point, the end point and three cities that should be way points.
Distances between cities are calculated using latitude and longitude values for each point. 
The distance that is calculated is the “great circle” distance, using the Haversine formula.
(see http://en.wikipedia.org/wiki/Haversine_formula and http://www.movable-type.co.uk/scripts/latlong.html.4). 
The program inputs the latitude and longitude values for locations of cities from the locDatabase.txt file
The route between the start point and the end point includes three cities input as way points. 
The order of points on the route are: start point, way point 1, way point 2, way point 3, end point.
The program calculates and outputs the distance between each pair of points and the total distance on the route.


## Installation
Clone the repository locally
```bash
https://github.com/paulologeh/RouteDistanceCalculator.git
```
Install dependencies using yum or apt or brew or whichever installer you use
``` bash
yum install gcc-c++
``` 

## Usage
Run the program
``` bash
./run.sh
```
