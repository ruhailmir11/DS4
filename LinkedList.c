# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct Node {
	int data;
	struct Node * next;
} Node;

Node * root, * tail;
int size;

void append ( int data ){
	Node * new = ( Node * ) malloc ( sizeof(Node) );
	new -> data = data;

	if ( root == NULL ){
		root = new;
		tail = root;
	} else {
		tail -> next = new;
		tail = tail -> next;
	}

	size++;
}

void printList(){
	if ( size > 0 ){
		Node * tmp = root;
		while( tmp != NULL ){
			printf("%d -> ", tmp -> data);
			tmp = tmp -> next;
		}
	} else {
		printf("List Empty !\n");
	}
	printf("\n");
}

Node * search( int data ){
	Node * tmp = root;
	while( tmp != NULL ){
		if ( tmp -> data == data ) return tmp;
		tmp = tmp -> next;
	}
	return NULL;
}

bool shift(){
	if ( size > 0 ){
		root = root -> next;
		size--;
		return true;
	}
	else{
		printf("List Empty !\n");
		return false;
	}
}

bool pop(){
	if ( size <= 1 ){
		shift();	
	} else if ( size > 1 ){
		Node * tmp = root;
		while( tmp -> next -> next != NULL ){
			tmp = tmp -> next;
		}
		tmp -> next = NULL;
		size--;
		return true;
	} else {
		printf("List Empty !\n");
		return false;
	}
}

int main(){
	append(2);
	append(3);
	append(5);
	append(7);

	printList();

	// remove first element ...
	if ( shift() ) {
		printf("First element removed !\n");
	}

	// remove last element ...
	if ( pop() ){
		printf("Last element removed !\n");
	}

	// is "5" in the list ...
	
	Node * t;
	if ( ( t =search ( 5 ) ) != NULL ){
		printf( "%d is in the list\n", t -> data );
	}
	
	printList();

	return 0;
}
