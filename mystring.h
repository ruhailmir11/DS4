# include <stdbool.h>
# include <assert.h>
# include <stdlib.h>

# define CHAR_DIFF -32;

int len( char * string ){
	int len = 0;
	while ( *string++ != '\0' ){
		len++;
	}
	return len;}

bool cmp( char * s1, char * s2 ){
	int l1 = len(s1);
	int l2 = len(s2);
	
	assert( l1 == l2 );

	for ( int i = 0; i < l1; ++i ){
		if ( s1[i] != s2[i] ) return false;
	}

	return true;}

void rev ( char * string ){
	int L = len( string );
	for ( int i=0; i < L/2; i++ ){
		int start = i;
		int end = L - i - 1;
		char tmp = string[start];
		string[start] = string[end];
		string[end] = tmp;		
	}}

void cpy( char * from, char * to ){
	int l1 = len(from);
	for (int i = 0; i < l1; ++i){
		to[i] = from[i];
	}}

void upper( char * string ){
	int L = len(string);
	for (int i = 0; i < L; ++i) {
		if ( string[i] >= 'a' && string[i] <= 'z' ){
			string[i] += CHAR_DIFF;
		}
	}}

char * substr( char * string, int from, int to ){
	int L = len(string);
	assert( from >= 0 );
	assert( to <= L );
	int D = ( to - from );
	char * out = ( char * ) malloc (sizeof(D+2) * sizeof(char));
	for (int i = from; i < to; ++i){
		out[ i-from ] = string[i];
	}
	return out;}

bool includes( char * string, char * word ){
	int l1 = len(string);
	int l2 = len(word);

	for (int i = 0; i < l1-l2+1; i++){
		char * sub = substr( string, i, i+l2);
		if ( cmp( sub, word ) ) return true;
	}

	return false;}

bool areEqual ( char * text, char * pat ){

	if ( *text == '\0' && *pat != '\0' ) return false;

	if ( *pat == '\0' ) return true;

	if ( *text == *pat ) return areEqual( text + 1, pat + 1 );

	return false;}

bool rincludes( char * text, char * pat ){
	if ( *text == '\0' ) return false;

	if ( *text == *pat && areEqual( text, pat ))
			return 1;
		else
			return rincludes( text + 1, pat );

	return rincludes( text+1, pat );}

bool isPalindrome( char * string ){
	int L = len( string );
	char * copy = (char *) malloc (sizeof(L) * sizeof(char));
	cpy( string, copy );
	rev( copy );
	return cmp( string, copy );}
