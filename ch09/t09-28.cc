#include <forward_list>
#include <string>

using std::forward_list;
using std::string;

void insert_s2_behind_s1(forward_list<string> fls, string s1, string s2)
{
	auto prev = fls.before_begin(), curr = fls.begin(), end = fls.end();

	while (curr != end) {
		if (*curr == s1) {
			fls.insert_after(curr, s2);
			return;
		} else {
			prev = curr;
			++curr;
		}
	}
	fls.insert_after(prev, s2);
}