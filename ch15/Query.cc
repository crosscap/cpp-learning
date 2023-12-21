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

using line_no = vector<string>::size_type;

class QueryResult;

class TextQueriy
{
public:
	TextQueriy(ifstream &infile);

	QueryResult query(const string &s) const;

private:
	shared_ptr<vector<string>> file;
	map<string, shared_ptr<set<line_no>>> wm;
};

class QueryResult
{
	friend ostream &print(ostream &outfile, const QueryResult &query);

public:
	QueryResult(const string &s,
	            shared_ptr<set<line_no>> p,
	            shared_ptr<vector<string>> f)
		: sought(s), lines(p), file(f) { }

private:
	string sought;
	shared_ptr<set<line_no>> lines;
	shared_ptr<vector<string>> file;
};

TextQueriy::TextQueriy(ifstream &infile)
	: file(new vector<string>)
{
	string text;
	while (getline(infile, text)) {
		file->push_back(text);
		int n = file->size() - 1;
		istringstream line(text);
		string word;
		while (line >> word) {
			auto &lines = wm[word];
			if (!lines)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}

QueryResult TextQueriy::query(const string &sought) const
{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);

	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}

ostream &print(ostream &os, const QueryResult &query)
{
	os << query.sought << " occurs " << query.lines->size() << " times" << endl;
	for (auto num : *query.lines)
		cout << "\t(line " << num + 1 << " ) " << *(query.file->begin() + num) << endl;

	return os;
}

void runQueries(ifstream &infile)
{
	TextQueriy tq(infile);

	while (true) {
		cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q")
			break;
		print(cout, tq.query(s)) << endl;
	}
}

string make_plural(int i, const string &word, const string &behind)
{
	return i > 1 ? word + behind : word;
}

void clean_word(string &str)
{
	for (auto iter = str.begin(); iter != str.end();)
		if (iter == str.end() - 1 && !isalnum(*iter))
			iter = str.erase(iter);
		else {
			*iter = tolower(*iter);
			++iter;
		}
}

int main()
{
	ifstream ifile("input.txt");

	runQueries(ifile);

	return 0;
}