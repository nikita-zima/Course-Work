#include<iostream>
#include<tuple>
#include<vector>
#include<string>
#include<utility>
#include<set>
#include<memory>
#include<iomanip>
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
template<typename T>
ostream& operator<<(ostream& out, const set<T>& s)
{

	for (auto i : s) {
		out << i << "\n";
	}
	return out;
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
	for (const auto& i : to_out)
	{
		out << i << " ";
	}
	return out;
}
#include"Activitie.h"
#include"Tourist.h"
#include"Guide.h"
#include"Group.h"
#include"TravelAgency.h"


//	vector<Tourist*>all_tourists;
Group Mounte("Mountaineering", { 1,1,2020 }, { 10,1,2020 }, { 1,5,2020 }, { 10,5,2020 });
Group Divi("Diving", { 20, 3, 2020 }, { 25,3,2020 }, { 20,8,2020 }, { 25,8,2020 });
Group KA("Kayaking", { 1, 1, 2020 }, { 10,1,2020 }, { 1,5,2020 }, { 10,5,2020 });
Group Hi("Hike", { 7, 2, 2020 }, { 9,2,2020 }, { 13,10,2020 }, { 15,10,2020 });
vector<Group>gr = { Mounte,Divi, KA,Hi };


void AddtoVEctorByInterest(const string& s, Tourist& tour) {
	if (s == "Mountaineering") {
		gr[0].AddtoGroup(tour);
	}
	else if (s == "Diving") {
		gr[1].AddtoGroup(tour);
	}
	else if (s == "Kayaking") {
		gr[2].AddtoGroup(tour);
	}
	else if (s == "Hike") {
		gr[3].AddtoGroup(tour);
	}
}
void MenuFunction()
{
	cout << "Enter '0' to exit the program\n";
	cout << "Enter '1' to hire new guides\n";
	cout << "Enter '2' to input information about tourists\n";
	cout << "Enter '3' to create new group\n";
}
vector<Guide>v_g;
int main() {
	cout << "Welcome to the program!\n";
	cout << "First of all you need to hire new guides\n";
	int var;
	do {
		MenuFunction();
		cin >> var;
		if (var == 0)
		{
			cout << "Have a nice day\n";
			break;
		}
		if (var == 1) {
			cout << "Hiring guides : \n";//добрый день , босс , нам нужно нанять гидов , сколько мы можем ввести
			cout << "Inpur amount of guides , that you can take\n";
			int in;
			cin >> in;
			Guide new_one;
			for (int i = 0; i < in; i++) {
				cout << "Input guide fullname\n";
				cout << "name->patromunic->surname\n";
				FullName name;
				cin >> name.name >> name.patronymic >> name.surname;
				cout << "Then age\n";
				int age;
				do {
					cin >> age;
					if (age < 10)
					{
						cout << "Sorry, but guide have not enough experiense\n";
					}
					else if (age > 80)
					{
						cout << "Sorry, guide is too old\n";
						cout << "Eneter new age\n";
					}
				} while (age > 80 || age < 20);
				cout << "And now fender(male or female)\n";
				string gender;
				do {
					cin >> gender;
					if (gender != "male" && gender != "female")
					{
						cout << "Unknown gender, please try again\n";
					}
				} while (gender != "male" && gender != "female");
				cout << " Input your best bodypart : \n";
				string s_in;
				cin >> s_in;
				new_one = Guide(name, age, gender, s_in);
				v_g.push_back(new_one);
				cout << "size  - " << v_g.size() << endl;
			}
		}
		if (var == 2) {
			Tourist tt;
			string command;
			cout << "Now let`s add tourist if they interested in our agency\n";
			do {
				cout << "Enter 'Add' to add new toursit and 'Stop' to stop\n";
				cin >> command;
				if (command == "Add") {
					cout << "There are 4 types of holidays here : \n1.Mountaineering\n2.Diving\n3.Kayaking\n4.Hike\n";
					int n;
					cin >> n;
					string input;
					switch (n)
					{
					case 1:
						input = "Mountaineering";
						break;
					case 2:
						input = "Diving";
						break;
					case 3:
						input = "Kayaking";
						break;
					case 4:
						input = "Hike";
						break;

					default:
						break;
					}
					cout << "Enter tourist full name\n";
					cout << "name->patronymic->surname\n";
					FullName name;
					cin >> name.name >> name.patronymic >> name.surname;
					cout << "Enter his age\n";
					int age;
					do {
						cin >> age;
						if (age > 80)
						{
							cout << "We are sorry, but person is too old for active trips\n";
						}
						else if (age < 10)
						{
							cout << "We are sorry, but person is too young\n";
						}
					} while (age > 80 || age < 10);
					string gender;
					cout << "And now gender(male or female)\n";
					do {
						cin >> gender;
						if (gender != "male" && gender != "female")
						{
							cout << "Unkbown gender, please try again\n";
						}
					} while (gender != "male" && gender != "female");
					Tourist tour(name, age, gender);
					tt = tour;
					tt.SetInterest(input);
					if (tt.SetPlace())
					{
						for (auto i : gr)
						{
							if (tt.getInterests() == i.getNick())
							{
								cout << "Chose date that is good for you : \n";
								i.PrintSrokes();
								int x;
								cin >> x;
								tt.SetDate(i.GetDatesByIdx(x));
								tt.PrintInfoAboutTrip();
								cout << endl;
							}
						}
						AddtoVEctorByInterest(tt.getInterests(), tt);
					}
					else {
						cout << "\nWe can't find  any trip for you\n";
					}
					for (auto i : gr) {
						i.CheckTheGroup();
					}
				}
				else if (command == "Stop")
				{
					break;
				}
				else
				{
					cout << "Invalid data, please try again\n";
				}
			} while (command != "Stop");
		}
		if (var == 3)
		{
			gr[0].SetPLaceofTrip();
			cout << "Most of people desided to go to: \n";
			for (auto i : gr)
			{
				i.CheckTheGroup();
			}
		}
	}while (var != 1 || var != 2||var!=3);
	return 0;
	//придумать минимум и максимум с которым те или ииные отправляются в походы
}