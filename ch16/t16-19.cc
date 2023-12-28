#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

template <typename container>
void display_vector(const container &vec)
{
	for(typename vec::size_type i = 0; i != vec.size(); ++i)
		cout << vec.at(i) << " ";
	cout << endl;
}