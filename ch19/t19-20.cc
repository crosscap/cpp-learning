#include <cctype>
#include <cstddef>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::ispunct;
using std::istringstream;
using std::map;
using std::ostream;
using std::pair;
using std::set;
using std::shared_ptr;
using std::size_t;
using std::string;
using std::strlen;
using std::tolower;
using std::vector;

class TextQuery
{
public:
	class QueryResult;

	using line_no = std::vector<std::string>::size_type;

	TextQuery(std::ifstream &);
	QueryResult query(const std::string &) const;
	void display_map();

private:
	std::shared_ptr<std::vector<std::string>> file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;

	static std::string cleanup_str(const std::string &);
};

class TextQuery::QueryResult
{
	friend std::ostream &print(std::ostream &, const QueryResult &);

public:
	typedef std::set<line_no>::const_iterator line_it;
	QueryResult(std::string s,
	            std::shared_ptr<std::set<line_no>> p,
	            std::shared_ptr<std::vector<std::string>> f);
	std::set<line_no>::size_type size() const { return lines->size(); }
	line_it begin() const { return lines->cbegin(); }
	line_it end() const { return lines->cend(); }
	std::shared_ptr<std::vector<std::string>> get_file() { return file; }

private:
	std::string sought;
	std::shared_ptr<std::set<line_no>> lines;
	std::shared_ptr<std::vector<std::string>> file;
};

std::ostream &print(std::ostream &os, const TextQuery::QueryResult &query);

inline TextQuery::QueryResult::QueryResult(std::string s,
                                           std::shared_ptr<std::set<line_no>> p,
                                           std::shared_ptr<std::vector<std::string>> f)
	: sought(s), lines(p), file(f) { }

string make_plural(int i, const string &word, const string &behind)
{
	return i > 1 ? word + behind : word;
}

// read the input file and build the map of lines to line numbers
TextQuery::TextQuery(ifstream &is)
	: file(new vector<string>)
{
	string text;
	while (getline(is, text)) {   // for each line in the file
		file->push_back(text);    // remember this line of text
		int n = file->size() - 1; // the current line number
		istringstream line(text); // separate the line into words
		string word;
		while (line >> word) { // for each word in that line
			word = cleanup_str(word);
			// if word isn't already in wm, subscripting adds a new entry
			auto &lines = wm[word];            // lines is a shared_ptr
			if (!lines)                        // that pointer is null the first time we see word
				lines.reset(new set<line_no>); // allocate a new set
			lines->insert(n);                  // insert this line number
		}
	}
}

// not covered in the book -- cleanup_str removes
// punctuation and converts all text to lowercase so that
// the queries operate in a case insensitive manner
string TextQuery::cleanup_str(const string &word)
{
	string ret;
	for (auto it = word.begin(); it != word.end(); ++it) {
		if (!ispunct(*it))
			ret += tolower(*it);
	}
	return ret;
}

TextQuery::QueryResult
TextQuery::query(const string &sought) const
{
	// we'll return a pointer to this set if we don't find sought
	static shared_ptr<set<line_no>> nodata(new set<line_no>);

	// use find and not a subscript to avoid adding words to wm!
	auto loc = wm.find(cleanup_str(sought));

	if (loc == wm.end())
		return QueryResult(sought, nodata, file); // not found
	else
		return QueryResult(sought, loc->second, file);
}

ostream &print(ostream &os, const TextQuery::QueryResult &qr)
{
	// if the word was found, print the count and all occurrences
	os << qr.sought << " occurs " << qr.lines->size() << " "
	   << make_plural(qr.lines->size(), "time", "s") << endl;

	// print each line in which the word appeared
	for (auto num : *qr.lines) // for every element in the set
							   // don't confound the user with text lines starting at 0
		os << "\t(line " << num + 1 << ") "
		   << *(qr.file->begin() + num) << endl;

	return os;
}