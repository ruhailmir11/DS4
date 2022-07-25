# include <stdio.h>
# include <stdbool.h>
# include "LL.h"

/*
    Roll No: CSE_LE_64
    Sem: 4th
*/

bool isPrime_( int n, int k ){
    if ( k <= 1 ) return true;
    if ( n % k == 0 ) return false;
    return isPrime_( n, k - 1 );
}

// Utility ...
bool isPrime( int n ){
    return isPrime_(n, n-1);
}

int main(){
    // Generating and storing primes upto 50 ...
    for (int i = 1; i <= 50; i++){
        if ( isPrime (i) ) push( i );
    }

    // Printing the stored primes ...
    print( printInt );

    return 0;
}

// END ...
