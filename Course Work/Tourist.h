#pragma once
#include"TourGroup.h"
using namespace std;
class Tourist: virtual public TourGroup
{
public:
	void setNew(const FullName& name,const int& age,const string& gender,const Date& start,const Date& finish,const vector<string>& interests)
	{
		basic_name = name;
		default_age = age;
		default_gender = gender;
		to_start = start;
		to_finish = finish;
		default_intersest = interests;
	}
	void Edit(vector<Tourist>& basic,const FullName& name)
	{
		string var;
		for (auto i : basic) {
			if (i.basic_name == name)
			{
				cout << "Name is " << i.basic_name<<endl;
				cout << "Age is " << i.default_age<<endl;
				cout << "Gender is " << i.default_gender<<endl;
				cout << "Want start trip at " << i.to_start<<endl;
				cout << "Want end trip at " << i.to_finish<<endl;
				cout << "His ineterests are:" <<i.default_intersest<< endl;
				while (var != "Stop")
				{
					cout << "Enter type of information you want to edit(Age, Gender,Date,Interests)\n";
					cout << "Write 'Stop' to stop\n";
					cin >> var;
					if (var == "Age") {
						int new_age;
						cout << "Enter new age: ";
						cin >> new_age;
						i.default_age = new_age;
					}
					if (var == "Gender")
					{
						string gender;
						cout << "Enter new gender: ";
						do {
							cin >> gender;
							if (gender != "male" && gender != "female")
							{
								cout << "Unknown gender, please try again\n";
							}
						} while (gender != "male" && gender != "female");
						i.default_gender = gender;
					}
					if (var == "Date")
					{
						Date new_start, new_finish;
						cout << "New to start trip date: ";
						do {
							cin >> new_start.day >> new_start.month >> new_start.year;
							cout << endl << "New to finish trip date: ";
							cin >> new_finish.day >> new_finish.month >> new_finish.year;
							if (new_finish < new_start)
							{
								cout << "Please input start trip date at first\n";
							}
						} while (new_finish < new_start);
						i.to_start = new_start;
						i.to_finish = new_finish;
					}
					if (var == "Interests")
					{
						vector<string> new_vec;
						string new_inter;
						cout << "Enter new interests('Stop' to stop): ";
						while (new_inter != "Stop")
						{
							cin >> new_inter;
							new_vec.push_back(new_inter);
						}
						i.default_intersest = new_vec;
					}
				}
			}
		}
	}
	Date getStartDate()
	{
		return to_start;
	}
	Date getFinishDate()
	{
		return to_finish;
	}
	vector<string> getInterests()
	{
		return default_intersest;
	}
private:
	FullName basic_name;
	int default_age;
	string default_gender;
	Date to_start;
	Date to_finish;
	vector<string> default_intersest;
};

