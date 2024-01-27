#include <iostream>

class numbered
{
public:
	numbered() : mysn(now_counter++) {}
	numbered(const numbered &orig) : mysn(now_counter++) {}
	numbered &operator=(const numbered &rhs) {mysn = now_counter++; return *this;}
	int mysn;
private:
	static int now_counter;
};

int numbered::now_counter = 0;

void f2(const numbered &s)
{
	std::cout << s.mysn << std::endl;
}

int main()
{
	numbered a, b = a, c = b;

	f2(a);
	f2(b);
	f2(c);

	return 0;
}