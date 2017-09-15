#include <iostream>
#include <cstdlib>
#include <cassert>
#include <ctime>

void printAll( int a[], int l, int r ) {
	for ( int i = l; i <= r; i++ ) std::cout << a[i] << " ";
	std::cout << std:: endl;
}

bool is_sorted( int a[], int len ) {
	for ( int i = 1; i < len; i++ ) {
		if ( a[i] < a[i-1] ) return false;
	}
	return true;
}

/* This is Lomuto's partitioning algorithm with pivot from left */
int partition1( int a[], int l, int r ) {
	int piv = a[l], j = l+1, start = l;
	for ( int i = l+1; i <= r; i++ ) {
		if ( a[i] < piv ) std::swap( a[i], a[j++] );
	}
	std::swap( a[start], a[j-1] );
	return j-1;
}

/* This is Lomuto's partitioning algorithm with pivot from right */
int partition2( int a[], int l, int r ) {
	int piv = a[r], j = l;
	for ( int i = l; i <= r-1; i++ ) {
		if ( a[i] <= piv ) std::swap( a[i], a[j++] );
	}
	std::swap( a[r], a[j] );
	return j;
}

/* This is Hoare's partitioning algorithm from CLRS */
int partition3( int a[], int l, int r ) {
	int piv = a[l], i = l-1, j = r+1;
	while ( true ) {
		do { j--; } while ( a[j] > piv );		
		do { i++; } while ( a[i] < piv );
		if ( i < j ) std::swap( a[i], a[j] );
		else {
			//printAll( a, l, r );
			return j;
		}
	}
}

void quicksort( int a[], int l, int r ) {
	if ( r <= l ) return;
	int i = partition3( a, l, r );
	assert( i >= l );
	assert( i <= r );
	quicksort( a, l, i ); // for hoare
	quicksort( a, i+1, r ); // for hoare
	//quicksort( a, l, i-1 ); // for lomuto
	//quicksort( a, i+1, r ); // for lomuto
}

int* genRandArr( int n, int max ) {
	srand( time( nullptr ) );
	int* a = new int[ n ];
	for ( int i = 0; i < n; i++ ) a[ i ] = rand() % max;
	return a;
}

int main ( int argc, char* argv[] ) {
	
	if ( argc != 3 ) return -1;
	int n = atoi( argv[1] );
	int* arr = genRandArr( n, atoi( argv[2] ) );
	//printAll( arr, 0, n-1 );
	std::cout << "Random array generated, sorting..." << std::endl;
	clock_t begin = clock();
	quicksort( arr, 0, n-1 );
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	std::cout << "Took " << elapsed_secs << " sec" << std::endl;
	std::cout << "Array sorted? " << is_sorted( arr, n ) << std::endl;
	
	begin = clock();
	quicksort( arr, 0, n-1 );
	end = clock();
	elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	std::cout << "Took " << elapsed_secs << " sec" << std::endl;
	std::cout << "Array sorted? " << is_sorted( arr, n ) << std::endl;	
	
	delete[] arr;
	
return 0;	
}
