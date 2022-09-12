#include <iostream>
#include <cstring>
using namespace std;
class String
{
public:
	String(const char *);
	String();
	String(const String &);
	~String();
	String operator+(String &);
	bool operator<(String);
	friend istream &operator>>(istream &in, String &);
	friend ostream &operator<<(ostream &out, String &);
	String operator()(int, int);
	String &operator=(const String &);

private:
	char *name;
};
String::String(const char *s)
{
	name = new char[strlen(s) + 1];
	strcpy(name, s);
}
String::String()
{
	name = NULL;
}
String::String(const String &a)
{
	name = new char[strlen(a.name) + 1];
	strcpy(name, a.name);
}
String::~String()
{
	if (name != NULL)
		delete[] name;
}
String String::operator+(String &a)
{
	String temp;
	temp.name = new char[strlen(name) + strlen(a.name) + 1]();
	strcat(temp.name, this->name);
	strcat(temp.name, a.name);
	return temp;
}
bool String::operator<(String a)
{
	if (strlen(name) < strlen(a.name))
		return 1;
	else
		return 0;
}
istream &operator>>(istream &in, String &a)
{
	a.name = new char[100];
	in >> a.name;
	a.name[strlen(a.name)] = '\0';
	return in;
}
ostream &operator<<(ostream &out, String &a)
{
	out << a.name;
	return out;
}
String String::operator()(int a, int b)
{
	String s;
	int l = b - a + 1;
	s.name = new char[l + 1]();
	int n;
	for (n = 0; n < l; n++)
	{
		s.name[n] = this->name[a++];
	}
	return s;
}
String &String::operator=(const String &a)
{
	name = new char[strlen(a.name) + 1];
	strcpy(name, a.name);
	return *this;
}
int main()
{
	String x("pocket"), y, m, n;
	cin >> y;
	m = x + y;
	n = m(4, 6);
	cout << m << endl;
	cout << n << endl;
	return 0;
}