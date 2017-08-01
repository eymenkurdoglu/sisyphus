llist* llist::search( llist* a, int y )
{

while ( a && a->data != y ) a = a->next;

return a;
}

void llist::insertAfter( llist* a, int x )
{

if ( !a ) return;

llist* node = new llist;
node->data = x;
node->next = a->next;
a->next = node;

}

void llist::deleteAfter( llist* a )
{ 
if ( a ) {
	llist* n = a->next;
	if ( n ) { a->next = n->next; delete n; } 
}
}

void llist::deleteThis( llist* a ) // use only if the element to be deleted is not the last!!
{
if ( a->next ) {
	a->data = (a->next)->data;
	llist* temp = a->next;
	a->next = (a->next)->next;
	delete temp;
} 
}

// llist* llist::mergeTwoSortedLists( llist* a, llist* b )
// {
// // merges in place
// llist* head = a->data < b->data ? a : b;
// 
// if ( head == a ) a = a->next;
// else b = b->next;
// 
// while ( a && b ) {
// 	llist* n = a->data >= b->data ? b : a;
// 	tail->next = n;
// 	tail = n;
// 	(n == a ? a : b) = n->next;
// }
// tail->next = a ? a : b;
// 
// return head;
// }

llist* mergeTwoLists(llist* l1, llist* l2) {
	llist* merged = new llist( -1 );
	llist* sentinel = merged;
	if ( l1 && l2 ) {
		llist** min = l1->val < l2->val ? &l1 : &l2;
		merged->next = *min;
		*min = (*min)->next;
		merged = merged->next;
	}
	if ( l1 && !l2 ) merged->next = l1;
	else if ( !l1 && l2 ) merged->next = l2;
return sentinel->next;
}

void llist::append( llist* a, llist* node )
{
if ( !node ) return;
node->next = a;
a = node;
}

llist* llist::reverseList( llist* fw )
{

llist* bw = NULL, temp;

while ( fw ) {
	temp = fw->next;
	my_append( bw, fw );
	fw = temp;
}

return bw;
}

bool llist::testOverlapping( llist* a, llist* b )
{

while ( a->next ) a = a->next;
while ( b->next ) b = b->next;

return a == b ? true : false;
}
