# include <stdio.h>
# include "LL.h"

/*
    Roll No: CSE_LE_64
    Sem: 4th
*/

int main(){
	// Storing even numbers from 0 - 52 in the list ...
	for ( int i=0; i < 52; i += 2 ){
		push( i );
	}

	// Displaying the numbers ...
	print( printInt );

	return 0;
}

// END ...