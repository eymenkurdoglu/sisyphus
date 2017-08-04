#include <vector>

using namespace std;

namespace ch6 {

template <class T> // how to put this definiton in a cc file is a mystery
extern void swap( T& x, T& y ) {
	T temp = x;
	x = y;
	y = temp;
}

void evenOdd( vector<int>& );
void dutchFlag( vector<int>&, int );
vector<int> Multiply( vector<int>, vector<int> );

}