#pragma once
class Guide : public Tourist {
public:
	Guide() :Tourist() {}
	Guide(const FullName& name, const int& age, const string& gender, string skill) :Tourist(name, age, gender) {
		if (skill == "body")
		{
			this->skill = make_shared<Mountaineering>();
		}
		else if (skill == "maps")
		{
			this->skill = make_shared<Hike>();
		}
		else if (skill == "arms")
		{
			this->skill = make_shared<Kayaking>();
		}
		else if (skill == "dive")
		{
			this->skill = make_shared<Diving>();
		}
		cout << "\nYou are owr new guide in: " << printSkill() << endl;
	}
	shared_ptr<Activities> getSkill() const
	{
		return this->skill;
	}
	string printSkill()
	{
		return this->skill->GetType();
	}
private:
	shared_ptr <Activities> skill;
};
