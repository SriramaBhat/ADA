//Find the gcd of two numbers using subtraction
#include<stdio.h>
int count = 0;

int gcdSubtraction (int m, int n) {
    while(m != n) {
        if(m > n) {
            m -= n;
            count++;
        } else {
            n -= m;
            count++;
        }
    }

    return m;
}

void main() {
    int m,n;
    printf("\nEnter the two numbers whose gcd is to be found:\n");
    scanf("%d%d", &m,&n);
    printf("\nGCD of the given numbers is %d\n", gcdSubtraction(m,n));
    printf("\nThe basic operation count is %d\n", count);
}
