#ifndef LLIST_HH
#define LLIST_HH

class llist {

public:
	explicit llist( int x ) { data = x; next = nullptr; };

	llist* search( llist*, int );
	void insertAfter( llist*, int );
	void deleteAfter( llist* );
	void deleteThis( llist* );
	llist* mergeTwoSortedLists( llist*, llist* );
	void append( llist*, llist* );
	llist* reverseList( llist* );
	bool testOverlapping( llist*, llist* ); 
private:
	int data;
	llist* next;
};

#endif
