#include <vector>
#include <string>
#include <iostream>

using namespace std;

namespace ch16 {

	bool is_palindromic( const string& );
	void decompose( const string&, int, vector<string>*, vector< vector<string> >* );
	vector< vector<string> > list_all_palindromic_decomp( const string& );
	vector< vector<int> > power_set( const vector<int>& );
}
