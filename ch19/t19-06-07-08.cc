#include <typeinfo>

#include "Query.h"

using std::bad_cast;

void transform(Query_base *qp, Query_base &qr)
{
	AndQuery *ap = dynamic_cast<AndQuery *>(qp);
	if (ap) {
		std::cout << "p transform succeed" << std::endl;
	} else {
		std::cout << "p transform failed" << std::endl;
	}

	try {
		AndQuery &ar = dynamic_cast<AndQuery &>(qr);
		std::cout << "r transform succeed" << std::endl;
	} catch (bad_cast) {
		std::cout << "r transform failed" << std::endl;
	}
	if (typeid(*qp) == typeid(qr)) {
		std::cout << "equal" << std::endl;
	}
	if (typeid(*qp) == typeid(AndQuery)) {
		std::cout << "equal" << std::endl;
	}
}
