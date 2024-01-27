#include <iostream>
#include <memory>
#include <string>
#include <vector>

using std::string;
using std::vector;

vector<int> *get_vi();
void get_input(vector<int> *);
void deplay_vi(vector<int> *);

int main()
{
	vector<int> *pvi = get_vi();

	get_input(pvi);
	deplay_vi(pvi);
	delete pvi;
	pvi = nullptr;

	return 0;
}

vector<int> *get_vi()
{
	vector<int> *pvi = new vector<int>;
	return pvi;
}

void get_input(vector<int> *vi)
{
	int inp;
	while (std::cin >> inp) {
		vi->push_back(inp);
	}
}

void deplay_vi(vector<int> *vi)
{
	for (auto &r : *vi) {
		std::cout << r << " ";
	}
	std::cout << std::endl;
}