#include "LibMat.h"

int main()
{
    cout << "\n" << "Creating a LibMat object to print()\n";
    LibMat m;
    print( m );
    cout << endl;

    cout << "\n" << "Creating a Book object to print()\n";
    Book b( "The Castle", "Franz Kafka" );
    print( b );
    cout << endl;

    cout << "\n" << "Creating a AudioBook object to print()\n";
    AudioBook ab( "Man Without Qualities", "Robert Musil", "Kenneth Meyer" );
    print( ab );
    cout << endl;

    cout << '\n' << "Creating a Magazine object to print()\n";
    Magazine ma("Go World", "202310");
    print(ma);
    cout << endl;

    return 0; // unnecessary but quiets vc++
}