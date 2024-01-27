#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>

using std::cout;

class Window_mgr;

class Screen
{
	friend class Window_mgr;

public:
	typedef std::string::size_type pos;
	using Action = Screen &(Screen::*)();
	enum Directions { HOME,
		              FORWARD,
		              BACK,
		              UP,
		              DOWN };

	Screen() = default;
	Screen(pos ht, pos wd)
		: height(ht), width(wd), contents(ht * wd, ' ') { }
	Screen(pos ht, pos wd, char c)
		: height(ht), width(wd), contents(ht * wd, c) { }

	char get() const { return contents[cursor]; }
	inline char get(pos ht, pos wd) const;

	Screen &set(char);
	Screen &set(pos, pos, char);
	Screen &move(pos r, pos c);
	Screen &move(Directions);
	Screen &displey(std::ostream &os);
	const Screen &displey(std::ostream &os) const;
	pos size();

	Screen &home();
	Screen &forward();
	Screen &back();
	Screen &up();
	Screen &down();

	static const pos Screen::*get_cursor_pos() { return &Screen::cursor; }

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;

	void do_display(std::ostream &os) const { os << contents; }

	static Action Menu[];
};

inline Screen &Screen::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;
	return *this;
}

inline Screen &Screen::move(Directions cm)
{
	return (this->*Menu[cm])();
}

char Screen::get(pos r, pos c) const
{
	pos row = r * width;
	return contents[row + c];
}

inline Screen &Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

Screen &Screen::displey(std::ostream &os)
{
	do_display(os);
	return *this;
}
const Screen &Screen::displey(std::ostream &os) const
{
	do_display(os);
	return *this;
}

Screen::Action Screen::Menu[] = {
	&Screen::home,
	&Screen::forward,
	&Screen::back,
	&Screen::up,
	&Screen::down
};

#endif