
// Name: Ruhail Mir
// Roll No: 64
// 4th Sem CSE

# include <stdio.h>

typedef long long int T;

T fact( int n ){
	if ( n <= 1 ) return 1; 
	return n * fact( n - 1 );
}

int main(){
	int k = 8;
	T factorial_k = fact( k );

	printf("Factorial of %d is %lld\n", k, factorial_k);

	return 0;
}


// END ...
