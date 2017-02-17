#include <vector> // internally, vectors use a dynamically allocated array to store their elements.
#include <iostream>

using namespace std;

namespace ch6 {

template <class T> void swap( T& x, T& y ) { T temp = x; x = y; y = temp; }
template <class T> void print ( T& a ) { for ( int i : a ) cout << i << ' '; cout << endl; }

void evenOdd( vector<int>& a )
{
	int n = a.size(), l = 0, r = n-1;

	while ( l < r ) {
		while( a[l]%2 == 0 && l < n ) l++;
		while( a[r]%2 == 1 && r >= 0 ) r--;
		if ( l < r ) swap( a[l], a[r] );
	}
}

void dutchFlag( vector<int>& a, int x )
{
	int l = 0, r = a.size()-1, i = 0;
	while ( i <= r ) {
		if ( a[i] < x ) swap( a[i++], a[l++] );
		else if ( a[i] > x ) swap( a[i], a[r--] );
		else i++;
	}
}

} // end of namespace