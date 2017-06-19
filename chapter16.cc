#include "chapter16.hh"
//#include <iostream>

bool ch16::is_palindromic( const string& s ) {
	int l = 0, r = s.size()-1;
	while ( l < r ) {
		if ( s[l++] != s[r--] ) return false;
	}
	return true;
}

void ch16::decompose( const string& s, int ix, vector<string>* curr, vector< vector<string> >* res ) {
	
	if ( ix == s.size() ) {
		res->push_back( *curr );
		return;
	}

	for ( int i = ix; i < s.size(); i++ ) {
		string prefix = s.substr( ix, i-ix+1 );
		if ( is_palindromic( prefix ) ) {
			curr->push_back( prefix );
			decompose( s, i+1, curr, res );
			curr->pop_back();
		}
	}
}

vector< vector<string> > ch16::list_all_palindromic_decomp( const string& s ) {

vector< vector<string> > all;
decompose( s, 0, new vector<string>, &all );

for ( int i = 0; i < all.size(); i++ ) {
	for ( int j = 0; j < all[i].size(); j++ ) {
		std::cout << all[i][j] << " ";
	}
	std::cout << std::endl;
}

return all;
}
