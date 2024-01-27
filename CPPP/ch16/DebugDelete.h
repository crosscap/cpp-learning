#ifndef DEBUGDELETE_H
#define DEBUGDELETE_H

#include <iostream>

class DebugDelete
{
public:
	DebugDelete(std::ostream &s = std::cerr)
		: os(s) { }

	template <typename T>
	void operator()(T *p) const;

private:
	std::ostream &os;
};

template <typename T>
inline void DebugDelete::operator()(T *p) const
{
	os << "deleting unique_ptr" << std::endl;
	delete p;
}
#endif