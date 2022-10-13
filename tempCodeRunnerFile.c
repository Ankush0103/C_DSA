// Graph BFS
#include<stdio.h>
#include<stdlib.h>
#include"QueueBFS.c"
#define N 10
struct Graph
{
	int vertex;
	int edge;
	int **addMatrix;
};

struct Graph * createGraph(int v, int e)
{
	int i, j;
	struct Graph *g;
	g = (struct Graph *)malloc(sizeof(struct Graph));
	g->vertex = v;
	g->edge = e;
	g->addMatrix = (int **)malloc(g->vertex * sizeof(int *));
	
	for(i=0; i<g->vertex; i++)
	{
		g->addMatrix[i] = (int *)malloc(g->vertex * sizeof(int ));
		
		for(j=0; j<g->vertex; j++)
			g->addMatrix[i][j] = 0;
	}
	return g;
}

struct Graph * addEdge(struct Graph *g, int v1, int v2)
{
	g->addMatrix[v1][v2] = 1;
	g->addMatrix[v2][v1] = 1;
	return g;
}

void displayGraph(struct Graph *g)
{
	for(int i =0; i< g->vertex; i++)
	{
		for (int j = 0; j< g->vertex; j++)
			printf("%d ",g->addMatrix[i][j]);
		printf("\n");
	}
}

void BFS(struct Graph *g, int snode)
{
	int j; 
	int x;
	int * visited;
	struct queue *q = createQueue(10);
	
	visited = (int *)malloc(g->vertex * sizeof(int ));
	for(int j = 0; j<g->vertex; j++)
	{
		visited[j] = 0;
	}
	
	visited[snode] = 1;
	enqueue(q, snode);
	
	while(!isEmpty(q))
	{
		x = dequeue(q);
		printf("%d ", x);
		
		for(int j = 0; j<g->vertex; j++)
		{
			if(visited[j] == 0 && g->addMatrix[x][j]==1)
			{
				enqueue(q, j);
				visited[j] = 1;
			}			
		}
	}

}
			

int main()
{
	int edge; int vertex;
	struct Graph *g;

	printf("Enter the number of vertex and edge\n");
	scanf("%d%d", &vertex, &edge);
	g = createGraph(vertex, edge);
	for(int i = 0; i<edge; i++)
	{
		int v1, v2;
		printf("enter the start and end vertex of an edge\n");
		scanf("%d%d", &v1, &v2);
		g = addEdge(g, v1, v2);
	}
	printf("\nDisplaying matrix\n");
	displayGraph(g);
	//BFS Implementation
	int n;
	printf("Enter the value of start node b: \n");
	scanf("%d", &n);
	printf("Breadth First Saerch: \n");
	BFS(g, n);
	return 0;
}