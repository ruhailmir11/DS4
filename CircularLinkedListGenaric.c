# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

/*
    Roll No: CSE_LE_64
    Sem: 4th
*/

typedef void * T;

typedef struct Node {
    T data;
    struct Node * next;
} Node;

void pop();
void shift();

Node * head, *tail;

void push ( T data ){
    Node * n = (Node *) malloc (sizeof(Node));
    n -> data = data;

    if ( head == NULL ){
        head = n;
        tail = n;
    } else {
        tail -> next = n;
        tail = tail -> next;
        tail -> next = head;
    }
}

void insertAfter( T e, T d ){
	if ( tail -> data == e ){
		push( d );
		return;
	}

    Node * tmp = head;
    while ( tmp != tail && tmp -> data != e ){
        tmp = tmp -> next;
    }
    if ( tmp == NULL ){
        printf("Element not found ! \n");
        return;
    }
    Node * n = (Node *) malloc ( sizeof ( Node ) );
    n -> data = d;
    n -> next = tmp -> next;
    tmp -> next = n;
}

void insertBefore( T e, T d ){
    Node * tmp = head;

    Node * n = (Node *) malloc ( sizeof ( Node ) );
    n -> data = d;
    
    if ( head -> data == e ){
        n -> next = head;
        head = n;
        return;
    }

    while ( tmp -> next != tail && tmp -> next -> data != e ){
        tmp = tmp -> next;
    }

    if ( tmp -> next == NULL ){
        printf("Element not found ! \n");
        return;
    }

    n -> next = tmp -> next;
    tmp -> next = n;
}

void print( void (*func(void *)) ){
    Node * tmp = head;
    while ( tmp != NULL ){
        func( tmp -> data );
        if ( tmp == tail ) break;
        else tmp = tmp -> next;
    }
    printf("\n");
}

Node * search ( T e ) {
    Node * tmp = head;
    while (true){
        if ( tmp -> data == e ){
            return tmp;
        }
        if ( tmp == tail ) break;
        else tmp = tmp -> next;
    }
    return NULL;
}

void deletes ( T e ){
    if ( head == NULL ){
        printf("List Empty !\n");
        return;
    }

    if ( head -> data == e ){
        shift();
        return;
    } else if ( tail -> data == e ){
        pop();
        return;
    }

    Node * tmp = head;
    while( tmp != tail && tmp -> next -> data != e ){
        tmp = tmp -> next;
    }

    Node * d = tmp -> next;
    tmp -> next = d -> next;
    free(d);
}

void shift(){
	Node * tmp = head;

	if( head == tail ){
		tmp -> next = NULL;
		head = tmp -> next;
		tail = tmp -> next;
		return;
	}

	head = tmp -> next;
}

void pop(){
    if ( head == NULL ){
        printf("List empty !\n");
        return;
    }

    if ( head == tail ){
        shift();
        return;
    }

    Node * tmp = head;
    while( tmp -> next != tail ){
        tmp = tmp -> next;
    }

    tmp -> next = NULL;
    tail = tmp;
    tail -> next = head;
}

void set( T e, T d ){
    Node * n = search ( e );
    if ( n == NULL ){
        printf("Element not in the list !\n");
        return;
    }
    n -> data = d;
}

// Define your own custom function
// to print other types of data ...

// For genaric integer data ...
void printInt( T data ){
    printf("%d -> ", (int)(data));
}

// For genaric string data ...
void printString( T data ){
    printf("%s -> ", (char *)(data));
}

int main() {
    // Add an element at the end of the list.
    push("apple");
    push("mango");
    push("grape");

    // Insert element before a given element.
    insertBefore( "grape", "strawberry" );

    // Insert element after a given element.
    insertAfter("mango", "something");

    // Delete first element in the List.
    shift();
    
    // Delete any element in the List.
    deletes("something");
    
    // Search an element in the list.
    Node * n;
    if ( ( n = search ("strawberry") ) != NULL ){
        printf("\"%s\" found in the list\n", n -> data);
    } else {
        printf("element not found in the list\n");
    }
    
    // Update an element in the list.
    set("strawberry", "apple");
    
    // Print the list with given genaric handler.
    print( printString );
    return 0;
}
