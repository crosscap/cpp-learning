#include <iostream>
#include <vector>

using namespace std;

const int MAXSIZE = 100;

int main()
{
	int i;
	int input, index = 0;
	int ai[MAXSIZE];
	vector<int> vi;

	while (cin >> input){
		ai[index] = input;
		vi.push_back(input);
		++index;
	}

	int asum = 0, vsum = 0;
	double aaver, vaver;
	for (i = 0; i < index; ++i)
		asum += ai[i];
	aaver = (double)asum / i;
	for (i = 0; i < vi.size(); ++i)
		vsum += vi[i];
	vaver = (double)vsum / i;
	cout << "sum of array is: " << asum << endl;
	cout << "average of array is: " << aaver << endl;
	cout << "sum of vector is: " << vsum << endl;
	cout << "average of vector is: " << vaver << endl;

	return 0;
}