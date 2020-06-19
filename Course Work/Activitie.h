#pragma once
#include<iostream>
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
private:
	set<string>  places = { "Carpathians", "Alpes" , "Crimean" , "Andes" };
};
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
private:
	set<string> oceans = { "Pacific" , "Atlantic" , "Indian" };
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
private:
	set<string>places = { "Carpathians", "Alpes" , "Crimean" , "Andes" };
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
private:
	set<string>rivers = { "Donau","Dnipro" , "Rein" , "Buh" };
};
