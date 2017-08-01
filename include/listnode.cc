#include "listnode.hh"

template <class Item>
void linkedlist<Item>::insert( const Item& x ) {
	listnode<Item>* newnode = new listnode<Item>( x, head );
	head = newnode;
}

template <class Item>
listnode<Item>* linkedlist<Item>::find_unique ( const Item& x ) {
	listnode<Item>* t = head;
	if ( t && t->next == x ) t = t->next;
return t;
}