
// Name: Ruhail Mir
// Roll No: 64
// 4th Sem CSE

# include <stdbool.h>
# include <stdio.h>

int steps = 0;

int power( int base, int exp ){
	if ( exp <= 0 ) return 1;
	return base * power ( base, exp - 1 );
}

void TOH ( int n, char A, char B, char C ){
	steps++;

	if ( n == 1 ){
		printf("%c --> %c\n", A, C);
		return;
	} else {
		TOH( n-1, A, C, B );

		printf("%c --> %c\n", A, C);
		
		TOH( n-1, B, A, C );
	}
}

int main(){

	int n = 5;

	TOH( n, 'A', 'B', 'C' );

	int expected = power( 2, n ) - 1;

	printf("\nFinished took %d steps expected ( %d ) \n", steps, expected );

	return 0;
}


// END ...