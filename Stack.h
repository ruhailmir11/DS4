# include <stdio.h>
# include <stdlib.h>

typedef struct Node {
	int data;
	struct Node * next;
} Node;

Node * top;

void push( int data ){
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

int pop(){
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

void printStack(){
	Node * tmp = top;
	while ( tmp != NULL ){
		printf("%d -> ", tmp -> data);
		tmp = tmp -> next;
	}
}

