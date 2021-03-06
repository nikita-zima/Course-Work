﻿#include<iostream>
#include<tuple>
#include<vector>
#include<string>
#include<utility>
#include<set>
#include<memory>
#include<iomanip>
using namespace std;
template<typename T>
ostream& operator<<(ostream& out, const set<T>& s)
{

	for (auto i : s) {
		out << i << "\n";
	}
	return out;
}
template <typename C>
ostream& operator<<(ostream& out, const vector<C>& to_out)
{
	for (const auto& i : to_out)
	{
		out << i << " ";
	}
	return out;
}
#include"Date.h"
#include"Fullname.h"
#include"Activitie.h"
#include"Tourist.h"
#include"Guide.h"
#include"Group.h"
using namespace std;

void PrintAll(const vector<shared_ptr<Tourist>>& all)
{
	cout << "All tourists in our base\n";
	for (auto i : all)
	{
		for (int i = 0; i < 50; i++)
		{
			cout << '-';
		}
		cout << endl;
		cout << "Name is " << i->getName() << endl;
		cout << "Age is " << i->GetAge() << endl;
		cout << "Gender is " << i->getGender() << endl;
		cout << "Can start trip at " << i->getStartDate() << " and finish " << i->getFinishDate() << endl;
		cout << "Interests are: \n"; i->getInterests(); cout << endl;
		for (int i = 0; i < 50; i++)
		{
			cout << '-';
		}
		cout << endl;
	}
}
void PrintGuide(const vector<Guide>& guides)
{
	for (auto i : guides)
	{
		for (int i = 0; i < 50; i++)
		{
			cout << '-';
		}
		cout << endl;
		cout << "Guide name is " << i.getName() << endl;
		cout << "Age is " << i.GetAge() << endl;
		cout << "Gender is " << i.getGender() << endl;
		cout << "Can guide trips in \n" << i.printSkill() << endl;
		for (int i = 0; i < 50; i++)
		{
			cout << '-';
		}
		cout << endl;
	}
}
void MenuFunction()
{
	cout << "Enter '0' to exit the program\n";
	cout << "Enter '1' to watch informtion about possible trips\n";
	cout << "Enter '2' to add new tourist\n";
	cout << "Enter '3' to watch information about all toursist\n";
	cout << "Enter '4' to hire a new guide\n";
	cout << "Enter '5' to watch all information about guides\n";
	cout << "Enter '6' to create a new group\n";
	cout << "Enter '7' to watch information about group\n";
	cout << "Enter '8' to change information about tourist by name\n";
}
void info()
{
	cout << "Information about our agency trips\n";
	Mountaineering mount;
	mount.getInfo();
	cout << endl;
	Kayaking k;
	k.getInfo();
	cout << endl;
	Diving d;
	d.getInfo();
	cout << endl;
	Hike h;
	h.getInfo();
	cout << endl;
}
void Changebyname(vector<shared_ptr<Tourist>>& all,const FullName& find)
{
	string var;
	for (auto& i : all)
	{
		if (i->getName() == find)
		{
			cout << "What you want to change(Age,Name,Dates, Gender)\n";
			cin >> var;
			while (true)
			{
				if (var == "Age")
				{
					cout << "Enter new age\n";
					int age;
					cin >> age;
					i->SetAge(age);
					break;
				}
				else if (var == "Name")
				{
					FullName name;
					cout << "Enter new name\n";
					cout << "name->surname->patronymic\n";
					cin >> name.name >> name.surname >> name.patronymic;
					i->setName(name);
					break;
				}
				else if (var == "Dates")
				{
					Date start, finish;
					cout << "Enter new start and finish dates\n";
					cout << "Start\n";
					cin >> start.day >> start.month >> start.year;
					cout << "Finish\n";
					cin >> finish.day >> finish.month >> finish.year;
					i->setNewDates(start, finish);
					break;
				}
				else if(var=="Gender")
				{ 
					string gender;
					do {
						cin >> gender;
						if (gender != "male" && gender != "female")
						{
							cout << "Unknown data,please try again\n";
						}
					} while (gender != "male" && gender != "female");
					i->setGender(gender);
					break;
				}
				else {
					cout << "Wrong command please try again\n";
				}
			}
		}
	}
}
int main() {
	vector<shared_ptr<Tourist>> all;
	vector<Guide> guides;
	Group new_group;
	int com;
	while (true)
	{
		MenuFunction();
		cin >> com;
		if (com == 0)
		{
			cout << "Thank you, have a nice day!\n";
			break;
		}
		else if (com == 1)
		{
			info();
		}
		else if (com == 2)
		{
			string var;
			do {
				cout << "Enter 'Add' to add new tourist, enter 'Stop' to stop\n";
				cin >> var;
				if (var == "Add")
				{
					cout << "Please enter tourist full name\n";
					cout << "Name->surname->patronymic\n";
					FullName name;
					cin >> name.name >> name.surname >> name.patronymic;
					cout << "Then age\n";
					int age;
					cin >> age;
					cout << " Next eneter gender(male or female)\n";
					string gender;
					do {
						cin >> gender;
						if (gender != "male" && gender != "female")
						{
							cout << "Unknown gender, please try again\n";
						}
					} while (gender != "male" && gender != "female");
					vector<int> inter_num;
					int q;
					while (true)
					{
						cout << "Next let`s add tourist`s interests\n";
						cout << "Enter '0' stop, '1' to add Mountaineering, '2' to add Kayaking, 3 to add Hike,4 to add Diving\n";
						cin >> q;
						if (q == 0)
						{
							break;
						}
						else {
							inter_num.push_back(q);
						}
					}
					Date start, finish;
					cout << "And finally enter date when tourist plan to start trip\n";
					cout << "day->month->year\n";
					cin >> start.day >> start.month >> start.year;
					cout << "And finish date\n";
					cout << "day->month->year\n";
					cin >> finish.day >> finish.month >> finish.year;
					Tourist tour(name, age, gender, start, finish);
					tour.SetInterest(inter_num);
					all.push_back(make_shared<Tourist>(tour));
				}
				else
				{
					cout << "Wrong command, please try again\n";
				}
			} while (var != "Stop");
		}
		else if (com == 3)
		{
			PrintAll(all);
		}
		else if (com == 4)
		{
			string var;
			while (true)
			{
				cout << "Write 'Add' to add new guide, write 'Stop' to stop\n";
				cin >> var;
				if (var == "Add")
				{
					cout << "Enter guide full name\n";
					cout << "name->surname->patronymic\n";
					FullName name;
					cin >> name.name >> name.surname >> name.patronymic;
					cout << "Eneter his age\n";
					int age;
					cin >> age;
					cout << "Enter guiides gender\n";
					string gender;
					do {
						cin >> gender;
						if (gender != "male" && gender != "female")
						{
							cout << "Unknown gender, please try again\n";
						}
					} while (gender != "male" && gender != "female");
					cout << "Your skill is(body,maps,arms,dive)\n";
					string skill;
					cin >> skill;
					Guide guide(name, age, gender, skill);
					guides.push_back(guide);

				}
				else if (var == "Stop")
				{
					break;
				}
				else
				{
					cout << "Wrong command,please try again\n";
				}
			}
		}
		else if (com == 5)
		{
			PrintGuide(guides);
		}
		else if (com == 6)
		{
			cout << "Enter which type of trip you want to held(Mountaineering, Kayaking,Hike,Diving)\n";
			string var;
			cin >> var;
			if (var == "Mountaineering")
			{
				new_group.makeGroup(make_shared<Mountaineering>(), all, guides);
			}
			else if (var == "Kayaking")
			{
				new_group.makeGroup(make_shared<Kayaking>(), all, guides);
			}
			else if (var == "Hike")
			{
				new_group.makeGroup(make_shared<Hike>(), all, guides);
			}
			else if (var == "Diving")
			{
				new_group.makeGroup(make_shared<Diving>(), all, guides);
			}
			else {
				cout << "Wrong type, please try again\n";
			}
		}
		else if (com == 7)
		{
			new_group.PrintGroup();
		}
		else if (com == 8)
		{
		    cout << "Enter name of person you want to change\n";
		    FullName to_find;
			cin >> to_find.name >> to_find.surname >> to_find.patronymic;
		    Changebyname(all, to_find);
        }else
		{
			cout << "Wrong data please try again\n";
		}
	}
	return 0;
}