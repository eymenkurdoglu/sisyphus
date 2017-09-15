void rotate_in_const_space( vector<int>& a, int d ) {
    
    d %= n;
    
    int num_cycles = gcd( n, d );
    
    for ( int i = 0; i < num_cycles; i++ ) {
        
        int to = i, from = (i+d)%n;
        
        int temp = a[to];
        
        while ( from != i ) {
            a[to] = a[from];
            to = from;
            from = (to+d)%n;
        }
        a[to] = temp;
    }	
}
