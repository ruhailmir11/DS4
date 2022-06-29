
// Name: Ruhail Mir
// Roll No: 64
// 4th Sem CSE

# include <stdbool.h>
# include <stdio.h>

bool is_prime ( int n, int k ){
	if ( k <= 1 ) return 1;
	else if ( n % k == 0 ) return 0;
	return is_prime( n, k - 1 );
}

// Utility func ...
bool isPrime( int n ){
	return is_prime ( n, n - 1 );
}

int main(){
	int n = 4;
	bool result = isPrime( n );

	char *msg = result ? "Prime" : "not a Prime";
	printf("%d is %s\n", n, msg);

	return 0;
}

// END ...
