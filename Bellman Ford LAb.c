// Bellman Ford lab
#include<stdio.h>
#include<stdlib.h>
//#define INT_MAX 9999
struct Edge{
    int source, destination, weight;
};

struct Graph{
    int V, E;
    struct Edge* edge; // This structure contain another structure which we already created edge.
};

struct Graph* createGraph(int V, int E){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph)); // Allocating space of structure again
    graph->V = V; //assigning values to structure element taken from user.
    graph->E = E;
    graph->edge = (struct Edge *)malloc(graph->E*sizeof(struct Edge));
    // Creating Edge type structure inside graph structure
    // Number of edge type structure is equal to number of edges.
    return graph;
}

void solution(int dist[], int n){
    int i;
    printf("\nVertex\t Distance from souce Vertex\n");
    for(i=0; i<n; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void BellmanFord(struct Graph* graph, int source){
    int V = graph->V;
    int E = graph->E;
    int storedist[V];
    int i, j;
    /* Now we initialise all distance to infinity except source.
        We assign source distance as zero.*/
    for(i = 0; i<V; i++)
        storedist[i] = INT_MAX;
    storedist[source] = 0;
    // We do v-1 relaxation because shortest path containing V vertex, never contain V-1 edges.
    for(i=1; i<= V-1; i++)
    {
        for(j=0; j<E; j++)
        {
            int u = graph->edge[j].source;
            int v = graph->edge[j].destination;
            int weight = graph->edge[j].weight;
            if(storedist[u] + weight < storedist[v])
                storedist[v] = storedist[u] + weight;
        }
    }
    // Now check if negative cycle exists or not
    // If we get shorter path then there is negative edge cycle
    for(i=0; i<E; i++)
    {
        int u = graph->edge[i].source;
        int v = graph->edge[i].destination;
        int weight = graph->edge[i].weight;
        if(storedist[u] + weight < storedist[v])
            printf("the graoh contain negative edge cycle");
    }
    solution(storedist, V);
}

int main(){
    int V, E, S;
    printf("enter number of vertices, edges and source vertex of the graph respectively: \n");
    scanf("%d  %d  %d", &V,  &E,  &S);
    struct Graph* graph = createGraph(V, E);
    int i;
    for(i = 0; i<E; i++){
        printf("Edge edge%d properties Source, destination, weight respectively\n", i+1);
        scanf("%d", &graph->edge[i].source);
        scanf("%d", &graph->edge[i].destination);
        scanf("%d", &graph->edge[i].weight);
    }
    BellmanFord(graph, S);//Passing created graph and source vertex to Bellman Ford algorithm
    return 0;
}

