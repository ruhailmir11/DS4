# include <stdio.h>
# include <stdlib.h>

/*
    Roll No: CSE_LE_64
    Sem: 4th
*/

typedef void * T;

typedef struct Node {
    T data;
    struct Node * next;
} Node;

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
    }
}

void insertAfter( T e, T d ){
    Node * tmp = head;
    while ( tmp != NULL && tmp -> data != e ){
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
    tail = tail -> next;
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
    
    while ( tmp -> next != NULL && tmp -> next -> data != e ){
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
        tmp = tmp -> next;
    }
}

Node * search ( T e ) {
    Node * tmp = head;
    while ( tmp != NULL ){
        if ( tmp -> data == e ){
            return tmp;
        }
        tmp = tmp -> next;
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
    while( tmp -> next -> data != e ){
        tmp = tmp -> next;
    }
    
    Node * d = tmp -> next;
    tmp -> next = d -> next;
    free(d);
}

void shift(){
    Node * tmp = head;
    head = tmp -> next;
    free(tmp);
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
    while( tmp -> next -> next != NULL ){
        tmp = tmp -> next;
    }
    
    tmp -> next = NULL;
    tail = tmp;
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
    insertAfter("grape", "something");
    
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
