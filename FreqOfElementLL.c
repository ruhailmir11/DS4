# include <stdio.h>
# include <time.h>
# include "LL.h"

/*
    Roll No: CSE_LE_64
    Sem: 4th
*/

typedef struct KV {
	int key;
	int freq;
} KV;

// Custom print function ...
void printKV( T data ){
	KV * kv = (KV *)(data);
	printf("%d\t:\t%d\n", kv -> key, kv -> freq);
}

// Custom search function ...
Node * searchKV ( T e ) {
    Node * tmp = head;
    while ( tmp != NULL ){
        if( ((KV *)(tmp -> data)) -> key == e ){
            return tmp;
        }
        tmp = tmp -> next;
    }
    return NULL;
}

int main(){
	srand(time(NULL));

	// Generating 10 random numbers ...
	for ( int i=0; i < 10; i++ ){
		int n = rand() % 10;

		Node * node;
		if (( node = searchKV ( n )) != NULL ){
			((KV * )( node -> data )) -> freq += 1;
		} else {
			KV * kv = ( KV * ) malloc ( sizeof (KV) );
			kv -> key = n;
			kv -> freq = 1;
			push( kv );
		}
	}

	// Displaying the numbers and frequencies...
	print( printKV );

	return 0;
}

// END ...
