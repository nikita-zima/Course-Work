#pragma once
class Guide : public Tourist {
public:
	Guide() :Tourist() {}
	Guide(const FullName& name, const int& age, const string& gender, string skill) :Tourist(name, age, gender), isInExpedition(false) {
		if (skill == "legs")
		{
			skills.first = make_shared<Mountaineering>();
			skills.second = make_shared<Hike>();

		}
		else
		{
			skills.first = make_shared<Kayaking>();
			skills.second = make_shared<Diving>();
		}
		cout << "\nOh you are expert in " << GetSkills().first << " and " << GetSkills().second << endl;
	}

	bool isGuide()override {
		return true;
	}
	virtual pair<string, string> GetSkills() {
		return make_pair(skills.first->GetType(), skills.second->GetType());
	}
private:
	bool isInExpedition;
	pair< shared_ptr <Activities>, shared_ptr <Activities>> skills;
};
