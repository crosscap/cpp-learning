#include "BinaryTree.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    BinaryTree< string > bt;

    bt.insert( "Piglet" );
    bt.insert( "Eeyore" );
    bt.insert( "Roo" );
    bt.insert( "Tigger" );
    bt.insert( "Chris" );
    bt.insert( "Pooh" );
    bt.insert( "Kanga" );

    cout << "preorder traversal: \n";
	bt.preorder();
	cout << "\n\nabout to remove root: Piglet\n";
	bt.remove( "Piglet" );
	cout << "\n\npreorder traversal after Piglet removal: \n";
	bt.preorder();
	cout << "\n\nabout to remove Eeyore\n";
	bt.remove( "Eeyore" );
	cout << "\n\npreorder traversal after Piglet removal: \n";
	bt.preorder();
    cout << endl;

    return 0;
}