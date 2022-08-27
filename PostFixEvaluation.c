# include<stdio.h>
# include<string.h>
# include<math.h>
# include<stdlib.h>
# include "Stack.h"

/*
	Roll No: CSE_LE_64
	Sem: 4th
*/

char * postfixEvaluation( char * exp ){
	for (int i = 0; i < strlen( exp ); i++ ){
		char c = exp[i];
		
		if( c >= '0' && c <= '9' ){
			push( c - '0' );
			
		} else {
			
			int b = pop();
			int a = pop();
			
			switch ( c ){
				case '+':
					push( a + b );
					break;
				case '-':
					push( a - b );
					break;
				case '/':
					push( a / b );
					break;
				case '*':
					push( a * b );
					break;
				case '^':
					push( (int) pow( (double) a, (double) b ) );
					break;
					
				default:
					break;
			}
		}
	}
	
	char * out = (char *) malloc(sizeof(char) * 5);
	itoa( pop(), out, 10 );
	return out;
}

int main(){
	char expression[] = "46+2/5*7+";
	char * output = postfixEvaluation( expression );
	printf("OUTPUT: %s\n", output);	
	return 0;
}
