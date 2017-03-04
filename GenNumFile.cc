#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main( int argc, char* argv[] )
{
	srand( time( nullptr ) );
	ofstream outfile;
	outfile.open( "numbers.txt" );
	if ( !outfile ) {cout << "Cannot open file.\n"; return -1;}
	unsigned size = atoi( argv[1] );
	for ( int i = 0; i < size; i++ )
		outfile << rand() << endl;
	outfile.close();
return 0;
}
