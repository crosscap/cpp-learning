// choose (c)
// do in feature

#include <deque>
#include <fstream>

#include "Query.h"

using std::cout;
using std::cin;
using std::deque;
using std::endl;
using std::ifstream;
using std::string;

void get_input_and_search(const ifstream &);
void get_answer();
void find_history();

int main()
{
	string flag;
	ifstream input_file("storyDataFile.txt");
	while (true) {
		cout << "enter 1 to put in a search\n"
			 << "enter 2 to check history\n"
			 << "enter q to quite" << endl;
		cin >> flag;
		if (flag == "1")
			get_input_and_search(input_file);
		else if (flag == "2")
			;
		else if (flag == "q")
			break;
		else
			cout << "please enter a right character" << endl;
	}
}

void runQueries(ifstream &input_file)
{
	Query q = Query("fiery") & Query("bird") | Query("wind");
	std::cout << q << std::endl;
	auto eval = q.eval(input_file);
	print(std::cout, eval);
}
