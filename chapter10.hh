#include "bt.hh"

namespace ch10 {

template <typename T>
int treeHeight( bt<T>* a )
{
	if ( a == nullptr ) return -1;
	int height_left = treeHeight( a->left );
	int height_right = treeHeight( a->right );
	return 1 + (height_left >= height_right ? height_left : height_right ); 
}

template <typename T>
struct treeTuple {
	bt<T>* tree;
	int height;
};

template <typename T>
treeTuple<T> kBalanced( bt<T>* a, int k )
{
	if ( a == nullptr ) return {nullptr, -1};
	auto l = kBalanced( a->left, k );
		if ( l.tree ) return l;
	auto r = kBalanced( a->right, k );
		if ( r.tree ) return r;
	int diff = l.height - r.height;
	diff = diff >= 0 ? diff : -1*diff;
	int max = l.height >= r.height ? l.height : r.height;
	if ( diff <= k ) return {nullptr, max};
	return {a, max};	
}

}
