#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>

#include "bt.hh"
#include "llist.hh"
#include "stack.hh"
#include "chapter6.hh"

using namespace std;

int main ()
{

int N; cin >> N;

srand( time( nullptr ) );

vector<int> v;

for ( int i = 0; i < N; i++ )
	v.push_back( rand()%100 );

ch6::print( v );
ch6::dutchFlag( v, 69 );
ch6::print( v );

return 0;
}
