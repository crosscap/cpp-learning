#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::ifstream;
using std::istream;
using std::string;
using std::vector;

class GetString
{
public:
	GetString(istream &i = cin)
		: is(i) { }

	string operator()();

private:
	istream &is;
	string in;
};

inline string GetString::operator()()
{
	if (!getline(is, in))
		in = "";

	return in;
}

int main()
{
	string line;
	ifstream ifile("input.txt");
	GetString getter(ifile);
	vector<string> vs;

	while (true) {
		line = getter();
		if (line.empty())
			break;
		else
			vs.push_back(line);
	}

	return 0;
}