#pragma once
using namespace std;
class Tourist
{
public:
	Tourist()
	{
		basic_name = { "","","" };
		default_age = 0;
		default_gender = "";
		to_start = { 0,0,0 };
		to_finish = { 0,0,0 };
	}
	Tourist(const FullName& name, const int& age, const string& gender) : basic_name(name), default_age(age),
		default_gender(gender){
	}
	bool SetPlace() {
		default_intersest->getInfo();
		default_intersest->Input();
		string s;
		cin >> s;
		if (default_intersest->CheckThePlace(s))
		{
			place = s;
			return true;
		}
		else
			cout << "Your input is invalid\n";
		return false;
	}
	void SetDateForEmpty(int plus_date) {

		Date date;
		cout << "\nInput date , when you want to go there\nday->month->year\n";
		cin >> date.day >> date.month >> date.year;
		to_start = date;
		Date new_date = { date.day + plus_date , date.month,date.year };
		to_finish = new_date;
		cout << " \nYou go there " << date << " and back - " << new_date << endl;
	}
	void SetDate(pair<Date, Date> s_date) {

		to_start = s_date.first;
		to_finish = s_date.second;
	}
	pair<Date, Date> GetDate() {
		return make_pair(to_start, to_finish);
	}
	bool CheckThePLace(string s) {
		return  default_intersest->CheckThePlace(s);
	}
	string GetPLace() {
		return place;
	}
	void PrintInfoAboutTrip() {
		cout << "That's " << getName() << " who is " << GetAge() << "\nInteres - " << getInterests() << " and goes to " << GetPLace() << " for " << getDurationOfHisweekends() << " days :  \nFrom " << GetDate().first << " to " << GetDate().second << endl;
	}
	int getDurationOfHisweekends() {

		return default_intersest->GetDuration();
	}
	void SetInterest(const  string& str) {

		if (str == "Mountaineering") {

			default_intersest = make_shared<Mountaineering>();
		}
		else if (str == "Hike") {

			default_intersest = make_shared<Hike>();
		}
		else if (str == "Kayaking") {

			default_intersest = make_shared<Kayaking>();
		}
		else if (str == "Diving") {

			default_intersest = make_shared<Diving>();
		}
	}
	virtual bool isGuide() {
		return false;
	}
	void SetAge(int age) {
		default_age = age;
	}
	const int GetAge()const {
		return default_age;
	}
	Date getStartDate()
	{
		return to_start;
	}
	Date getFinishDate()
	{
		return to_finish;
	}
	string getInterests()//формируем по этому критерию группу
	{
		return default_intersest->GetType();
	}
	FullName getName()
	{
		return basic_name;
	}
	void setName()
	{
		cout << "Enter name(surname,name,patronymic)\n";
		FullName name;
		cin >> name.surname >> name.name >> name.patronymic;
		basic_name = name;
	}
	void setAge()
	{
		cout << "Enter new age\n";
		int age;
		cin >> age;
		default_age = age;
	}
	void setGender()
	{
		cout << "Input gender 'male' or 'female'\n";
		string gender;
		cin >> gender;
		default_gender = gender;
	}
protected:
	FullName basic_name;
	int default_age;
	string default_gender;
	Date to_start;
	Date to_finish;
private:
	shared_ptr <Activities> default_intersest;
	string place;
};

