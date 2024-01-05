#include "t17-03.h"

tuple<string, shared_ptr<set<line_no>>, shared_ptr<vector<string>>>
TextQueriy::query(const string &sought) const
{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);

	auto loc = wm.find(sought);
	if (loc == wm.end())
		return make_tuple(sought, nodata, file);
	else
		return make_tuple(sought, loc->second, file);
}