template <class Item>
class listnode {
public:
	listnode( Item x ) { key = x; next = nullptr; }
	Item key;
	listnode<Item>* next;
};

template <class Item>
class linkedlist {
public:
	linkedlist( const Item& x ) {
		head = new listnode<Item>( x );
	}
	linkedlist( const Item& x, listnode<Item>* successor ) {
		head = new listnode<Item>( x );
		head->next = successor;
	}
	void insert ( const Item& );
	listnode<Item>* find_unique ( const Item& );
	listnode<Item>* head;
};