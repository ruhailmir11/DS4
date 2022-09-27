#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = 0, rear = -1;

void enqueue(int item) {
    if(rear < MAX-1)
        queue[++rear] = item;
    else {
        printf("OverFlow\n");
        return;
    }
}

int dequeue() {
    if( front <= rear )
        return queue[front++];
    else
        return -1;
}

void view()
{
    if(front > rear)
        printf("Empty\n");
    else {
        for(int i = front; i <= rear; i++)
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
    
    // OVerflow ...
    enqueue( 60 );
    
    printf("QUEUE STATE 2: ");
    view();
    
    // DeQueing ...
    int i1 = dequeue();
    int i2 = dequeue();
    
    printf("%d DeQueued \n", i1);
    printf("%d DeQueued \n", i2);
    
    
    printf("QUEUE STATE 3: ");
    view();
}
