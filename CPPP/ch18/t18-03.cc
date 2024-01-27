#include <fstream>
#include <vector>

using std::ifstream;
using std::vector;

void exercise_solution1(int *b, int *e)
{
	vector<int> v(b, e);
	int *p = new int[v.size()];
	try {
		ifstream in("ints");
		// 发生异常
	} catch (...) {
		delete[] p;
	}
}

struct Ints {
public:
	Ints(size_t sz)
		: p(new int[sz]) { }
	~Ints()
	{
		if (p) delete[] p;
	}

private:
	int *p;
};

void exercise_solution2(int *b, int *e)
{
	vector<int> v(b, e);
	Ints p(v.size());
	ifstream in("ints");
	// 发生异常
}