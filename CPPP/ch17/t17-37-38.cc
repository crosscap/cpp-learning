#include <iostream>
#include <fstream>

#define MAXSIZE 60

using std::istream;
using std::ostream;
using std::ifstream;
using std::cout;

void iostm37()
{
	ifstream infile("storyDataFile.txt");
	char str[MAXSIZE + 1];
	int sum = 0;

	while (!infile.eof()) {
		infile.getline(str, MAXSIZE + 1, '\n');
		if (str[0] != '\0')
			sum += infile.gcount();
		// std::cout << str << " " << sum << std::endl;
		if (!infile.good())
			if (infile.gcount() == MAXSIZE)
				infile.clear();
			else
				break;
	}
	cout << sum << std::endl;
}

void iostm38()
{
	ifstream infile("storyDataFile.txt");
	char str[MAXSIZE + 1];

	while (!infile.eof()) {
		infile.getline(str, MAXSIZE + 1, '\n');
		cout << str;
		if (!infile.good())
			if (infile.gcount() == MAXSIZE)
				infile.clear();
			else
				break;
		else
			cout << std::endl;
	}
}

int main()
{
	iostm38();
	return 0;
}