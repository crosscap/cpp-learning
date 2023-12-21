#include "t15-26.h"

int main()
{
	Quote quote1, quote2("quote2", 10);
	Bulk_quote bulk("bulk", 20, 10, 0.1);

	quote1 = quote2;
	quote2.debug() << endl;
	bulk.debug() << endl;

	return 0;
}