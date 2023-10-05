#include <vector>
using std::vector;

bool seq_elem(int pos, int &elem, const vector<int>* (*seq_ptr)(int) = nullptr);
const vector<int> * fibon_seq(int size);
const vector<int> * lucas_seq(int size);
const vector<int> * pell_seq(int size);
const vector<int> * triang_seq(int size);
const vector<int> * square_seq(int size);
const vector<int> * pent_seq(int size);
