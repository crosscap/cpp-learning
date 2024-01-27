#include <memory>

using std::shared_ptr;

struct destination {};
struct connection {};

connection connect(destination *);
void disconnect(connection);
void end_connection(connection *p);
void f(destination &d);

void f(destination &d)
{
	connection c = connect(&d);
	shared_ptr<connection> p(&c, [](shared_ptr<connection> p){disconnect(*p);});
}