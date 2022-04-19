// DFS algorithm in C

#include <stdio.h>
#include <stdlib.h>

struct node {
  int vertex;
  struct node* next;
};

int* queue;
int max=0;
int front=0,rear=0;

void enqueue(int data){
       if(front==rear){
       	  front=0;
       	  rear=0;
       	  queue[rear++]=data;
       	  return;
	   }	
	   if(rear<max){
	   	queue[rear++]=data;
	   }
   	
	
}

void dequeue(){
	 if(front==rear){
	 	queue[front]=-1;
       	  front=0;
       	  rear=0;
       	  return;
	   }	
	   if(front<rear){
	   	queue[front++]=-1;
	   }
}



int isEmpty(){
	if(front==rear){
		return 1;
	}
	else
	return 0;
}
struct Graph {
  int numVertices;
  int* visited;
  struct node** adjLists;
};

// DFS algo
void DFS(struct Graph* graph, int vertex) {
  struct node* adjList = graph->adjLists[vertex];
  struct node* temp = adjList;

  graph->visited[vertex] = 1;
  printf("Visited %d \n", vertex);

  while (temp != NULL) {
    int connectedVertex = temp->vertex;

    if (graph->visited[connectedVertex] == 0) {
      DFS(graph, connectedVertex);
    }
    temp = temp->next;
  }
  int i=0;
   for(i=0;i<graph->numVertices;i++){
  	if(graph->visited[i]==0)DFS(graph,i);
  }
}

void bfs(struct Graph* graph, int startVertex) {

  graph->visited[startVertex] = 1;
  enqueue(startVertex);

  while (!isEmpty()) {
    int currentVertex = queue[front];
    dequeue();
    printf("Visited %d\n", currentVertex);

    struct node* temp = graph->adjLists[currentVertex];

    while (temp) {
      int adjVertex = temp->vertex;

      if (graph->visited[adjVertex] == 0) {
        graph->visited[adjVertex] = 1;
        enqueue(adjVertex);
      }
      temp = temp->next;
    }
  }
  int i=0;
  for(i=0;i<graph->numVertices;i++){
  	if(graph->visited[i]==0)bfs(graph,i);
  }
}

// Create a node
struct node* createNode(int v) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

// Create graph
struct Graph* createGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct node*));

  graph->visited = malloc(vertices * sizeof(int));
  queue=malloc(vertices * sizeof(int));
  max=vertices;
  int i;
  for (i = 0; i < vertices; i++) {
    graph->adjLists[i] = NULL;
    graph->visited[i] = 0;
  }
  return graph;
}

// Add edge
void addEdge(struct Graph* graph, int src, int dest) {
  // Add edge from src to dest
  struct node* newNode = createNode(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;
}

// Print the graph
void printGraph(struct Graph* graph) {
  int v;
  for (v = 0; v < graph->numVertices; v++) {
    struct node* temp = graph->adjLists[v];
    printf("\n%d--- ", v);
    while (temp) {
      printf("%d -> ", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
}

void resetVisited(struct Graph* graph,int num){
	int i=0;
	for(i=0;i<num;i++)graph->visited[i] = 0;
}

int main() {
  struct Graph* graph = createGraph(9);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 0, 3);
  addEdge(graph, 1, 5);
  addEdge(graph, 1, 6);
  addEdge(graph, 6, 8);
  addEdge(graph, 3, 7);
  addEdge(graph, 4, 7);

 printGraph(graph);
 printf("DFS:\n");
 DFS(graph,0);
 resetVisited(graph,graph->numVertices);
  printf("BFS:\n");
 bfs(graph,0);

  return 0;
}
