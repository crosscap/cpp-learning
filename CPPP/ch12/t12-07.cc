#include <iostream>
#include <memory>
#include <string>
#include <vector>

using std::shared_ptr;
using std::string;
using std::vector;

shared_ptr<vector<int>> get_vi();
void get_input(shared_ptr<vector<int>>);
void deplay_vi(shared_ptr<vector<int>>);

int main()
{
	shared_ptr<vector<int>> pvi = get_vi();

	get_input(pvi);
	deplay_vi(pvi);

	return 0;
}

shared_ptr<vector<int>> get_vi()
{
	shared_ptr<vector<int>> pvi = std::make_shared<vector<int>>();
	return pvi;
}

void get_input(shared_ptr<vector<int>> pvi)
{
	int inp;
	while (std::cin >> inp) {
		pvi->push_back(inp);
	}
}

void deplay_vi(shared_ptr<vector<int>> pvi)
{
	for (auto &r : *pvi) {
		std::cout << r << " ";
	}
	std::cout << std::endl;
}