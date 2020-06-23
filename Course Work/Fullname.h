#pragma once
struct FullName
{
	string surname;
	string name;
	string patronymic;
};
bool operator==(const FullName& lhs, const FullName& rhs)
{
	if (lhs.name == rhs.name) {
		if (lhs.surname == rhs.surname) {
			if (lhs.patronymic == rhs.patronymic)
			{
				return true;
			}
		}
	}
}
ostream& operator<<(ostream& out, const FullName& to_out)
{
	return out << to_out.surname << " " << to_out.name << " " << to_out.patronymic;
}