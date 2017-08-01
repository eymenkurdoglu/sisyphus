#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <unordered_map>
#include <string>
#include <unordered_set>
#include <iomanip>
#include <ctime>
#include <set>

using namespace std;

void recursive_perm ( vector<int>& b, int j, vector< vector<int> >& allperms ) {
	
	if ( j == b.size()-1 ) {
		allperms.emplace_back( b );
		return;
	}
	
	for ( int i = j; i < b.size(); i++ ) {
		swap( b[i], b[j] );
		recursive_perm( b, j+1, allperms );
		swap( b[i], b[j] );
	}
}

vector< vector<int> > permute ( vector<int>& a ) {
	vector< vector<int> > allperms;
	vector<int> b( a );
	recursive_perm ( b, 0, allperms );
	return allperms;
}

int main (int argc, char* argv[] ) {
//clock_t begin = clock();
//clock_t end = clock();

vector<int> a = {0,1,2,3,4,5,6,7};
vector< vector<int> > all = permute( a );

return 0;
}
