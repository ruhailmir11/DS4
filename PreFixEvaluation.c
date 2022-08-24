# include<stdio.h>
# include<string.h>
# include<math.h>
# include<stdlib.h>
# include "Stack.h"

/*
	Roll No: CSE_LE_64
	Sem: 4th
*/

char * prefixEvaluation( char * exp ){
	for (int i = strlen( exp )-1; i >= 0; i-- ){
		char c = exp[i];
		
		if( c >= '0' && c <= '9' ){
			char c_str[] = { c, '\0' };
			push( atoi( c_str ) );
			
		} else {
			
			int a = pop();
			int b = pop();
			
			switch ( c ){
				case '+':
					push( a + b );
					break;
				case '-':
					push( a - b );
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
	char expression[] = "-+7*45+20";
	char * output = prefixEvaluation( expression );
	printf("OUTPUT: %s\n", output);
	
	return 0;
}