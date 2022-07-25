# include <stdio.h>
# include "LL.h"

/*
    Roll No: CSE_LE_64
    Sem: 4th
*/

// custom type ...
typedef struct Student {
    char * name;
    int roll;
    char * dept;
    int marks;
} Student;

// custom print function ...
void printStudent( T data ){
    Student * s = (Student *)(data);
    printf("%s\t%d\t%s\t%d\n", s -> name, s -> roll, s -> dept, s -> marks);
}

int main(){
    // Creating dummy student data ...
    Student st1;
    st1.name = "A";
    st1.roll = 1;
    st1.dept = "CSE";
    st1.marks = 100;

    Student st2;
    st2.name = "B";
    st2.roll = 2;
    st2.dept = "ECE";
    st2.marks = 100;

    Student st3;
    st3.name = "C";
    st3.roll = 3;
    st3.dept = "CSE";
    st3.marks = 100;
    
    // Storing the students in the list ...
    push( &st1 );
    push( &st2 );
    push( &st3 );

    // Printing the students ...
    printf("%s\t%s\t%s\t%s\n", "Name", "Roll", "Dept", "Marks");
    print( printStudent );
    return 0;
}

// END ...
