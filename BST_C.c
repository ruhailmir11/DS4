#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
    NAME: Ruhail Maqbool Mir
    ROLL NO: CSE_20_LE_64
*/

/* Utils */
bool isPrime( int n ){
    for( int i=2; i < n; i++ ){
        if( n % i == 0 ) {
            return false;
        }
    }
    return true;
}

/* Utils END */

/* Node START */

typedef struct Node {
    struct Node * left;
    struct Node * right;
    int data;
} Node;

Node * nodeRoot;

Node * nodeInsert( Node * root, Node * node ){
    if( root == NULL ){
        root = node;
        return root;
    } else {
        if( node -> data < root -> data ){
            if( root -> left == NULL ) root -> left = node;
            else {
                nodeInsert( root -> left, node );
            }
        } else {
            if( root -> right == NULL ) root -> right = node;
            else {
                nodeInsert( root -> right, node );
            }
        }
    }
}

void nodePre( Node * root ){
    if ( root == NULL ) return;
    printf("%d, ", root -> data);
    if( root -> left != NULL ) nodePre( root -> left );
    if( root -> right != NULL ) nodePre( root -> right );
}

void nodeIn( Node * root ){
    if ( root == NULL ) return;
    if( root -> left != NULL ) nodePre( root -> left );
    printf("%d, ", root -> data);
    if( root -> right != NULL ) nodePre( root -> right );
}

void nodePost( Node * root ){
    if ( root == NULL ) return;
    if( root -> left != NULL ) nodePre( root -> left );
    if( root -> right != NULL ) nodePre( root -> right );
    printf("%d, ", root -> data);
}

void nodePrimesInOrder( Node * root ){
    if ( root == NULL ) return;
    if( root -> left != NULL ) nodePrimesInOrder( root -> left );
    
    if( isPrime ( root -> data ) ){
        printf("%d, ", root -> data);
    }
    
    if( root -> right != NULL ) nodePrimesInOrder( root -> right );
}

void nodeEvensIn( Node * root ){
    if ( root == NULL ) return;
    if( root -> left != NULL ) nodeEvensIn( root -> left );
    if( root -> data % 2 == 0 ){
        printf("%d, ", root -> data);
    }
    if( root -> right != NULL ) nodeEvensIn( root -> right );
}

void nodeOddsIn( Node * root ){
    if ( root == NULL ) return;
    if( root -> left != NULL ) nodeOddsIn( root -> left );
    if( root -> data % 2 != 0 ){
        printf("%d, ", root -> data);
    }
    if( root -> right != NULL ) nodeOddsIn( root -> right );
}

/* Node END */

/* Tree Start */

void treeInsert( int value ){
    Node * n = ( Node * ) malloc (sizeof( Node ));
    n -> data = value;
    
    if( nodeRoot == NULL ){
        nodeRoot = nodeInsert( nodeRoot, n );
    } else {
        nodeInsert( nodeRoot, n );
    }
}

void treePrintPre(){
    nodePre( nodeRoot );
    printf("\n");
}

void treePrintIn(){
    nodeIn( nodeRoot );
    printf("\n");
}

void treePrintPost(){
    nodePost( nodeRoot );
    printf("\n");
}

void treePrintPrimesInOrder(){
    nodePrimesInOrder( nodeRoot );
    printf("\n");
}

void treePrintEvensInOrder(){
    nodeEvensIn( nodeRoot );
    printf("\n");
}

void treePrintOddsInOrder(){
    nodeOddsIn( nodeRoot );
    printf("\n");
}

Node * treeRightMin( Node * root ){
    Node * tmp = root -> right;
    while( tmp -> left != NULL ){
        tmp = tmp -> left;
    }
    return tmp;
}

Node * treeLeftMax( Node * root ){
    Node * tmp = root -> left;
    while( tmp -> right != NULL ){
        tmp = tmp -> right;
    }
    return tmp;
}

Node * treeDeleteNode( Node * root, int value ){
    if( value > root -> data ) root -> right = treeDeleteNode( root -> right, value );
    else if ( value < root -> data ) root -> left = treeDeleteNode( root -> left, value );
    else {
        if( root -> left == NULL && root -> right == NULL ){
            // Delete Left Node ...
            root = NULL;
            free(root);
        } else if ( root -> right == NULL ){
            // Has Left Subtree ...
            Node * tmp = root -> left;
            free(root);
            return tmp;
        } else if ( root -> left == NULL ){
            // Has Right Subtree ...
            Node * tmp = root -> right;
            free(root);
            return tmp;
        } else {
            // Has both ...
            Node * minNode = treeLeftMax( root );
            root -> data = minNode -> data;
            root -> left = treeDeleteNode( root -> left, minNode -> data );
        }
    }
    
    return root;
}

void treeDelete( int value ){
    treeDeleteNode( nodeRoot, value );
}

/* Tree END */

int main() {
    int A[] = { 55, 39, 30, 24, 15, 11, 22, 33, 58, 99 };
    int N = sizeof(A) / sizeof(A[0]);
    
    for( int i=0; i < N; i++ ){
        treeInsert( A[i] );
    }
    
    printf("Current tree State (In Order): \n");
    treePrintIn();
    
    printf("\nPrimes in the Tree (In Order): \n");
    treePrintPrimesInOrder();
    
    printf("\nEven numbers in the Tree (In Order): \n");
    treePrintEvensInOrder();
    
    printf("\nOdd numbers in the Tree (In Order): \n");
    treePrintOddsInOrder();
    
    printf("\nDeleting: 11, 55, 99, 24\n");
    
    treeDelete( 11 );
    treeDelete( 55 );
    treeDelete( 99 );
    treeDelete( 24 );
    
    printf("\nTree After Deleting: \n");
    treePrintPre();
    
    printf("\n\nDone \n");
    return 0;
}

// ..... End .... //
