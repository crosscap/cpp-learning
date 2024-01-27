#include <bitset>

using std::bitset;

int main()
{
	bitset<32> bitvec("1000000010000100101110");
	bitset<32> bitvec2;

	bitvec2.set(1);
	bitvec2.set(2);
	bitvec2.set(3);
	bitvec2.set(5);
	bitvec2.set(8);
	bitvec2.set(13);
	bitvec2.set(21);

	return 0;
}