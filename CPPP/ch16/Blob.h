#ifndef BLOB_H
#define BLOB_H

#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

using std::shared_ptr;
using std::string;
using std::vector;

template <typename>
class BlobPtr;
template <typename>
class Blob;
template <typename T>
bool operator==(const Blob<T> &, const Blob<T> &);

template <typename T>
class Blob
{
	friend class BlobPtr<T>;
	friend bool operator== <T>(const Blob<T> &, const Blob<T> &);

public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;

	Blob();
	Blob(std::initializer_list<T> il);
	template <typename It>
	Blob(It, It);

	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const T &t) { data->push_back(t); }
	void push_back(T &&t) { data->push_back(std::move(t)); }
	void pop_back();
	T &back();
	const T &back() const;
	T &front();
	const T &front() const;
	T &operator[](size_type n);
	const T &operator[](size_type n) const;

	BlobPtr<T> begin() { return BlobPtr<T>(*this); }
	BlobPtr<T> end();

private:
	std::shared_ptr<std::vector<T>> data;
	void check(size_type i, const std::string &msg) const;
};

template <typename T>
inline Blob<T>::Blob()
	: data(std::make_shared<vector<T>>()) { }

template <typename T>
inline Blob<T>::Blob(std::initializer_list<T> il)
	: data(std::make_shared<vector<T>>(il)) { }

template <typename T>
template <typename It>
inline Blob<T>::Blob(It beg, It end)
	: data(std::make_shared<vector<T>>(beg, end)) { }

template <typename T>
void Blob<T>::check(size_type i, const string &msg) const
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}

template <typename T>
void Blob<T>::pop_back()
{
	check(0, "pop_back on empty Blob");
	data->pop_back();
}

template <typename T>
T &Blob<T>::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}

template <typename T>
const T &Blob<T>::back() const
{
	check(0, "back on empty StrBlob");
	return data->back();
}

template <typename T>
T &Blob<T>::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
}

template <typename T>
const T &Blob<T>::front() const
{
	check(0, "front on empty StrBlob");
	return data->front();
}

template <typename T>
T &Blob<T>::operator[](size_type n)
{
	return (*data)[n];
}

template <typename T>
const T &Blob<T>::operator[](size_type n) const
{
	return (*data)[n];
}

template <typename T>
BlobPtr<T> Blob<T>::end()
{
	auto ret = BlobPtr<T>(*this, data->size());
	return ret;
}

template <typename T>
bool operator==(const Blob<T> &lhs, const Blob<T> &rhs)
{
	return lhs.data == rhs.data;
}

template <typename T>
class BlobPtr
{
public:
	BlobPtr()
		: curr(0) { }
	BlobPtr(Blob<T> &a, size_t sz = 0)
		: wptr(a.data), curr(sz) { }

	T &operator*() const;
	T *operator->() const;

	std::string operator[](std::size_t n) { return (*wptr.lock())[n]; }
	const std::string operator[](std::size_t n) const { return (*wptr.lock())[n]; }
	BlobPtr &operator++();
	BlobPtr &operator--();
	BlobPtr operator++(int);
	BlobPtr operator--(int);

private:
	std::shared_ptr<std::vector<std::string>>
	check(std::size_t, const std::string &) const;

	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator++()
{
	check(curr, "incerement past end of BlobPtr");
	++curr;
	return *this;
}

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator--()
{
	--curr;
	check(curr, "decerement past begin of BlobPtr");
	return *this;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
	BlobPtr ret = *this;
	++*this;
	return ret;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int)
{
	BlobPtr ret = *this;
	--*this;
	return ret;
}

template <typename T>
T &BlobPtr<T>::operator*() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

template <typename T>
T *BlobPtr<T>::operator->() const
{
	return &this->operator*();
}

template <typename T>
std::shared_ptr<std::vector<std::string>>
BlobPtr<T>::check(std::size_t i, const std::string &msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound BlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}
#endif