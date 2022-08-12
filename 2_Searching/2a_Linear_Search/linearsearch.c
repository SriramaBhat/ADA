//Program to perform analysis of linear search
#include<stdio.h>
#include<stdlib.h>
#define INITIAL 10
#define FINAL 100
#define INCRE 10
int count = 0;

int linearSearch (int *arr, int n, int key, char *name) {
    int pos = -1;
    FILE *fp = fopen(name, "a");
    for(int i=0; i<n; i++) {
        count++;
        if(arr[i] == key) {
            pos = i;
            break;
        }
    }
    fprintf(fp, "%d\t%d\n", n, count);
    fclose(fp); count = 0;
    return pos;
}

void main () {
    int n, *arr, key, pos;
    char name[25];
    system("rm -f *_Case.txt");
    for(n=INITIAL; n<= FINAL; n+=INCRE) {
        arr = (int *)malloc(n*sizeof(int));
        for(int i=0; i<n; i++) {
            arr[i] = (i+1);
        }
        arr[(n-1)/2] = -15;
        pos = linearSearch(arr, n, 1, "Best_Case.txt");
        printf("\nKey found in %d position\n", pos);
        pos = linearSearch(arr, n, -15, "Avg_Case.txt");
        printf("\nKey found in %d position\n", pos);
        pos = linearSearch(arr, n, 999, "Worst_Case.txt");
        printf("\nKey found in %d position\n", pos);
    }
    system("gnuplot -p -c cmd.txt");
}