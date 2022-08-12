//Program to perform the analysis of Insertion Sort
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

void insertionSort(int *arr, int n, char *name) {
    count = 0;
    printf("\nBefore Sorting:\n");
    printArray(arr, n);
    FILE *fp = fopen(name, "a");
    for(int i=1; i<n; i++) {
        int value = arr[i];
        int j= i-1;
        while(count++ && arr[j] > value) {
            arr[j+1] = arr[j];
            j--;
            if(j<0)
                break;
        }
        arr[j+1] = value;
    }
    printf("\nAfter Sorting:\n");
    printArray(arr, n);
    fprintf(fp, "%d\t%d\n", n, count);
    fclose(fp);
}

void main() {
    int *arr, n;
    system("rm -f *_Case.txt");
    srand(time(NULL));
    for(n = INITIAL; n<=FINAL; n+=INCRE) {
        arr = (int *)malloc(n*sizeof(int));

        //For Best case
        for(int i=0; i<n; i++)
            arr[i] = (i+1);
        insertionSort(arr, n, "Best_Case.txt");
        
        //For Average Case
        for(int i=0; i<n; i++)
            arr[i] = rand()%n;
        insertionSort(arr, n, "Avg_Case.txt");

        //For Worst Case
        for(int i=0; i<n; i++)
            arr[i] = (n-i);
        insertionSort(arr, n, "Worst_Case.txt");
    }

    system("gnuplot -p -c cmd.txt"); 
}