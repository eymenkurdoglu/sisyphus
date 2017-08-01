#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

template <typename T>
struct ffList {
	ffList* next;
	T data;
};

template <typename T>
void appendToList( ffList<T>** list, ffList<T>* node )
{
	node->next = *list;
	*list = node;
}

template <typename T>
void appendToList( ffList<T>** list, T data )
{
	ffList<T>* node = new ffList<T>;
	node->next = *list;
	node->data = data;
	*list = node;
}

template <typename T>
ffList<T>* reverseList ( ffList<T>* list )
{
	ffList<T>* revlist = nullptr;
	while ( list ) {
		ffList<T>* temp = list;
		list = list->next;
		temp->next = revlist;
		revlist = temp;
	}
return revlist;	
}

int main ( int argc, char* argv[] )
{
	ifstream infile; 
	infile.open( "numbers.txt" );
	int x;
	ffList<int>* a = nullptr;
	if ( !infile ) {cout << "Cannot open file\n"; return -1;}
	while ( infile >> x ) {
		appendToList( &a, x );
		if ( a ) cout << a->data << " ";
	}
	cout << endl;
	ffList<int>* b = reverseList( a );
	while ( b ) {
		cout << b->data << " ";
		b = b->next;
	}
	cout << endl;
return 0;	
}
