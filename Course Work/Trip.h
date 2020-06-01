#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Tourist.h"
#include"TourLeader.h"
#include"TourGroup.h"
using namespace std;
class Trip : virtual public TourGroup
{
public:

	
private:
	vector<Tourist> group;
	string type_of_trip;
	string place;
	Date to_start;
	Date to_finish;
};
class Mountaineering: virtual public Trip
{

};
class Diving: virtual public Trip
{

};
class Hike: virtual public Trip
{

};
class Kayaking: virtual public Trip
{

};

