#include "Screen.h"

typedef std::string::size_type pos;

int main()
{
	const pos Screen::*cdata = Screen::get_cursor_pos();
	Screen scr(20, 80);
	Screen *pscr = &scr;
	pos num0 = scr.*cdata, num1 = pscr->*cdata;

	return 0;
}
