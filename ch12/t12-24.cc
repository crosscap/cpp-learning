#include <iostream>
#include <string>

using std::string;

char *get_string_into_chars(const string &);

int main()
{
	string word;
	char *chs;

	std::cin >> word;
	chs = get_string_into_chars(word);
	std::cout << chs << std::endl;
	delete [] chs;

	return 0;
}

char *get_string_into_chars(const string &str)
{
	char *chars = new char[str.size() + 1];
	int length = str.size();
	for (int i = 0; i != length; ++i)
		chars[i] = str[i];
	chars[length] = '\0';
	return chars;
}