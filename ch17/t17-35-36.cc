#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

void inbook()
{
	cout << "default format: " << 100 * sqrt(2.0) << '\n'
		 << "scientific: " << scientific << 100 * sqrt(2.0) << '\n'
		 << "fixed decimal: " << fixed << 100 * sqrt(2.0) << '\n'
		 << "hexadecimal: " << hexfloat << 100 * sqrt(2.0) << '\n'
		 << "use defaults: " << defaultfloat << 100 * sqrt(2.0) <<"\n\n";
}

void iostm35()
{
	cout << "default format: " << 100 * sqrt(2.0) << '\n'
		 << "scientific: " << scientific << 100 * sqrt(2.0) << '\n'
		 << "fixed decimal: " << fixed << 100 * sqrt(2.0) << '\n'
		 << "hexadecimal: " << hexfloat << 100 * sqrt(2.0) << '\n'
		 << "hexadecimal upper: " << hexfloat << uppercase << 100 * sqrt(2.0) << '\n' << nouppercase
		 << "use defaults: " << defaultfloat << 100 * sqrt(2.0) <<"\n\n";
}

void iostm36()
{
	cout << left
		 << setw(20) << "default format: " << 100 * sqrt(2.0) << '\n'
		 << setw(20) << "scientific: " <<  scientific << 100 * sqrt(2.0) << '\n'
		 << setw(20) << "fixed decimal: " << fixed << 100 * sqrt(2.0) << '\n'
		 << setw(20) << "hexadecimal: " << hexfloat << 100 * sqrt(2.0) << '\n'
		 << setw(20) << "hexadecimal upper: " << hexfloat << uppercase << 100 * sqrt(2.0) << '\n' << nouppercase
		 << setw(20) << "use defaults: " << defaultfloat << 100 * sqrt(2.0) <<"\n\n";
}

int main()
{
	iostm36();
	return 0;
}