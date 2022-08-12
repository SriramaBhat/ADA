//Program to find gcd using modulo operator
#include<stdio.h>
int count = 0;

int gcdModulo (int m, int n) {
    int rem;
    while(n!=0) {
        count++;
        rem = m%n;
        m = n;
        n = rem;
    }
    return m;
}

void main() {
    int m, n;
    printf("\nEnter the two numbers whose gcd is to be found:\n");
    scanf("%d%d", &m, &n);
    printf("\nGCD of the given numbers is %d\n", gcdModulo(m,n));
    printf("\nThe basic operation count is %d\n", count);
}