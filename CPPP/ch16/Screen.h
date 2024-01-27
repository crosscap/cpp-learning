#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::vector;

class Window_mgr;

template <std::string::size_type, std::string::size_type>
class Screen;
template <std::string::size_type H, std::string::size_type W>
std::istream &operator>>(std::istream &, Screen<H, W> &);
template <std::string::size_type H, std::string::size_type W>
std::ostream &operator<<(std::ostream &, const Screen<H, W> &);

template <std::string::size_type H, std::string::size_type W>
class Screen
{
	friend std::istream &operator>> <H, W>(std::istream &, Screen<H, W> &);
	friend std::ostream &operator<< <H, W>(std::ostream &, const Screen<H, W> &);
	friend class Window_mgr;

public:
	typedef std::string::size_type pos;

	Screen()
		: contents(H * W, ' ') { }
	Screen(pos ht, pos wd, char c)
		: contents(H * W, c) { }

	char get() const { return contents[cursor]; }
	char get(pos ht, pos wd) const;
	Screen &clear(char = ' ');

	Screen &set(char);
	Screen &set(pos, pos, char);
	Screen &move(pos r, pos c);
	Screen &displey(std::ostream &os);
	const Screen &displey(std::ostream &os) const;
	pos size() { return W * H; }

private:
	pos cursor = 0;
	std::string contents;

	void do_display(std::ostream &os) const { os << contents; }
};

template <std::string::size_type H, std::string::size_type W>
inline Screen<H, W> &Screen<H, W>::move(pos r, pos c)
{
	pos row = r * W;
	cursor = row + c;
	return *this;
}

template <std::string::size_type H, std::string::size_type W>
inline char Screen<H, W>::get(pos r, pos c) const
{
	pos row = r * W;
	return contents[row + c];
}

template <std::string::size_type H, std::string::size_type W>
Screen<H, W> &Screen<H, W>::clear(char c)
{
	contents = std::string(H * W, c);
	return *this;
}

template <std::string::size_type H, std::string::size_type W>
inline Screen<H, W> &Screen<H, W>::set(char c)
{
	contents[cursor] = c;
	return *this;
}

template <std::string::size_type H, std::string::size_type W>
inline Screen<H, W> &Screen<H, W>::set(pos r, pos col, char ch)
{
	contents[r * W + col] = ch;
	return *this;
}

template <std::string::size_type H, std::string::size_type W>
Screen<H, W> &Screen<H, W>::displey(std::ostream &os)
{
	do_display(os);
	return *this;
}

template <std::string::size_type H, std::string::size_type W>
const Screen<H, W> &Screen<H, W>::displey(std::ostream &os) const
{
	do_display(os);
	return *this;
}

template <std::string::size_type H, std::string::size_type W>
std::istream &operator>>(std::istream &is, Screen<H, W> &rhs)
{
	std::string t;
	is >> t;
	rhs.contents = t.substr(0, H * W);
	return is;
}

template <std::string::size_type H, std::string::size_type W>
std::ostream &operator<<(std::ostream &os, const Screen<H, W> &rhs)
{
	os << rhs.contents;
	return os;
}
#endif