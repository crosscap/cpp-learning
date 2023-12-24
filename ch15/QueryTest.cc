#include <fstream>

#include "Query.h"

using std::ifstream;

void runQueries(ifstream &infile);

int main()
{
	ifstream ifile("storyDataFile.txt");

	runQueries(ifile);

	return 0;
}

void runQueries(ifstream &infile)
{
	Query q = Query("fiery") & Query("bird") | Query("wind");
	std::cout << q << std::endl;
	auto eval = q.eval(infile);
	print(std::cout, eval);
}
