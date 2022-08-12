//Topological DFS
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int graph[MAX][MAX], visited[MAX], count=0;
int stack[MAX], top=-1;

void dfs(int n, int start) {
    visited[start] = 1;
    for(int i=0; i<n; i++)
        if(graph[start][i] && visited[i]==0)
            dfs(n, i);
    stack[++top] = start;
}

void main() {
    int n;
    printf("\nEnter the number of vertices:\n");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) 
            scanf("%d", &graph[i][j]);
        visited[i] = 0;
    }
    
    printf("\nTopological Order:\n");
    for(int i=0; i<n; i++) {
        if(visited[i] == 0)
            dfs(n, i);
    }
    
    for(int i=n-1; i>=0; i--) {
        printf(" --> %c", stack[i]+65);
    }
}
