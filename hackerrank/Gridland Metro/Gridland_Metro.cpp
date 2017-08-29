#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct LineSegment {
	public:
	long left, right;
	LineSegment ( long a, long b ) {
		left = a, right = b;
	}
	bool operator< (const LineSegment& rhs) const {
		return left < rhs.left;
	}
	bool operator> ( const LineSegment& rhs) const {
		return left > rhs.left;
	}
	bool operator== ( const LineSegment& rhs) const {
		return left == rhs.left;
	}   
};

long union_and_count( vector<LineSegment>& A ) {
	if ( A.empty() ) return 0;
	sort( A.begin(), A.end() );
	LineSegment curr( A.front() );
	long total_length = 0;
	for ( int i = 1; i < A.size(); i++ ) {
		if ( A[i].left <= curr.right ) {
			if ( A[i].right >= curr.right ) curr.right = A[i].right;
		} else {
			total_length += curr.right - curr.left + 1;
			curr = A[i];
		}
	}
	total_length += curr.right - curr.left + 1;
	return total_length;
}

int main() {

long long n, m, k;
cin >> n >> m >> k;
unordered_map< long, vector<LineSegment> > tracks_in_row;
vector<int> used_rows;
for ( int i = 0; i < k; i++ ) {
	long r, left, right;
	cin >> r >> left >> right;
	if ( tracks_in_row.count( r-1 ) > 0 ) {
		tracks_in_row[r-1].push_back( LineSegment(left-1, right-1) );
	} else {
		used_rows.push_back( r-1 );
		tracks_in_row[r-1].push_back( LineSegment(left-1, right-1) );
	}
}
long sum = 0;
for ( int i = 0; i < used_rows.size(); i++ ) {
	sum += m - union_and_count( tracks_in_row[ used_rows[i] ] );
}
sum += m * ( n-used_rows.size() );
cout << sum << endl;

return 0;
}
