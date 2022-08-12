//Program to perform analysis of brute force string matching
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define INITIAL 10
#define FINAL 100
#define INCRE 10
int count = 0;

int naivestring (int *text, int *pattern, int n, int m, char *name) {
    count = 0;
    int pos = -1;
    FILE *fp = fopen(name, "a");
    for(int i=0; i<=n-m; i++) {
        int j=0;
        while(j<m) {
            count++;
            if(pattern[j] != text[i+j]) 
                break;
            j++;
        }
        if(j==m) {
            pos = i;
            break;
        }
    }
    if(pos > -1) {
        printf("\nThe string is found in position %d\n", pos);
    } else {
        printf("\nThe pattern does not exist in the text\n");
    }
    fprintf(fp, "%d\t%d\n", n, count);
    fclose(fp);
    return pos;
}

void main() {
    int *text, pattern[4], n;
    system("rm -f *_Case.txt");
    srand(time(NULL));
    for(n = INITIAL; n<=FINAL; n+=INCRE) {
        text = (int *)malloc(n*sizeof(int));
        //For Best case
        for(int i=0; i<n-1; i++)
            text[i] = 0;
        text[n-1] = 1;
        for(int j=0; j<4; j++) 
            pattern[j] = 0;
        naivestring(text, pattern, n, 4, "Best_Case.txt");

        //For Worst Case
        pattern[3] = 1;
        naivestring(text, pattern, n, 4, "Worst_Case.txt");

        //For Average Case
        for(int i=0; i<4; i++)
            pattern[i] = rand()%2;
        naivestring(text, pattern, n, 4, "Avg_Case.txt");
    }

    system("gnuplot -p -c cmd.txt"); 
}