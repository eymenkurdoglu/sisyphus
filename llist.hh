#ifndef LLIST_HH
#define LLIST_HH

class llist {

public:
	llist( int x ) { data = x; next = NULL; };
	llist* search( llist*, int );
	void insertAfter( llist*, int );
	void deleteAfter( llist* );
	llist* mergeTwoSortedLists( llist*, llist* );
	void append( llist*, llist* );
	llist* reverseList( llist* );
 
	llist* episearch( llist*, int );

private:
	int data;
	llist* next;

};

#endif
