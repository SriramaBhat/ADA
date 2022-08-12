//Program to perform analysis of quick sort
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define INITIAL 10
#define FINAL 100
#define INCRE 10
int count = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int *arr, int n) {
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
}

int partition(int *arr, int beg, int end) {
    int pivot=arr[beg];
    int i = beg, j = end+1;
    do {
        do {
            count++;
            i++;
        } while(arr[i] < pivot);

        do {
            j--;
            count++;
        } while(arr[j] > pivot);

        swap(&arr[i], &arr[j]);
    } while(i<j);
    swap(&arr[i], &arr[j]);
    swap(&arr[beg], &arr[j]);
    return j;
}

void quickSort (int *arr, int beg, int end) {
    if(beg < end) {
        int split = partition(arr, beg, end);
        quickSort(arr, beg, split-1);
        quickSort(arr, split+1, end);
    }
}

void quickImp (int *arr, int n, char *name) {
    count=0;
    printf("\nBefore Sorting:\n");
    printArray(arr, n);
    FILE *fp = fopen(name, "a");
    quickSort(arr, 0, n-1);
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
            arr[i] = 5;
        quickImp(arr, n, "Best_Case.txt");

        //For Worst Case
        for(int i=0; i<n; i++)
            arr[i] = n-i;
        quickImp(arr, n, "Worst_Case.txt");

        //For Average Case
        for(int i=0; i<n; i++)
            arr[i] = rand()%n;
        quickImp(arr, n, "Avg_Case.txt");
    }

    system("gnuplot -p -c cmd.txt"); 
}