#include <string>

using std::string;

class ZooAnimal
{};

class Endangered
{};

class Bear : virtual public ZooAnimal
{
public:
	Bear();
	Bear(std::string name, bool onExhibit);
};

class Raccoon : virtual public ZooAnimal
{
public:
	Raccoon();
	Raccoon(std::string name, bool onExhibit);
};

class Panda : public Bear, public Raccoon, public Endangered
{
public:
	Panda(std::string name, bool onExhibit)
		: Bear(name, onExhibit) {}
};
