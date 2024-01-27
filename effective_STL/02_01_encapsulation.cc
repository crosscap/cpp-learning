#include <algorithm>
#include <vector>

using std::find;
using std::vector;

class Widget {};

// wrong writing method
vector<Widget> vw;
Widget bestWidget_w;
// Assign a value to a bestWidget_w
vector<Widget>::iterator i_w = find(vw.begin(), vw.end(), bestWidget_w);

// right writing method
typedef vector<Widget> WidgetContainer;
typedef WidgetContainer::iterator WCIterator;
WidgetContainer cw;
Widget bestWidget_r;
// Assign a value to a bestWidget_r
WCIterator i_r = find(cw.begin(), cw.end(), bestWidget_r);
