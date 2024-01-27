#include <iostream>
#include <vector>

using std::vector;

void show_first_elem(vector<int> vi)
{
	// auto &sub = vi[0];
	auto &at = vi.at(0);
	auto &front = vi.front();
	auto beg = vi.begin();

	// std::cout << sub << std::endl;
	std::cout << at << std::endl;
	std::cout << front << std::endl;
	std::cout << *beg << std::endl;
}

int main()
{
	vector<int> vi;

	show_first_elem(vi);

	return 0;
}