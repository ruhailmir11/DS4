# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include "StackConv.h"

/* 
	Name: Ruhail Mir
	Roll No: 64
	4th Sem CSE
*/

int priority( char c ){
	if ( c == '^' ) return 5;
	else if ( c == '*' || c == '/' ) return 4;
	else if ( c == '+' || c == '-' ) return 3;
	else return 0;
}

bool isOperand( char c ){
	return (c >= '0' && c <= '9');
}

char * infixToPostfix( char * input ){
	char * postfix = (char *) malloc (sizeof ( char ) * strlen( input ));
	int k = 0; char x;
	
	for( int i=0; i < strlen(input); i++ ){
		char c = input[i];
		if ( isOperand( c ) ){
			postfix[k++] = c;
		} else if ( c == '(' ){
			push( c );
		} else if ( c == ')' ){
			while((x = pop()) != '('){
				postfix[k++] = x;
			}
		} else {
			while( priority( stackTop() ) >= priority( c ) ){
				postfix[k++] = pop();
			}
			push(c);
		}
	}
	
	postfix[k] = '\0';
	return postfix;
}

char * infixToPrefix( char * inputO ){
	// A little preprocessing ...
	char * input = strrev( inputO );
	
	for( int i=0; i < strlen(inputO); i++ ){
		if ( input[i] == '(' ) input[i] = ')';
		else if ( input[i] == ')' ) input[i] = '(';
	}
	
	char * prefix = infixToPostfix( input );
	return strrev( prefix );
}

int main(){
	char infix[] = "(4^5+5*7-9)";
	
	printf("Infix: %s\n", infix);
	printf("Postfix: %s\n", infixToPostfix( infix ));
	printf("Prefix: %s\n", infixToPrefix( infix ));
	
	return 0;
}

