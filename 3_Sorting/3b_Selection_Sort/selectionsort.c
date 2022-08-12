//Program to perform analysis of selection sort
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define INITIAL 10
#define FINAL 100
#define INCRE 10
int count = 0;

void printArray(int *arr, int n) {
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
}

void selectionSort(int *arr, int n, char *name) {
    count = 0;
    printf("\nBefore Sorting:\n");
    printArray(arr, n);
    FILE *fp = fopen(name, "a");
    int min, pos;
    for(int i=0; i<n; i++) {
        min = arr[i]; pos = i;
        for(int j=i+1; j<n; j++) {
            count++;
            if(min > arr[j]) {
                min = arr[j];
                pos = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temp; 
    }

    printf("\nAfter Sorting:\n");
    printArray(arr, n);
    fprintf(fp, "%d\t%d\n", n, count);
    fclose(fp);
}

void main() {
    int *arr, n;
    system("rm -f Count.txt");
    srand(time(NULL));
    for(n=INITIAL; n<=FINAL; n+=INCRE) {
        arr = (int *)malloc(n*sizeof(int));
        //Selection Sort does not have best average or worst cases
        for(int i=0; i<n; i++)
            arr[i] = rand()%n;
        selectionSort(arr, n, "Count.txt");
    }
    system("gnuplot -p -c cmd.txt");
}