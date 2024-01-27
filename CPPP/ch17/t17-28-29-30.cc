#include <iostream>
#include <random>
#include <vector>
#include <ctime>

using std::cin;
using std::cout;
using std::default_random_engine;
using std::endl;
using std::uniform_int_distribution;
using std::vector;
using std::time;

vector<unsigned> randVec28()
{
	static default_random_engine e(time(0));
	static uniform_int_distribution<unsigned> u(0, 9);
	vector<unsigned> ret;
	for (size_t i = 0; i < 100; ++i)
		ret.push_back(u(e));
	return ret;
}

vector<unsigned> randVec29()
{
	int seed;
	cout << "Please enter a number to be a seed: ";
	cin >> seed;
	static default_random_engine e(seed);
	static uniform_int_distribution<unsigned> u(0, 9);
	vector<unsigned> ret;
	for (size_t i = 0; i < 100; ++i)
		ret.push_back(u(e));
	return ret;
}

vector<unsigned> randVec30()
{
	int seed, max, min;
	cout << "Please enter a number to be a seed: ";
	cin >> seed;
	cout << "Please enter tow numbers to be min and max: ";
	cin >> min >> max;
	static default_random_engine e(seed);
	static uniform_int_distribution<unsigned> u(min, max);
	vector<unsigned> ret;
	for (size_t i = 0; i < 100; ++i)
		ret.push_back(u(e));
	return ret;
}

int main()
{
	// do other function here
	return 0;
}