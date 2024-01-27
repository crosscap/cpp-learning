#include <cstring>
#include <iostream>
#include <string>

#define MAXSIZE 10

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	char s0[MAXSIZE] = "hello", s1[MAXSIZE] = "world", s2[MAXSIZE * 2] = {};

	strcpy(s2, s0);
	strcat(s2, " ");
	strcat(s2, s1);
	printf("%s", s2);
	return 0;
}