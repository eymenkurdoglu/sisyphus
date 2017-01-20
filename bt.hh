#ifndef BT_HH
#define BT_HH
#include <iostream>

class bt {
/*full bt: every node other than leaves has 2 children
 *perfect bt: full bt where all leaves are at same depth  
 *inorder walk: L-root-R, preorder walk: root-L-R, postorder walk: L-R-root */
public:
	explicit bt( int x, bt* l, bt* r ) { data = x; left = l; right = r; };
	void inorderWalk( void );
	bool isHeightBalanced( void ); // handle iteratively
private:
	int data;
	bt* left, *right;
};

#endif
