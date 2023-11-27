#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <deque>

using std::copy;
using std::sort;
using std::deque;
using std::back_inserter;
using std::inserter;
using std::front_inserter;

void display_di(const deque<int> &di);

int main()
{
	int input, counter;
	deque<int> start{1, 2, 3, 4, 5, 6, 7, 8, 9};
	deque<int> di1, di2, di3;

	copy(start.begin(), start.end(), back_inserter(di1));
	copy(start.begin(), start.end(), inserter(di2, di2.begin()));
	copy(start.begin(), start.end(), front_inserter(di3));

	display_di(start);
	display_di(di1);
	display_di(di2);
	display_di(di3);

	return 0;
}

void display_di(const deque<int> &di)
{
	for (auto &ri : di)
		std::cout << ri << " ";
	std::cout << std::endl;
}