#include "chapter6.hh"

void ch6::evenOdd( vector<int>& a )
{
	int n = a.size(), l = 0, r = n-1;

	while ( l < r ) {
		while( a[l]%2 == 0 && l < n ) l++;
		while( a[r]%2 == 1 && r >= 0 ) r--;
		if ( l < r ) swap( a[l], a[r] );
	}
}

void ch6::dutchFlag( vector<int>& a, int x )
{
	int s = 0, g = a.size()-1, e = 0;
	while ( e <= g ) {
		if ( a[e] < x ) swap( a[e++], a[s++] );
		else if ( a[e] > x ) swap( a[e], a[g--] );
		else e++;
	}
}

vector<int> ch6::Multiply( vector<int> a, vector<int> b ) {

	vector<int> res( a.size()+b.size(), 0 );
	int sign = a.front() * b.front() > 0 ? 1 : -1;
	a.front() = a.front() > 0 ? a.front() : -1*a.front();
	b.front() = b.front() > 0 ? b.front() : -1*b.front();
	for( int i = a.size()-1; i >= 0; i-- ) {
		for ( int j = b.size()-1; j >= 0; j-- ) {
			res[i+j+1] += a[i]*b[j];
			res[i+j] += res[i+j+1]/10;
			res[i+j+1] %= 10;
		}
	}

	int i;
	for ( i = 0; i < a.size()+b.size() && res[i] == 0; i++ ) ;
	vector<int> R;
	while ( i < a.size()+b.size() ) R.push_back( res[i++] );
	if ( R.empty() ) return {0};
	R.front() *= sign;

return R;
}