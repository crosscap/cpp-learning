#include <iostream>

template <typename elemType, size_t size>
elemType *begin(elemType (&a)[size])
{
	return &a[0];
}

template <typename elemType, size_t size>
elemType *end(elemType (&a)[size])
{
	return &a[size];
}