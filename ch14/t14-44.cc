#include <functional>
#include <map>
#include <string>

using std::function;
using std::map;
using std::string;

int add(int i, int j)
{
	return i + j;
}

float add(float i, float j)
{
	return i + j;
}

int sub(int i, int j)
{
	return i - j;
}

float sub(float i, float j)
{
	return i - j;
}

int power(int i, int j)
{
	int answer = i;
	for (int flag = j - 1; flag > 0; --flag)
		answer *= i;
	return answer;
}

auto mod = [](int i, int j) { return i % j; };

struct divide {
	int operator()(int i, int j) { return i / j; }
};

int main()
{
	int (*fp)(int, int) = sub;
	map<string, function<int(int, int)>> binop{
		{"+", [](int i, int j) { return add(i, j); }}, // 消除二义性
		{"-", fp},                                     // 消除二义性
		{"*", [](int i, int j) { return i * j; }},
		{"/", divide()},
		{"%", mod},
		{"^^", power},
		{"=", std::equal_to<int>()}};

	return 0;
}
