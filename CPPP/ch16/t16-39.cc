#include <iostream>
#include <string>

template <typename T>
int compare(const T &v1, const T &v2)
{
	if (v1 < v2) return -1;
	if (v2 < v1) return 1;
	return 0;
}

int main()
{
	std::string str1 = "go", str2 = "val";
	std::cout << compare<std::string>(str1, str2) << std::endl;
	return 0;
}