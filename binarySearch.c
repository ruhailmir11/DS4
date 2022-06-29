
// Name: Ruhail Mir
// Roll No: 64
// 4th Sem CSE

# include <stdio.h>
# include <math.h>

int binarySearch ( int * A, int e, int S, int E ){
	int mid = (( E - S ) / 2.0 ) + S;

	if ( A[mid] == e ) {
		return mid;
	}

	else if ( A[mid] > e ) {
		// Search to the left ...
		return binarySearch( A, e, S, mid-1 );

	} else if ( A[mid] < e ) {
		// Search to the left ...
		return binarySearch( A, e, mid+1, E );
	}

	return -1;
}

int main() {
	int K[] = { 2, 3, 5, 7, 9, 11, 13, 17, 19, 23 };
	int n = sizeof( K ) / sizeof( K[0] );

	int toFind = 13;

	int index = binarySearch( K, toFind, 0, n );
	if ( index != -1 ) {
		printf("%d found at index : %d\n", toFind, index);
	} else {
		printf("%d doen't found\n", toFind);
	}

	return 0;
}

// END ...
