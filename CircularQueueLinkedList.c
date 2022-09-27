#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node * next;
} Node;

Node * front, *rear;

void enqueue( int data ){
    Node * item = (Node *) malloc (sizeof( Node ));
    item -> data = data;
    
    if( front == NULL && rear == NULL ){
        front = item;
        rear = item;
    } else {
        rear -> next = item;
        rear = rear -> next;
        rear -> next = front;
    }
}

int dequeue(){
    if ( front == NULL  ){
        printf("Queue empty !");
        return -1;
    }
    
    Node * temp = front;
    int item = temp -> data;
    front = front -> next;
    rear -> next = front;
    free( temp );
    
    return item;
}

void view(){
    if( front == rear ){
        printf("Queue Empty !");
        return;
    }
    
    Node * ptr = front;
    while( true ){
        printf("%d, ", ptr -> data);
        if( ptr == rear ) break;
        ptr = ptr -> next;
    }
    
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    
    printf("QUEUE STATE 1: ");
    view();
    
    int i1 = dequeue();
    int i2 = dequeue();
    
    printf("%d DeQueued\n", i1);
    printf("%d DeQueued\n", i2);
    
    printf("QUEUE STATE 2: ");
    view();
    
    // It's really circular, proof :
    // Lets access Node "40" using Node "50";
    
    Node * R = rear;
    while( R -> data != 40 ){
        R = R -> next;
    }
    
    printf("Found Node %d\n", R -> data );
    return 0;
}
