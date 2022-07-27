# include <stdio.h>
# include <stdlib.h>

typedef void * T;

typedef struct Node {
	T data;
	struct Node * next;
} Node;

Node * top;

void push( T data ){
	Node * new_ = (Node *) malloc(sizeof(Node));
	new_ -> data = data;

	if ( top == NULL ){
		top = new_;
	} else {
		new_ -> next = top;
		top = new_;
	}
}

T pop(){
	if ( top == NULL ){
		printf("Stack Empty !\n");
	} else {
		Node * tmp = top;
		T t = top -> data;
		top = top -> next;
		free(tmp);
		return t;
	}
}

void print(void (*func(void *))){
	Node * tmp = top;
	while ( tmp != NULL ){
		func(tmp -> data);
		tmp = tmp -> next;
	}
}

// custom print int function for genaric functionality ...
void printInt( T data ){
	printf("%d\n", (int)(data));
}

// custom print string function for genaric functionality ...
void printString( T data ){
	printf("%s\n", (char *)(data));
}

int main(){
	push("Apple");
	push("Mango");
	push("Strawberry");

	pop();

	print( printString );

	return 0;
}
