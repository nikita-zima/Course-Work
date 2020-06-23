#pragma once
#include<algorithm>
class Group {
public:
	Group() {
	}
	Group(shared_ptr < Activities> activity, vector < shared_ptr<Tourist>> group, Guide guide)
	{
		this->activity = activity;
		this->guide = guide;
		this->group = group;
	}
	bool makeGroup(shared_ptr < Activities> activity, vector < shared_ptr<Tourist>> group, vector<Guide> guides)
	{
		bool f = true;
		Guide guide;
		Date to_start;
		Date to_finish;
		int counter;
		vector < shared_ptr<Tourist>> by_inter;
		multiset<Date> start_dates;
		multiset<Date>finish_dates;
		vector<shared_ptr<Tourist>> result;
		int c = 0;
		for (auto i : group)
		{
			if (i->HasInterest(activity)) {
				c++;
				this->activity = activity;
				by_inter.push_back(i);
			}
			else if (c == 0) {
				cout << "No one interested in such type of trip\n";
				return false;
			}
		}
		for (auto i : by_inter)
		{
			Date s, f;
			s = i->getStartDate();
			f = i->getFinishDate();
			start_dates.insert(s);
			finish_dates.insert(f);
		}
		set<Date> repeats_start;
		multiset<Date>::iterator start = start_dates.begin();
		for (; start != start_dates.end(); ++start)
		{
			if (repeats_start.count(*start) > 0) continue;
			else {
				if ((counter = start_dates.count(*start)) > 1)
				{
					repeats_start.insert(*start);
				}
			}
		}
		for (auto i : repeats_start)
		{
			this->start = i;
			break;
		}
		multiset<Date>::iterator finish = finish_dates.begin();
		int counter2;
		set<Date> repeats_finish;
		for (; finish != finish_dates.end(); ++finish)
		{
			if (repeats_finish.count(*finish) > 0) continue;
			else {
				if ((counter2 = finish_dates.count(*finish)) > 1)
				{
					repeats_finish.insert(*finish);
				}
			}
		}
		for (auto i : repeats_finish)
		{
			this->finish = i;
			break;
		}
		for (auto i : by_inter)
		{
			if (i->getStartDate() != this->start && i->getFinishDate() != this->finish)
			{
				result.push_back(i);
			}
			this->group = result;
		}
		for (auto i : guides)
		{
			if (i.getSkill() != this->activity)
			{
				guide = i;
				this->guide = guide;
				cout << "Guide was found\n";
				break;
			}
			else {
				cout << "There are no guides with such skill\n";
				return false;
			}
		}
		cout << "The group was made\n";
		return true;
	}
	void PrintGroup()
	{
		cout << "This group goes " << this->activity->GetType() << endl;
		cout << "They start their trip at " << this->start << " and finish at " << this->finish << endl;
		cout << "Group is: " << endl;
		for (auto i : group)
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
		}
		cout << "Their guide will be \n";
		cout << "Guide name is " << guide.getName() << endl;
		cout << "Age is " << guide.GetAge() << endl;
		cout << "Gender is " << guide.getGender() << endl;
		cout << "Can guide trips in \n" << guide.printSkill() << endl;
		for (int i = 0; i < 50; i++)
		{
			cout << '-';
		}
	}
private:
	shared_ptr<Activities> activity;
	vector < shared_ptr<Tourist>> group;
	Guide guide;
	Date start;
	Date finish;
};