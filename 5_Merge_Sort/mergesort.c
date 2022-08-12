//Program to perform analysis of merge sort
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

void merge(int *arr, int beg, int mid, int end) {
    int i, j, k;
    int n1 = (mid-beg)+1;
    int n2 = end - mid;
    int left[n1], right[n2];

    for(i=0; i<n1; i++)
        left[i] = arr[beg+i];
    for(j=0; j<n2; j++)
        right[j] = arr[mid+1+j];
    i=0; j=0; k=beg;
    while(i<n1 && j<n2) {
        count++;
        if(left[i] <= right[j])
            arr[k] = left[i++];
        else
            arr[k] = right[j++];
        k++;
    }

    while(i<n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while(j<n2) {
        arr[k] = right[j];
        j++;
        k++;
    }

}

void mergeSort (int *arr, int beg, int end) {
    if(beg < end) {
        int mid = (beg+end)/2;
        mergeSort(arr, beg, mid);
        mergeSort(arr, (mid+1), end);
        merge(arr, beg, mid, end);
    }
}

void worst(int arr[], int beg, int end){
    if (beg < end){
        int mid = (beg + end)/2;
        int n1 = mid - beg + 1;
        int n2 = end - mid;

        int a[n1], b[n2];
        for(int i = 0; i<n1; ++i)
            a[i] = arr[2*i];
        for(int j = 0; j<n2; ++j)
            b[j] = arr[2*j + 1];

        worst(a, beg, mid);
        worst(b, mid + 1, end);

        int i, j;
        for(i = 0; i<n1; ++i)
            arr[i] = a[i];
        for(j = 0; j<n2; ++j) 
            arr[i+j] = b[j];
    }
}

void mergeImp(int *arr, int n, char *name) {
    count = 0;
    printf("\nBefore Sorting:\n");
    printArray(arr, n);
    FILE *fp = fopen(name, "a");
    mergeSort(arr, 0, n-1);
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
        mergeImp(arr, n, "Best_Case.txt");

        //For Worst Case
        worst(arr, 0, n-1);
        mergeImp(arr, n, "Worst_Case.txt");

        //For Average Case
        for(int i=0; i<n; i++)
            arr[i] = rand()%n;
        mergeImp(arr, n, "Avg_Case.txt");
    }

    system("gnuplot -p -c cmd.txt"); 
}