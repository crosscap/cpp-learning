#include <tuple>

int main()
{
	std::tuple<int, int, int> threeI{10, 20, 30};
	auto threeI2 = std::make_tuple(10, 20, 30);

	return 0;
}