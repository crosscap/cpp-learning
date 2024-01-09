#include <cmath>
#include <ctime>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using std::bernoulli_distribution;
using std::cin;
using std::cout;
using std::default_random_engine;
using std::endl;
using std::lround;
using std::normal_distribution;
using std::string;
using std::time;
using std::uniform_int_distribution;
using std::uniform_real_distribution;
using std::vector;

void basic_rand()
{
	uniform_int_distribution<unsigned> u(0, 9);
	default_random_engine e;
	for (size_t i = 0; i < 10; ++i)
		cout << u(e) << " ";
	cout << endl;
}

vector<unsigned> bad_randVec()
{
	default_random_engine e;
	uniform_int_distribution<unsigned> u(0, 9);
	vector<unsigned> ret;
	for (size_t i = 0; i < 100; ++i)
		ret.push_back(u(e));
	return ret;
}

vector<unsigned> good_randVec()
{
	static default_random_engine e(time(0));
	static uniform_int_distribution<unsigned> u(0, 9);
	vector<unsigned> ret;
	for (size_t i = 0; i < 100; ++i)
		ret.push_back(u(e));
	return ret;
}

void uniform_d()
{
	default_random_engine e;
	uniform_real_distribution<> u(0, 1);
	for (size_t i = 0; i < 10; ++i)
		cout << u(e) << " ";
	cout << endl;
}

void normal_d()
{
	default_random_engine e;
	normal_distribution<> n(4, 1.5);
	vector<unsigned> vals(9);
	for (size_t i = 0; i < 200; ++i) {
		unsigned v = lround(n(e));
		if (v < vals.size())
			++vals[v];
	}
	for (size_t i = 0; i < vals.size(); ++i)
		cout << i << ": " << string(vals[i], '*') << endl;
	cout << endl;
}

bool play(bool)
{
	return true;
}

void get_first()
{
	string resp;
	default_random_engine e;
	bernoulli_distribution b;
	do {
		bool first = b(e);
		cout << (first ? "We go first" : "You get to go first") << endl;
		cout << ((play(first)) ? "Sorry, you lost" : "congrats, you won") << endl;
		cout << "play again? Enter 'yes' or 'no" << endl;
	} while (cin >> resp && resp[0] != 'y');
}

int main()
{
	normal_d();
	return 0;
}