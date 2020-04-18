# RouteDistanceCalculator
## Overview
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

## Setup
### Mac/Linux
1. Install the GNU C++ Compiler using yum or apt or homebrew installer you use
```bash
sudo apt install gcc
```
2. Open up a terminal. If you have a mac (bash/zsh) will be the default terminal shell. Navigate to your desired directory and clone the repository. You can also download and unzip the repository.
```bash
git clone https://github.com/paulologeh/RouteDistanceCalculator.git
```
### Windows
1. Download @https://www.cygwin.com and select gcc, g++ etc and install.
2. Open up PowerShell or command prompt. Navigate to your desired directory and clone the repository. You can also download and unzip the repository.
```batch
git clone https://github.com/paulologeh/RouteDistanceCalculator.git
```
## Usage
### Mac/Linux
1. Run program in terminal
```bash
./run.sh
```
### Windows
1. Open run.bat or run in powershell/command prompt
```batch
run.bat
```
