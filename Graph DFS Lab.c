//Graph
#include<stdio.h>
#include<stdlib.h>
#include"StackDFS.c"
#define N 10
struct Graph{
    int vertex;
    int edge;
    int **addMatrix;
};

struct Graph * createGraph(int v, int e){
    int i, j;
    struct Graph *g;
    g = (struct Graph *)malloc(sizeof(struct Graph));
    g->vertex = v;
    g->edge = e;
    g->addMatrix = (int **)malloc(g->vertex * sizeof(int *));
    for(i=0;i<g->vertex;i++){
        g->addMatrix[i] = (int *)malloc(g->vertex * sizeof(int));
        for(j=0;j<g->vertex;j++)
            g->addMatrix[i][j] = 0; //Question Mark
    }
    return g;
}

struct Graph * addEdge(struct Graph *g, int v1, int v2){
    g->addMatrix[v1][v2] = 1;
    g->addMatrix[v2][v1] = 1;
    return g;
}

void displayGraph(struct Graph * g){
    for(int i = 0; i<g->vertex; i++){
        for(int j = 0; j<g->vertex;j++)
            printf("%d ", g->addMatrix[i][j]);
        printf("\n");
    }
}

void DFS(struct Graph *g, int snode){
    int j, x;
    int *visited;
    struct stack *s = createStack(10);
    visited = (int *)malloc(g->vertex*sizeof(int));
    for(int j = 0; j<g->vertex; j++)
        visited[j] = 0;
    visited[snode] = 1;
    push(s, snode);
    while(!isEmpty(s))
    {
        x = pop(s);
        printf("%d ", x);
        for(int j = 0; j<g->vertex; j++){
            if(visited[j]==0 && g->addMatrix[x][j]==1){
                push(s, j);
                visited[j] = 1;
            }
        }
    }
}

int main(){
    int edge; int vertex;
    struct Graph *g;
    printf("Enter the number of vertex and edge in the graph\n");
    scanf("%d%d", &vertex, &edge);
    g = createGraph(vertex, edge);
    for(int i = 0; i<edge; i++){
        int v1, v2;
        printf("Enter the start and end vertex of a node\n");
        scanf("%d%d", &v1, &v2);
        g = addEdge(g, v1, v2);
    }
    printf("\nDipalying matrix\n");
    displayGraph(g);
    int n;
    printf("Enter the value of start node: \n");
    scanf("%d", &n);
    printf("Depth First Search: \n");
    DFS(g, n);
}