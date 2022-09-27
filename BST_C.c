#include <stdio.h>
#include <stdlib.h>

/*
    NAME: Ruhail Maqbool Mir
    ROLL NO: CSE_20_LE_64
*/

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
    
    printf("Before Deleting: \n");
    treePrintPre();
    
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
