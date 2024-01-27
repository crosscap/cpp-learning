#include <forward_list>
#include <list>
#include <vector>

using std::forward_list;
using std::list;
using std::vector;

void function_vector()
{
	vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto iter = vi.begin();
	while (iter != vi.end()) {
		if (*iter % 2) {
			iter = vi.insert(iter, *iter);
			iter += 2;
		} else
			iter = vi.erase(iter);
	}
}

void function_list()
{
	list<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto iter = vi.begin();
	while (iter != vi.end()) {
		if (*iter % 2) {
			vi.insert(iter, *iter);
			++iter;
		} else
			iter = vi.erase(iter);
	}
}

void function_flist()
{
	forward_list<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto iter = vi.begin(), prev = vi.before_begin();
	while (iter != vi.end()) {
		if (*iter % 2) {
			vi.insert_after(prev, *iter);
			prev = iter++;
		} else {
			iter = vi.erase_after(prev);
		}
	}
}