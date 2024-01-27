#include <fstream>
#include <iterator>
#include <string>

using std::string;
using std::ostream_iterator;
using std::istream_iterator;

void detach_even_odd(string &input, string &output_odd, string &output_even);

int main(int argc, char *argv[])
{
	if (argc == 4) {
		string input(argv[1]), output_even(argv[2]), output_odd(argv[3]);
		detach_even_odd(input, output_even, output_odd);
	}

	return 0;
}

void detach_even_odd(string &input, string &output_odd, string &output_even)
{
	std::ifstream in(input);
	std::ofstream out_odd(output_odd), out_even(output_even);
	istream_iterator<int> in_iter(in), eof;
	ostream_iterator<int> odd_iter(out_even, " "), even_iter(out_odd, "\n");

	while(in_iter != eof) {
		if (*in_iter % 2)
			odd_iter = *in_iter++;
		else
			even_iter = *in_iter++;
	}
}