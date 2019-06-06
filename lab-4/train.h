#include <string>
using namespace std;

class TRAIN
{
public:
	string Name() const { return m_name; }
	int Number() const { return m_number; }
	string Time() const { return m_time; }

	friend istream& operator >>(istream&, TRAIN&);
	friend ostream& operator <<(ostream&, const TRAIN&);

private:
	string m_name; // пункт назначения
	int m_number; // номер поезда
	string m_time; // время отправления
};

std::istream& operator >>(std::istream& in, TRAIN& obj)
{
	in >> obj.m_name;
	in >> obj.m_number;
	in >> obj.m_time;
	return in;
}

std::ostream& operator <<(std::ostream& out, const TRAIN& obj)
{
	out << obj.m_name << ' ';
	out << obj.m_number << ' ';
	out << obj.m_time << ' ';
	return out;
}