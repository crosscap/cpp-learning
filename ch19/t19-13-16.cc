#include "Sales_data.h"

// t19-13
const std::string Sales_data::*pb = &Sales_data::bookNo;

// t19-16
typedef double (Sales_data::*APP)() const;
