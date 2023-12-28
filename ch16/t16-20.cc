#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

template <typename container>
void display_vector(const container &vec)
{
	for(typename vec::iterator iter = vec.cbegin(); iter != vec.cend(); ++iter)
		cout << *iter << " ";
	cout << endl;
}