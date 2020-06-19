#pragma once
class Group {
public:
	Group() {
	}
	Group(const string& nick, Date a, Date b, Date c, Date d) : nickname(nick) {
		res.push_back(make_pair(a, b));
		res.push_back(make_pair(c, d));
	}
	void AddtoGroup(Tourist& tour) {
		if (group.empty())
			start_and_end = tour.GetDate();
		group.push_back(tour);
	}
	void PrintSrokes() {
		int x = 1;
		for (auto i : res) {
			cout << x << ". From " << i.first << " to " << i.second << endl;
			++x;
		}
	}
	const pair<Date, Date> GetDatesByIdx(int idx) {
		if (idx == 1)
			return res[0];
		else
			return res[1];
	}
	void CheckTheGroup() {
		cout << getNick();
		cout << setw(30) << setfill('-'); cout << endl;
		int x = 1;
		if (group.empty())
			cout << "No one wants to go here\n";
		else
		{
			for (auto i : group) {

				cout << "TripMember - " << x << endl;
				i.PrintInfoAboutTrip();
				cout << endl;
				++x;
			}
		}
	}
	const string getNick()const {
		return nickname;
	}
	void PrintDates() {
		cout << "This group goes to " << nickname << " from" << start_and_end.first << " to " << start_and_end.second << endl;
	}
	const pair<Date, Date> GetDates() {
		return start_and_end;
	}
	bool isEmpty() {
		return (group.empty());
	}
	int GEtSize() {
		return  group.size();
	}
	void GetInfoByIdx(int idx) {
		group[idx].PrintInfoAboutTrip();
	}
	void SetPLaceofTrip() {
		set<string>lpaces;
		for (auto i : group) {
			lpaces.insert(i.GetPLace());
		}
		vector<pair<int, string>>result_of;
		for (auto i : lpaces)
		{
			int counter = 0;
			for (auto j : group) {
				if (j.GetPLace() == i)
					counter++;
			}
			result_of.push_back(make_pair(counter, i));
		}
	}
private:
	pair<Date, Date> start_and_end;
	vector<pair<Date, Date>> res;
	string nickname;//== интерес
	vector<Tourist>group;
	string place;
};

