
class llist {

public:
llist( int x ) { data = x; next = NULL; };
llist* my_search( llist*, int );
void my_insertAfter( llist*, int );
void my_deleteAfter( llist* );
llist* my_mergeTwoSortedLists( llist*, llist* );
void my_append( llist*, llist* );
llist* my_reverseList( llist* );
 
llist* epi_search( llist*, int );
private:
int data;
llist* next;

};
