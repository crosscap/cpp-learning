#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<unsigned> scores(11, 0);
	unsigned grade;
	auto sob = scores.begin();

	while (cin >> grade) {
		if (grade <= 100)
			++*(sob + (grade/10));
	}

	return 0;
}
