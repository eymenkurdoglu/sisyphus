#include <fstream>
#include <cstdlib>
#include <iostream>

using namespace std;

int main ( int argc, char* argv[] )
{
	srand( time( nullptr ) );
	ofstream outfile;
	outfile.open( "random.txt" );
	if ( !outfile ) {cout << "Cannot open file.\n"; return -1;}
	unsigned int fileSize = atoi( argv[1] );
	unsigned alphabetSize = 'z'-'A'+1;
	for ( int i = 0; i < fileSize; i++ ) 
		outfile << static_cast<char>('A' + rand() % alphabetSize);
	outfile.close();
return 0;
}
