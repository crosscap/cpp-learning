#include <forward_list>

using std::forward_list;

forward_list<int> &
delete_fli_odd(forward_list<int> &fli)
{
	auto prev = fli.before_begin(), curr = fli.begin(), end = fli.end();
	while (curr != end)
		if (*curr % 2)
			curr = fli.erase_after(prev);
		else {
			prev = curr;
			++curr;
		}

	return fli;
}