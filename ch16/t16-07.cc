#include <iostream>

template <typename elemType, size_t size>
constexpr size_t array_size(elemType (&a)[size])
{
	return size;
}