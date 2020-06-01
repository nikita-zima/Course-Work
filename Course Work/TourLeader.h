#pragma once
#include"Tourist.h"
#include<iostream>
#include<vector>
#include<string>
class TourLeader : public Tourist
{
public:
	vector<string> getType()
	{
		return TypeofTrip;
	}
TourLeader(FullName basic_name,
int default_age,
string default_gender): Tourist(){

}
private:
	vector<string> TypeofTrip;
};

