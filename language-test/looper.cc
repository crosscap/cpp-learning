#include <iostream>

int main()
{
	for (int ix = 0, sum = 0; ix != 100; ++ix) {
		sum += ix;
		std::cout << sum << ((ix + 1) % 10 ? ' ' : '\n');
	}
	std::cout << std::endl;

	return 0;
}