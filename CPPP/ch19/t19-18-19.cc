#include <algorithm>
#include <functional>
#include <string>
#include <vector>

#include "Sales_data.h"

using std::bind;
using std::count_if;
using std::find_if;
using std::function;
using std::mem_fn;
using std::string;
using std::vector;

using namespace std::placeholders;

size_t count_str_empty_fun(const vector<string> &strs)
{
	function<bool(const string &)> fp = &string::empty;
	return count_if(strs.begin(), strs.end(), fp);
}

size_t count_str_empty_mem(const vector<string> &strs)
{
	bool (string::*fp)() const = &string::empty;
	return count_if(strs.begin(), strs.end(), mem_fn(fp));
}

size_t count_str_empty_bind(const vector<string> &strs)
{
	bool (string::*fp)() const = &string::empty;
	return count_if(strs.begin(), strs.end(), bind(fp, _1));
}

const Sales_data &find_morethan_avg(const vector<Sales_data> &datas, double avg)
{
	return *find_if(datas.begin(), datas.end(),
	                [avg](const Sales_data &dt) { return dt.avg_price() > avg; });
}
