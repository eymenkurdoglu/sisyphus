
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
// merges in place
llist* head = a->data < b->data ? a : b;

if ( head == a ) a = a->next;
else b = b->next;

while ( a && b ) {
	llist* n = a->data >= b->data ? b : a;
	tail->next = n;
	tail = n;
	(n == a ? a : b) = n->next;
}
tail->next = a ? a : b;

return head;
}

void llist::my_append( llist* a, llist* node )
{
if ( !node ) return;
node->next = a;
a = node;
}

llist* llist::my_reverseList( llist* fw )
{

llist* bw = NULL, temp;

while ( fw ) {
	temp = fw->next;
	my_append( bw, fw );
	fw = temp;
}

return bw;
}
