#pragma once
class TourGroup
{
public:
	TourGroup MakeGroup(vector<TourLeader>& guides, vector<Tourist> group)
	{
		int counter;
		TourGroup made;
		vector<Tourist> people;
		int min, max;
		while (min > max) {
			cout << "Input min and max size of tour group\n";
			cin >> min >> max;
			if (min > max)
			{
				cout << "First number must be less then second\n";
			}
		}
		Date start, finish;
		while (finish < start)
		{
			cout << "Enter date you want to plan trip(to start and to finish)\n ";
			cin >> start.day >> start.month >> start.year;
			cin >> finish.day >> finish.month >> finish.year;
			if (finish < start)
			{
				cout << "Input stat date at first\n";
			}
		}
		string type;
		cout << "Enter type of tourism you want to go('Hike','Mountaineering','Kayaking','Diving')\n";
		while (type != "Hike" || type != "Mountaineering" || type != "Kayakin" || type != "Diving")
		{
			cin >> type;
			if (type != "Hike" || type != "Mountaineering" || type != "Kayakin" || type != "Diving")
			{
				cout << "Incorrect data type,please try again\n";
			}
		}
		while (min <= counter && max >= counter) {
			for (auto i : group)
			{
				if (i.getStartDate() == start) {
					if (i.getFinishDate() == finish) {
						for (auto q : i.getInterests())
						{
							if (q == type)
							{
								counter++;
								people.push_back(i);
							}
						}
					}
				}
			}
		}
		TourLeader new_guide;
		for (auto i : guides)
		{
			for (auto q : i.getType())
			{
				if (q == type)
				{
					new_guide = i;
					break;
				}
			}
		}
		made.main_guide = new_guide;
		made.basic_group = people;
		return made;
	}
private:
	TourLeader main_guide;
	vector<Tourist> basic_group;
};

