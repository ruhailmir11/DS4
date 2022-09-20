#include <iostream>

/*
    Roll No: CSE_LE_64
    Sem: 4th
*/

using namespace std;

class Node {
public:
	int data;
	Node * left = nullptr;
	Node * right = nullptr;

	Node( int d ){
		data = d;
	}

	void insert( int d ){
		Node * n = new Node( d );
		if ( d < data ){
			if ( left == nullptr ){
				left = n;
			} else {
				left -> insert( d );
			}
		} else {
			if ( right == nullptr ){
				right = n;
			} else {
				right -> insert( d );
			}
		}
	}

	bool search( int dataIn ){
		if ( data == dataIn ){
			return true;
		} else if ( left != nullptr && dataIn <  data ){
			return left -> search( dataIn );
		} else if ( right != nullptr && dataIn > data ) {
			return right -> search( dataIn );
		}
		return false;
	}

	void print(){
		if( left != nullptr ) left -> print();
		cout << data << ", ";
		if( right != nullptr ) right -> print();
	}

	void printPre(){
		cout << data << ", ";
		if( left != nullptr ) left -> print();
		if( right != nullptr ) right -> print();
	}

	void printPost(){
		if( left != nullptr ) left -> print();
		if( right != nullptr ) right -> print();
		cout << data << ", ";
	}
};

class Tree {
public:
	Node * root = nullptr;

	void insert( int data ){
		if ( root == nullptr )
			root = new Node( data );
		else {
			root -> insert( data );
		}
	}

	bool search( int data ){
		return root -> search( data );
	}

	Node * deleteNode( Node * root, int value ){
		if ( root == nullptr ) return root;
		else if ( value < root -> data ) root -> left = deleteNode( root -> left, value );
		else if ( value > root -> data ) root -> right = deleteNode( root -> right, value );
		else {
			// Leaf Node ...
			if ( root -> left == nullptr && root -> right == nullptr ){
				//delete root;
				root = nullptr;
			}
			// Has Right subtree ..
			else if ( root -> left == nullptr ){
				Node * tmp = root -> right;
				delete root;
				root = tmp;
			}
			// Has Left subtree ...
			else if( root -> right == nullptr ){
				Node * tmp = root -> left;
				delete root;
				return tmp;
			}
			// Has both subtrees ....
			else {
				Node * minNode = findMinRight( root );
				root -> data = minNode -> data;
				root -> right = deleteNode( root -> right, minNode -> data );
			}
		}

		return root;
	}

	Node * findMinRight( Node * root ){
		Node * tmp = root -> right;
		while ( tmp -> left != nullptr ){
			tmp = tmp -> left;
		}
		return tmp;
	}

	void printTreePreOrder(){
		cout << "\nPreOrder Traversal" << endl;
		root -> printPre();
	}

	void printTreeInOrder(){
		cout << "\n\nInOrder Traversal" << endl;
		root -> print();
	}

	void printTreePostOrder(){
		cout << "\n\nPostOrder Traversal" << endl;
		root -> printPost();
	}
};

int main(){
	Tree tree;

	int T[] = { 9, 2, 3, 8, 13, 11, 16, 14 };

	for( int i = 0; i < 8; i++ ){
		tree.insert( T[i] );
	}

	tree.printTreePreOrder();

	tree.printTreeInOrder();

	tree.printTreePostOrder();

	cout << endl << endl;

	int number = 5;
	bool e = tree.search( number );

	if( e ){
		cout << number << " Found in the Tree !" << endl;
	} else {
		cout << number << " Isn't Found in the Tree !" << endl;
	}

	// // Deleting node "13" ...
	tree.deleteNode( tree.root, 13 );

	cout << "TREE AFTER DELETE: " << endl;
	tree.printTreeInOrder();

	return 0;
}
