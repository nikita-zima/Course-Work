#pragma once
using namespace std;
class Tourist
{
public:
	Tourist()
	{
		name = { "","","" };
		age = 0;
		gender = "";
		to_start = { 0,0,0 };
		to_finish = { 0,0,0 };
	}
	Tourist(const FullName& name, const int& age, const string& gender) :name(name), age(age), gender(gender) {}
	Tourist(const FullName& name, const int& age, const string& gender, const Date& start, const Date& finish) : name(name), age(age),
		gender(gender), to_start(start), to_finish(finish)
	{
	}
	void SetInterest(const vector<int>& commands) {
		for (auto i : commands)
		{
			if (i == 1)
			{
				interests.push_back(make_shared<Mountaineering>());
			}
			else if (i == 2)
			{
				interests.push_back(make_shared <Kayaking>());
			}
			else if (i == 3)
			{
				interests.push_back(make_shared <Hike>());
			}
			else if (i == 4)
			{
				interests.push_back(make_shared <Diving>());
			}
			else
			{
				interests.push_back(make_shared<Hike>());
			}
		}
	}
	void SetAge(int age) {
		this->age = age;
	}
	const int GetAge()const {
		return age;
	}
	const Date getStartDate() const
	{
		return to_start;
	}
	const Date getFinishDate() const
	{
		return to_finish;
	}
	const FullName getName() const
	{
		return name;
	}
	const string getGender() const
	{
		return gender;
	}
	bool HasInterest(shared_ptr<Activities> activity)
	{
		return find_if(interests.begin(), interests.end(), [activity](shared_ptr<Activities> act) {return *act == *activity; }) != interests.end();
	}
	void getInterests()
	{
		for (auto i : this->interests)
		{
			cout << i->GetType() << endl;;
		}
	}
protected:
	FullName name;
	int age;
	string gender;
private:
	Date to_start;
	Date to_finish;
	vector<shared_ptr <Activities>> interests;
};

