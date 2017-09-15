#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N; cin >> N;
    vector<int> W(1);
    cin >> W[0];
    for ( int i = 1; i < N; i++ ) {
        int x; cin >> x;
        if ( x < W[0] ) W[0] = x;
        else if ( x > W.back() ) W.push_back( x );
        else {
            int l = 0, r = W.size()-1, res = -1;
            while ( l <= r ) {
                int m = l + (r-l)/2;
                if ( W[m] < x ) {
                    res = m;
                    l = m+1;
                } else {
                    r = m-1;
                }
            }
            assert( W[res+1] >= x );
            W[res+1] = x;
        }
    }
    cout << W.size() << endl;
    return 0;
}
