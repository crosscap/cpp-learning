#include <iostream>
#include <string>

using std::string;

char *cat_chars(const char *, const char *);
string cat_string(const string &, const string &);

int main()
{
	char str1[] = "go to ";
	char str2[] = "the world";
	char *str = cat_chars(str1, str2);
	string st1(str1), st2(str2), st(cat_string(st1, st2));

	std::cout << str << std::endl;
	std::cout << st << std::endl;
	delete [] str;

	return 0;
}

char *cat_chars(const char *str1, const char *str2)
{
	int length;
	for (length = 0; *(str1 + length); ++length);
	for (int i = 0; *(str2 + i); ++length, ++i);
	char *str = new char[length];
	for (length = 0; *(str1 + length); ++length)
		str[length] = str1[length];
	for (int i = 0; *(str2 + i); ++length, ++i)
		str[length] = str2[i];
	str[length] = '\0';

	return str;
}

string cat_string(const string &str1, const string &str2)
{
	string str(str1);
	for (int i = 0; i != str2.size(); ++i)
		str.push_back(str2[i]);

	return str;
}