#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = 0, rear = -1, count = 0;

void enqueue( int item ){
    rear = ( rear + 1 ) % ( MAX );
    queue[rear] = item;
    
    if ( count < MAX ) count++;
}

int dequeue(){
    if ( count <= 0 ){ 
        printf("Underflow \n");
        return -1;
    }
    
    int item = queue[front];
    front = ( front + 1 ) % MAX;
    return item;
}

void view(){
    if ( count <= 0 ){
        printf("Queue Empty !\n");
        return;
    }
    
    for( int i=0; i < count; i++ ){
        printf("%d, ", queue[i]);
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

    // Limit crossed, now circle back ...
    enqueue(60);
    enqueue(70);
    enqueue(80);
    enqueue(90);
    enqueue(100);
    
    printf("QUEUE STATE 2: ");
    view();
    
    
    enqueue(200);
    // Limit crossed, now circle back ...
    printf("QUEUE STATE 3: ");
    view();
    
    return 0;
}
