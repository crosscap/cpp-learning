#include <memory>
#include <vector>

#include "new_Quote.h"

using std::make_shared;
using std::shared_ptr;
using std::vector;

int main()
{
	vector<Quote> vec_bq;
	vec_bq.push_back(Bulk_quote("0-201", 50, 10, .25));
	vec_bq.push_back(Bulk_quote("0-202", 60, 5, .15));
	vec_bq.push_back(Bulk_quote("0-202", 20, 20, .30));
	double sum = 0;
	for (auto r : vec_bq)
		sum += r.net_price(15);
	cout << sum << endl;
	vector<shared_ptr<Quote>> vec_sp_bq;
	vec_sp_bq.push_back(make_shared<Bulk_quote>("0-201", 50, 10, .25));
	vec_sp_bq.push_back(make_shared<Bulk_quote>("0-202", 60, 5, .15));
	vec_sp_bq.push_back(make_shared<Bulk_quote>("0-202", 20, 20, .30));
	sum = 0;
	for (auto r : vec_sp_bq)
		sum += r->net_price(15);
	cout << sum << endl;
	return 0;
}