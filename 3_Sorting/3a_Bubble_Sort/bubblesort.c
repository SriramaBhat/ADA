//Program to perform analysis of bubblu sort
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define INITIAL 10
#define FINAL 100
#define INCRE 10
int count = 0;

void printArray (int *arr, int n) {
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
}

void bubbleSort(int *arr, int n, char *name) {
    printf("\nBefore Sorting:\n");
    printArray(arr,n);
    FILE *fp = fopen(name, "a");
    int flag = 0;
    count = 0;
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-1-i; j++) {
            count++;
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            }
        }
        if(flag == 0)
            break;
        flag = 0;
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
        bubbleSort(arr, n, "Best_Case.txt");
        
        //For Average Case
        for(int i=0; i<n; i++)
            arr[i] = rand()%n;
        bubbleSort(arr, n, "Avg_Case.txt");

        //For Worst Case
        for(int i=0; i<n; i++)
            arr[i] = (n-i);
        bubbleSort(arr, n, "Worst_Case.txt");
    }

    system("gnuplot -p -c cmd.txt"); 
}