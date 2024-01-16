#include <cstdlib>
#include <iostream>
#include <stdexcept>

using std::abort;
using std::cerr;
using std::endl;

int main()
{
	try {
		// 使用 C++ 标准库
	} catch (std::overflow_error &oe) {
		cerr << oe.what() << endl;
		abort();
	} catch (std::underflow_error &ue) {
		cerr << ue.what() << endl;
		abort();
	} catch (std::range_error &rae) {
		cerr << rae.what() << endl;
		abort();
	} catch (std::runtime_error &rue) {
		cerr << rue.what() << endl;
		abort();
	} catch (std::domain_error &de) {
		cerr << de.what() << endl;
		abort();
	} catch (std::invalid_argument &ia) {
		cerr << ia.what() << endl;
		abort();
	} catch (std::out_of_range &oor) {
		cerr << oor.what() << endl;
		abort();
	} catch (std::length_error &lee) {
		cerr << lee.what() << endl;
		abort();
	} catch (std::logic_error &loe) {
		cerr << loe.what() << endl;
		abort();
	} catch (std::bad_alloc) {
		cerr << "bad alloc" << endl;
		abort();
	} catch (std::bad_cast) {
		cerr << "bad cast" << endl;
		abort();
	} catch (std::exception) {
		cerr << "normal exception" << endl;
		abort();
	} catch (...) {
		cerr << "default error" << endl;
		abort();
	}
}