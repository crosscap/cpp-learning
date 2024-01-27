#include <fstream>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <tuple>
#include <vector>

using std::ifstream;
using std::make_shared;
using std::make_tuple;
using std::map;
using std::set;
using std::shared_ptr;
using std::string;
using std::tuple;
using std::vector;

using line_no = vector<string>::size_type;

class TextQueriy
{
public:
	TextQueriy(ifstream &infile);

	tuple<string, shared_ptr<set<line_no>>, shared_ptr<vector<string>>> query(const string &s) const;

private:
	shared_ptr<vector<string>> file;
	map<string, shared_ptr<set<line_no>>> wm;
};
