//DFS for topological sorting
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int count = 0, top = -1;
int stack[MAX];

void dfs(int graph[][MAX], int visited[], int n, int start);
void topologicalSort(int graph[][MAX], int visited[], int n);

void main() {
    int n, graph[MAX][MAX], visited[MAX], i, j;
    printf("\nEnter the number of nodes in the graph:\n");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix:\n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf("%d", &graph[i][j]);
        }
        visited[i] = 0;
    }

    printf("\nThe topological order is:\n");
    topologicalSort(graph, visited, n);  
    for(i=n-1; i>=0; i--){
        printf(" =>%c", stack[i] + 65);
    }
}

void topologicalSort(int graph[][MAX], int visited[], int n) {
    int i;
    for(i=0; i<n; i++){
        if(visited[i] == 0){
            dfs(graph, visited, n, i);
        }
    }
    return;
}

void dfs(int graph[][MAX], int visited[], int n, int start) {
    int i;
    visited[start] = 1;
    for(i=0; i<n; i++){
        if(graph[start][i] && visited[i] == 0) {
            dfs(graph, visited, n, i);
        }
    }
    stack[++top] = start;
    return;
}
