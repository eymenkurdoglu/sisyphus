#include <queue>
#include <ctime> // time
#include <cstdlib> // srand, rand
#include <iostream>

int main () {
	
	srand( time( nullptr ) );
	int n = rand()%1000+1;
	int* arr = new int[ n ];
	for ( int i = 0; i < n; i++ ) {
		arr[ i ] = rand()%500;
	}
	
	// min heap:
	std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap( arr, arr+n );
	
	while ( !min_heap.empty() ) {
		std::cout << min_heap.top() << " ";
		min_heap.pop();
	}
	std::cout << std::endl;
	
return 0;
}
