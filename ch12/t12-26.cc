#include <iostream>
#include <memory>
#include <string>

using std::string;

int main()
{
	int n = 10;
	std::allocator<string> alloc_str;
	auto const p = alloc_str.allocate(n);
	string *q = p;
	string s;

	while (std::cin >> s && q != p + n)
		alloc_str.construct(q++, s);
	const size_t size = q - p;
	while (q != p)
		alloc_str.destroy(--q);
	alloc_str.deallocate(p, n);

	return 0;
}