
// Name: Ruhail Mir
// Roll No: 64
// 4th Sem CSE

# include <stdio.h>

typedef long long int T;

T fib ( int n ){
	if ( n <= 2 ) return 1;
	return fib( n - 1 ) + fib ( n - 2 );
}

int main(){
	int k = 10;
	printf("\n");
	printf("Fibonacci terms: 1 to 10 \n");

	for (int i = 1; i <= k; ++i) {
		T f = fib ( i );
		printf("term %d : %lld\n", i, f );
	}

	printf("\n");
	return 0;
}

// END ...
