#pragma once
#include<iostream>
#include"Date.h"
#include"Fullname.h"
using namespace std;
///перед выбором активити вывести на экран всевозможные варианты (GetInfo)
class Activities
{
public:
	Activities() : place(""), duration(0)
	{
		getInfo();
	}
	Activities(string n_place) : place(n_place) {
	}
	virtual bool CheckThePlace(string place_) = 0;
	virtual  int GetDuration() = 0;
	virtual void getInfo() {}
	virtual  string GetType() = 0;
	virtual void Input() = 0;
	virtual bool GEtBool() = 0;
protected:
	int duration;
	string place;
};
class Mountaineering :virtual public Activities
{
public:
	bool f = true;
	Mountaineering(string s) : Activities(s) {
		duration = 10;
	}
	Mountaineering() {
		duration = 10;
	}
	bool GEtBool() override {
		return f;
	}
	void Input() override {
		cout << endl << "INPUT PLACE which  was mentioned higher\n";
	}
	string GetType() override {
		return "Mountaineering";
	}
	void getInfo() override {
		cout << "Mountaineering will take " << duration << " days \n You can go to the : \n" << places << endl;
		printHigh();
	}
	bool CheckThePlace(string place_) override {
		for (auto i : places) {
			if (i == place_)
				return true;
		}
		return false;
	}
	int GetDuration() override {
		return duration;
	}
	void printHigh() const
	{
		for (const auto& i : mountain_high)
		{
			cout << i.first << " height is " << i.second << "meters" << endl;
		}
	}
private:
	vector<string>  places = { "Carpathians", "Alpes" , "Crimean" , "Andes" };
	vector<pair<string, int>> mountain_high = { {"Carpathians",2600},{"Alpes",4800},{"Crimean",1500},{"Andes",5000} };
};
bool operator==(Activities& act1, Activities& act2)
{
	return   act1.GetType() == act2.GetType();
}
class Diving : public Activities
{
public:
	bool f = true;
	Diving() {
		duration = 5;

	}
	Diving(string s) : Activities(s) {
		duration = 5;
	}
	bool GEtBool() override {
		return f;
	}
	void Input() override {
		getInfo();
		cout << endl << "INPUT PLACE which  was mentioned higher\n";
	}
	int GetDuration() override {
		return duration;
	}
	void getInfo() override {
		cout << "Diving will take " << duration << " days \n You can go to the : \n" << oceans << endl;
		printDepth();
	}
	bool CheckThePlace(string place_)override {
		for (auto i : oceans) {
			if (i == place_)
				return true;
		}
		return false;
	}
	string GetType() override {
		return "Diving";
	}
	void printDepth() const
	{
		for (const auto& i : depth)
		{
			cout << i.first << " depth of diving is " << i.second << " meters" << endl;
		}
	}
private:
	vector<string> oceans = { "Pacific" , "Atlantic" , "Indian" };
	vector<pair<string, int>> depth = { {"Pacific",20},{"Atlantic",30},{"Indian", 15} };
};
class Hike : public Activities
{
public:
	bool f = true;
	Hike() {
		duration = 2;

	}
	Hike(string s) : Activities(s) {
		duration = 2;
	}
	bool GEtBool() override {
		return f;
	}
	void Input() override {
		getInfo();
		cout << endl << "INPUT PLACE which  was mentioned higher\n";
	}
	int GetDuration() override {
		return duration;
	}
	void getInfo() override {
		cout << "Hiking will take " << duration << " days \n You can go to the : \n" << places << endl;
		printLenth_of_Path();
	}
	bool CheckThePlace(string place_)override {
		for (auto i : places) {
			if (i == place_)
				return true;
		}
		return false;
	}
	string GetType() override {
		return "Hike";
	}
	void printLenth_of_Path() const
	{
		for (const auto& i : length_of_path)
		{
			cout << i.first << " length of our hike path is " << i.second << " meters" << endl;
		}
	}
private:
	vector<string>places = { "Forest", "Fields" , "Mountains" , "Sea" };
	vector<pair<string, int>>length_of_path = { {"Forest",5000},{"Fields",3000},{"Mountains", 4000},{"Sea",2000} };
};
class Kayaking : public Activities
{
public:
	bool f = true;
	Kayaking() {
		duration = 2;
	}
	Kayaking(string s) : Activities(s) {
		duration = 2;
	}
	bool GEtBool() override {
		return f;
	}
	void Input() override {
		getInfo();
		cout << endl << "INPUT PLACE which  was mentioned higher\n";
	}
	int GetDuration() override {
		return duration;
	}
	void getInfo() override {
		cout << "Kayaking will take " << duration << " days \n You can go to the : \n" << rivers << endl;
		printLength();
	}
	bool CheckThePlace(string place_) override {
		for (auto i : rivers) {
			if (i == place)
				return true;
		}
		return false;
	}
	string GetType() override {
		return "Kayaking";
	}
	void printLength() const
	{
		for (const auto& i : length)
		{
			cout << i.first << " length of our tour is " << i.second << " meters" << endl;
		}
	}
private:
	vector<string>rivers = { "Donau","Dnipro" , "Rein" , "Buh" };
	vector<pair < string, int >>length = { {"Donau",6000}, {"Dnipro",10000}, {"Rein",9000}, {"Buh",8000} };
};
