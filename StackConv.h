# include <stdio.h>
# include <stdlib.h>

typedef struct Node {
	char data;
	struct Node * next;
} Node;

Node * top;

void push( char data ){
	Node * new_ = (Node *) malloc(sizeof(Node));
	new_ -> data = data;
	new_ -> next = NULL;
	
	if ( top == NULL ){
		top = new_;
	} else {
		new_ -> next = top;
		top = new_;
	}
}

char pop(){
	if ( top == NULL ){
		printf("Stack Empty !\n");
	} else {
		Node * tmp = top;
		int t = top -> data;
		top = top -> next;
		free(tmp);
		return t;
	}
}

bool isEmpty(){
	return top == NULL;
}

char stackTop(){
	return top -> data;
}

void printStack(){
	Node * tmp = top;
	while ( tmp != NULL ){
		printf("%c -> ", tmp -> data);
		tmp = tmp -> next;
	}
}
