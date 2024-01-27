#include <fstream>

#include "t15-36.h"

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
	std::cout << std::endl << q << std::endl;
}