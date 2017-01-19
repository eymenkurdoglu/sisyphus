
llist* llist::my_search( llist* a, int y )
{

if ( a->data == y ) return a;
while ( a->next ) {
	a = a->next;
	if ( a->data == y ) return a;	
}

return NULL;
}

llist* llist::epi_search( llist* a, int y )
{

while ( a && a->data != y ) a = a->next;

return a;
}

void llist::my_insertAfter( llist* a, int x )
{

if ( !a ) return;

llist* node = new llist;
node->data = x;
node->next = a->next;
a->next = node;

}

void llist::my_deleteAfter( llist* a )
{

llist* n = a->next;
if ( n ) { a->next = n->next; delete n; }

}

llist* llist::my_mergeTwoSortedLists( llist* a, llist* b )
{
llist* a_ptr, b_ptr;
llist* head = a->data < b->data ? a : b;

if ( head == a ) a_ptr = a->next;
else b_ptr = b->next;

while ( a_ptr && b_ptr ) {
	llist* n = a_ptr->data > b_ptr->data ? b_ptr : a_ptr;
	tail->next = n;
	tail = n;
	n == a_ptr ? a_ptr : b_ptr = n->next;
}
tail->next = a_ptr ? b_ptr : a_ptr;
}
