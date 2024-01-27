#include "Screen.h"

typedef char (Screen::*Pmf1)() const;
typedef Screen &(Screen::*Pmf2)(char);
typedef Screen &(Screen::*Pmf3)(Screen::pos, Screen::pos, char);
typedef Screen &(Screen::*Pmf4)(Screen::pos, Screen::pos);
typedef Screen &(Screen::*Pmf5)(Screen::Directions);
using Pmf6 = Screen &(Screen::*)(std::ostream &os);
using Pmf7 = const Screen &(Screen::*)(std::ostream &os) const;
using Pmf8 = Screen::pos (Screen::*)();
using Pmf9 = Screen &(Screen::*)();
