#include <stdio.h>
#include <stdlib.h>

void printArray( int * ar, int n ){
	for( int i=0; i < n; i++ ){
		printf("%d, ", ar[i]);
	}
	printf("\n\n");
}

int * copyOf( int * ar, int n ){
	int * copy = (int *) malloc (sizeof(int) * n);
	for( int i=0; i<n;i++ ) copy[i] = ar[i];
	return copy;
}

int * bubbleSort( int * ar, int n ){
	for( int i=0; i < n; i++ ){
		for( int j=0; j < n - i - 1; j++ ){
			if ( ar[j] > ar[j+1] ){
				int tmp = ar[j];
				ar[j] = ar[j+1];
				ar[j+1] = tmp;
			}
		}
	}
	return ar;
}

int * selectionSort( int * ar, int n ){
	for( int i=0; i < n; i++ ){
		int min = i;

		for ( int j = i+1; j < n; j++ ){
			if( ar[j] < ar[min] ) min = j;
		}

		if( min != i ){
			int tmp = ar[min];
			ar[min] = ar[i];
			ar[i] = tmp;
		}
	}
	return ar;
}

int * insertionSort( int * ar, int n ){
	for( int i = 1; i < n; i++ ){
		int currentValue = ar[i];
		int j = i - 1;

		while( j >= 0 && ar[j] > currentValue ){
			ar[ j+1 ] = ar[j];
			j--;
		}

		ar[j+1] = currentValue;
	}

	return ar;
}

int main(){
	int A[] = { 6, 4, 1, 3, 2, 5, 7 };
	int n = sizeof(A) / sizeof(A[0]);
	printf("Before Sorting: \n");
	printArray( A, n );

	printf("BubbleSort: \n");
	int * bubble = bubbleSort( copyOf(A, n), n );
	printArray( bubble, n );


	printf("SelectionSort: \n");
	int * selection = selectionSort( copyOf(A, n), n );
	printArray( selection, n );
	

	printf("InsertionSort: \n");
	int * insertion = insertionSort( copyOf(A, n), n );
	printArray( insertion, n );

	return 0;
}
