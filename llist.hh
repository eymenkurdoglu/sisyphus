
class llist {

public:
llist( int x ) { data = x; next = NULL; };
llist* my_search( llist*, int );
llist* epi_search( llist*, int );
void my_insertAfter( llist*, int );
void my_deleteAfter( llist* );
llist* my_mergeTwoSortedLists( llist*, llist* );
 
private:
int data;
llist* next;

};
