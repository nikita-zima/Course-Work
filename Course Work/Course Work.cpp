#include<iostream>
#include<tuple>
#include<vector>
#include<string>
using namespace std;
struct Date {
	int day;
	int month;
	int year;
};
struct FullName
{
	string surname;
	string name;
	string patronymic;
};
bool operator ==(const Date& lhs, const Date& rhs)
{
	if (lhs.day == rhs.day)
		if (lhs.month == rhs.month)
			if (lhs.year == rhs.year)
				return true;
}
bool operator<(const Date& lhs, const Date& rhs)
{
	return tie(lhs.year, lhs.month, lhs.day) <
		tie(rhs.year, rhs.month, rhs.day);
}
bool operator==(const FullName& lhs, const FullName& rhs)
{
	if (lhs.name == rhs.name) {
		if (lhs.surname == rhs.surname) {
			if (lhs.patronymic == rhs.patronymic)
			{
				return true;
			}
		}
	}
}
ostream& operator<<(ostream& out, const Date& to_out)
{
	return out << to_out.day << "." << to_out.month << "." << to_out.year;
}
ostream& operator<<(ostream& out, const FullName& to_out)
{
	return out << to_out.surname << " " << to_out.name << " " << to_out.patronymic;
}
template <typename C>
ostream& operator<<(ostream& out, const vector<C>& to_out)
{
	for (const auto &i : to_out)
	{
		 out << i <<" ";
	}
	return out;
}
#include"Tourist.h"
#include"Trip.h"
#include"TourLeader.h"
#include"TourGroup.h"


void InputInformation(vector<Tourist>& basic_vec)
{
	Tourist basic;
	FullName to_edit;
	cout << "Please input tourist full name(surname,name,patronymic)\n";
	cin >>to_edit.surname >>to_edit.name >>to_edit.patronymic;
	cout << "Next enter tourist age in years\n";
	int age;
	cin >> age;
	cout << "Next input gender(male or female)\n";
	string gender;
	do {
		cin >> gender;
		if (gender != "male" && gender != "female")
		{
			cout << "Unknown gender, please try again\n";
		}
	} while (gender != "male" && gender != "female");
	cout << "Now enter two dates, when tourist plan to start and then when finish his trip\n";
	Date start, finish;
	do {
		cin >> start.day >> start.month >> start.year
			>> finish.day >> finish.month >> finish.year;
		if (finish < start)
		{
			cout << "You must input start date at first\n";
		}
	} while (finish < start);
	cout << "Input some of torist interests(write 'Stop' to stop entering information\n";
	vector<string>interests;
	string word;
	while (word != "Stop")
	{
		cin >> word;
		if (word == "Stop")
		{
			break;
		}
		interests.push_back(word);
	}
	basic.setNew(to_edit, age, gender, start, finish, interests);
	basic_vec.push_back(basic);
}
void MenuFuntcion()
{
	cout << "Enter '0' to exit\n";
	cout << "Enter '1' to input information about tourists\n";
	cout << "Enter '2' to edit information about tourists\n";
	cout << "Enter '3' to crete a new group leader\n";
	cout << "Enter '4' to input some activity types\n";
	cout << "Enter '5' to create new torist group\n";
}
int main()
{
	vector<Tourist> basic_vec;
	vector<TourLeader> guides;
	int command;
	cout << "Welcome to the program!\n";
	do {
		MenuFuntcion();
		cin >> command;
		if (command == 0)
		{
			cout << "Thank you,have a nice day!";
			return 0;
		}
		else if (command == 1)
		{
			string var;
			while(var!="Stop")
			{
			   InputInformation(basic_vec);
			   cout << "Write 'Stop' if you want to stop enter information\n";
			   cout << "Write anything else to add new person\n";
			   cin >> var;
			}
		}
		else if (command == 2)
		{
			Tourist man;
			FullName to_find;
			cout << "Please input surname name and patronymic of tourist to find\n";
			cin >> to_find.surname >> to_find.name >> to_find.patronymic;
			man.Edit(basic_vec, to_find);
			
		}
		else if (command == 3)
		{

		}
		else if (command == 4)
		{

		}
		else if (command == 5)
		{

		}
		else
		{
			cout << "Invalid datatype,please try again\n";
		}
		} while (/*command != 0 ||*/ command != 1 || command != 2 || command != 3 || command != 4||command!=5);
	return 0;
}