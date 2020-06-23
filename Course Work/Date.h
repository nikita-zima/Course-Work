#pragma once
struct Date {
	int day;
	int month;
	int year;
};
bool operator!=(const Date& lhs, const Date& rhs)
{
	if (lhs.day != rhs.day)
	{
		return false;
	}
	else if (lhs.month != rhs.month)
	{
		return false;
	}
	else if (lhs.year != rhs.year)
	{
		return false;
	}
}
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
ostream& operator<<(ostream& out, const Date& to_out)
{
	return out << to_out.day << "." << to_out.month << "." << to_out.year;
}