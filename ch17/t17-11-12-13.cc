#include <bitset>

using std::bitset;

struct bits
{
	int answers;
	void set(int, bool = true);
	bool get(int);
};

void bits::set(int num, bool ans)
{
	if (ans)
		answers |= (1) << num;
	else
		answers &= ~((1) << num);
}

bool bits::get(int num)
{
	int checker = answers & ((1) << num);
	return checker ? true : false;
}

bits answers{53};

bool check_answer(int num, bool answer)
{
	return (answers.get(num) == answer) ? true : false;
}

void set_answer(int num, bool answer)
{
	answers.set(num, answer);
}