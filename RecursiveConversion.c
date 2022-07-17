# include <stdio.h>

// Name: Ruhail Mir
// Roll No: 64
// 4th Sem CSE

int convertTo(int number, int base){
    if ( number == 0 ) return 0;
    convertTo( number / base, base );
    int R = (number % base);
    if ( base == 16 && R > 9)
        printf("%c ",  R + 55);
    else
        printf("%d ", R);
}

int main() {
    int number, base;
    printf("Enter the number to convert : ");
    scanf("%d", &number);
    printf("Enter the base to convert the number to: ");
    scanf("%d", &base);
    
    printf("%d in base %d is : \n", number, base);
    convertTo( number, base );
    return 0;
}
