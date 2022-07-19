
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

/*
    ROLL NO: CSE_LE_64
    SEM: 4th
*/

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
    else {
        printf("List Empty !\n");
        return false;
    }
}

int indexOf( int element ){
    int index = 0;
    Node * tmp = root;
    while( tmp != NULL ){
        if ( tmp -> data == element ){
            return index;
        }
        index++;
        tmp = tmp -> next;
    }
    return -1;
}

bool unshift( int data ){
    Node * new_ = ( Node * ) malloc ( sizeof(Node) );
    new_ -> data = data;
    new_ -> next = root;
    root = new_;
    size++;
    return true;
}

bool insertBefore( int element, int data ){
    Node * tmp = root;
    
    if ( indexOf ( element ) == 0 ){
        unshift( data );
        return;
    }
    
    while ( tmp -> next != NULL && tmp -> next -> data != element){
        tmp = tmp -> next;
    }
    
    if ( tmp == NULL ){
        printf("Element %d is not in the List ! \n", element);
        return false;
    }
    
    Node * new_ = (Node *) malloc ( sizeof (Node) );
    new_ -> data = data;
    new_ -> next = tmp -> next;
    tmp -> next = new_;
    size++;
    
    return true;
}

bool insertAfter( int element, int data ){
    Node * tmp = root;
    
    while ( tmp != NULL && tmp -> data != element){
        tmp = tmp -> next;
    }
    
    if ( tmp == NULL ){
        printf("Element %d is not in the List ! \n", element);
        return false;
    }
    
    Node * new_ = (Node *) malloc ( sizeof (Node) );
    new_ -> data = data;
    new_ -> next = tmp -> next;
    tmp -> next = new_;
    size++;
    
    return true;
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
    
    printList();
    
    // remove last element ...
    if ( pop() ){
        printf("Last element removed !\n");
    }
    
    printList();
    
    // Add the element "7" at the beginning ...
    if ( unshift ( 7 ) ){
        printf("Item added to the beginning ! \n");
    }
    
    printList();
    
    // is "5" in the list ...
    Node * t;
    if ( ( t =search ( 5 ) ) != NULL ){
        printf( "%d is in the list\n", t -> data );
    }
    
    // Insert Element "9" after Element "5"
    if ( insertAfter( 5, 9 ) ){
        printf("Element inserted after the given element !\n");
    }
    
    printList();
    
    // Insert Element "3" before Element "7"
    if( insertBefore( 7, 2 ) ){
        printf("Element inserted before the given element !\n");
    }
    
    printList();
    return 0;
}
