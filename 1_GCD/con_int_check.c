//find gcd using consecutive integer checking
#include<stdio.h>
int count = 0;

int conIntCheck(int m, int n) {
    int min = (m<n) ? m : n;
    int temp1, temp2;
    while(min != 1) {
        count++;
        temp1 = m%min;
        if(temp1 == 0) {
            temp2 = n%min;
        }
        if(temp2 == 0) {
            return min;
        }
        min--;
    }
    return 1;
}

void main() {
    int m, n;
    printf("\nEnter the two numbers whose gcd is to be found:\n");
    scanf("%d%d", &m, &n);
    printf("\nGCD of the given numbers is %d\n", conIntCheck(m,n));
    printf("\nThe basic operation count is %d\n", count);
}