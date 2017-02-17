#ifndef BT_HH
#define BT_HH
#include <iostream>

template <typename T>
struct bt {
/*full bt: every node other than leaves has 2 children
 *perfect bt: full bt where all leaves are at same depth  
 *inorder walk: L-root-R, preorder walk: root-L-R, postorder walk: L-R-root */
public:
	explicit bt( T x, bt* l, bt* r ) { data = x; left = l; right = r; };
private:
	T data;
	bt<T>* left, *right;
};

#endif
