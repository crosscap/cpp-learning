#include "Sales_data.h"

template <typename T>
int compare(const T &v1, const T &v2);

int main()
{
	Sales_data sd1("go", 10, 10), sd2("val", 20, 7);

	std::cout << compare(sd1, sd2) << std::endl;

	return 0;
}

template <typename T>
int compare(const T &v1, const T &v2)
{
	if (v1 < v2) return -1;
	if (v2 < v1) return 1;
	return 0;
}