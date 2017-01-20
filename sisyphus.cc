#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>

#include "bt.hh"
#include "llist.hh"
#include "stack.hh"

using namespace std;

int main ()
{

int N; cin >> N;

srand( time( NULL ) );

vector<int> v;

for ( int i = 0; i < N; i++ )
	v.push_back( rand()%20 );

for ( int i : v ) cout << i << ' ';
cout << endl;



return 0;
}
