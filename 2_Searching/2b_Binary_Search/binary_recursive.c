//Program to perform analysis of binary search
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define INITIAL 10
#define FINAL 100
#define INCRE 10
int count = 0;

int binarySearch(int *arr, int low, int high, int key) {
    count++;
    int mid = (low+high)/2;
    if(low > high) {
        return -1;
    }else if(arr[mid] == key) {
        return mid;
    } else if(key < arr[mid]) {
        binarySearch(arr, low, (mid-1), key);
    } else {
        binarySearch(arr, (mid+1), high, key);
    }
}

void bsImpl (int *arr, int n, int key, char *name) {
    FILE *fp = fopen(name, "a");
    count = 0;
    printf("\nThe position of the element is %d\n", binarySearch(arr, 0, n-1, key));
    fprintf(fp, "%d\t%d\n", n, count);
    fclose(fp);
}

void main() {
    int *arr, n;
    char name[25];
    system("rm -f *_Case.txt");
    for(n=INITIAL; n<=FINAL; n+=INCRE) {
        arr = (int *)malloc(n*sizeof(int));
        for(int i=0; i<n; i++)
            arr[i] = i;
        bsImpl(arr, n, arr[(n-1)/2], "Best_Case.txt");
        bsImpl(arr, n, rand()%n, "Avg_Case.txt");
        bsImpl(arr, n, 9999, "Worst_Case.txt");
    }
    system("gnuplot -p -c Command.txt");
}