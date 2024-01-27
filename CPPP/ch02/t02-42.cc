#include "Sales_data.h"
#include <iostream>
#include <string>

int main()
{
	double price;
	Sales_data book;

	// t01-20
	while (std::cin >> book.bookNo >> book.units_sold >> price) {
		book.revenue = book.units_sold * price;
		std::cout << book.bookNo << book.units_sold << book.revenue << std::endl;
	}
	// t01-21
	double price1, price2;
	Sales_data item1, item2;

	std::cin >> item1.bookNo >> item1.units_sold >> price1;
	std::cin >> item2.bookNo >> item2.units_sold >> price2;
	item1.revenue = item1.units_sold * price1;
	item2.revenue = item2.units_sold * price2;
	std::cout << item1.bookNo
			  << item1.units_sold + item2.units_sold
			  << item1.revenue + item2.revenue
			  << std::endl;

	// t01-22
	Sales_data book_sum;
	while (std::cin >> book.bookNo >> book.units_sold >> price) {
		book.revenue = book.units_sold * price;
		book_sum.units_sold += book.units_sold;
		book_sum.revenue += book_sum.revenue;
	}
	std::cout << book_sum.bookNo << book_sum.units_sold << book_sum.revenue << std::endl;

	// t01-23

	Sales_data curritem, item;
	if (std::cin >> curritem.bookNo >> curritem.units_sold >> price) {
		curritem.revenue = curritem.units_sold * price;
		int cnt = 1;
		while (std::cin >> item.bookNo >> item.units_sold >> price) {
			item.revenue = item.units_sold * price;
			if (curritem.bookNo == item.bookNo)
				++cnt;
			else {
				std::cout << curritem.bookNo << " occures "
						  << cnt << " times" << std::endl;
				curritem = item;
				cnt = 1;
			}
		}
		std::cout << curritem.bookNo << " occures "
				  << cnt << " times" << std::endl;
	}

	// t01-25
	Sales_data total; // variable to hold data for the next transaction

	// read the first transaction and ensure that there are data to process
	if (std::cin >> total.bookNo >> total.units_sold >> price) {
		total.revenue = total.units_sold * price;
		Sales_data trans; // variable to hold the running sum
		// read and process the remaining transactions
		while (std::cin >> trans.bookNo >> trans.units_sold >> price) {
			trans.revenue = trans.units_sold * price;
			// if we're still processing the same book
			if (total.bookNo == trans.bookNo) {
				total.units_sold += trans.units_sold;
				total.revenue += trans.revenue; // update the running total
			} else {
				// print results for the previous book
				std::cout << total.bookNo << total.units_sold << total.revenue << std::endl;
				total = trans; // total now refers to the next book
			}
		}
		std::cout << total.bookNo << total.units_sold << total.revenue << std::endl;
		// print the last transaction
	} else {
		// no input! warn the user
		std::cerr << "No data?!" << std::endl;
		return -1; // indicate failure
	}

	return 0;
}