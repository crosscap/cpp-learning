#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::istream;
using std::istringstream;
using std::make_shared;
using std::map;
using std::ostream;
using std::set;
using std::shared_ptr;
using std::string;
using std::vector;

class QueryResult;

class TextQueries
{
	friend class QueryResult;

public:
	TextQueries();
	TextQueries(ifstream &infile);

	QueryResult query(const string &s);
	QueryResult query(const string &s, const TextQueries &);

private:
	shared_ptr<vector<string>> text;
	shared_ptr<map<string, set<int>>> words;
};

class QueryResult
{
	friend ostream &print(ostream &outfile, const QueryResult &query);

public:
	QueryResult(const string &str, const TextQueries &);

private:
	int counter;
	string finding;
	shared_ptr<vector<string>> text;
	shared_ptr<map<string, set<int>>> words;
	set<int> *result;
};

TextQueries::TextQueries()
{
	text = make_shared<vector<string>>();
	words = make_shared<map<string, set<int>>>();
}

TextQueries::TextQueries(ifstream &infile)
{
	string s;
	text = make_shared<vector<string>>();
	words = make_shared<map<string, set<int>>>();
	while (getline(infile, s))
		text->push_back(s);
}

QueryResult TextQueries::query(const string &s)
{
	return query(s, *this);
}

QueryResult TextQueries::query(const string &s, const TextQueries &tq)
{
	QueryResult result(s, *this);
	return result;
}

QueryResult::QueryResult(const string &str, const TextQueries &qt)
	: counter(0), finding(str), text(qt.text), words(qt.words)
{
	bool flag = false;
	string word;
	vector<int> temp_result;

	for (int i = 0, end = text->size(); i != end; ++i) {
		flag = false;
		istringstream sstrm((*text)[i]);
		while (sstrm >> word) {
			if (word == finding) {
				if (!flag) {
					flag = true;
					temp_result.push_back(i);
				}
				++counter;
			}
		}
	}
	(*words)[finding] = set<int>(temp_result.begin(), temp_result.end());
	result = &(*words)[finding];
}

ostream &print(ostream &outfile, const QueryResult &query)
{
	outfile << query.finding << " occurs " << query.counter << " times" << endl;
	for (auto &r : *query.result)
		cout << "\t(line " << r + 1 << " ) " << (*query.text)[r] << endl;

	return outfile;
}

void runQueries(ifstream &infile)
{
	TextQueries tq(infile);

	while (true) {
		cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q")
			break;
		print(cout, tq.query(s)) << endl;
	}
}

int main()
{
	ifstream ifile("input.txt");

	runQueries(ifile);

	return 0;
}