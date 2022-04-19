#include <stdio.h>

#define max 10


int adj[max][max];
int queue[max];
int visited[max];
int front=0,rear=0;
int first=-1;
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



void bfs(){
	if(visited[first]==0)printf("%d\n",first);
	visited[first]=1;
	enqueue(first);
	
	while(rear>0){
		int node=queue[front];
		int i=0;
		for(i=0;i<max;i++){
			if(adj[node][i]==1 && visited[i]!=1){
				printf("%d\n",i);
				visited[i]=1;
				enqueue(i);
			}
		}
		dequeue();
	}
	int i=0,j=0;
	for(i=0;i<max;i++){
		for(j=0;j<max;j++){
		   if(adj[i][j]==1 && visited[i]==0){
		   	first=i;
		   	bfs();
		   }
		}
	}
}


void dfs(int node){
	if(visited[node]==0)printf("%d\n",node);
	visited[node]=1;
	int i=0;
	for(i=0;i<max;i++){
			if(adj[node][i]==1 && visited[i]!=1){
				dfs(i);
			}
	}
	
	
	int j=0;i=0;
	
		for(i=0;i<max;i++){
		for(j=0;j<max;j++){
		   if(adj[i][j]==1 && visited[i]==0){
		   	first=i;
		   	dfs(first);
		   }
		}
	}
	
}


void addEdge(int start,int end){
	if(start>=0 && start<max && end>=0 && end<max){
		adj[start][end]=1;
		if(first==-1)first=start;
	}
}

void display(){
	int i,j;
	for(i=0;i<max;i++){
		for(j=0;j<max;j++){
			printf("%d",adj[i][j]);
		}
		printf("\n");
	}
}

void createGraph(){
	
	int i,j;
	for(i=0;i<max;i++){
		queue[i]=-1;
		visited[i]=0;
		for(j=0;j<max;j++){
			adj[i][j]=0;
		}
	}
}

int main(){
	createGraph();
	
	int origin=0,end=0;
//	while(1){
//		printf("Add an edge to a graph giving value of origin and end(to exit put -1 -1 as origin and end)->\n");
//		if(origin==-1 && end==-1)break;
//		printf("Origin : ");
//		scanf("%d",&origin);
//		printf("\nEnd : ");
//		scanf("%d",&end);
//		addEdge(origin,end);
//	}


  addEdge(0, 1);
  addEdge(0, 2);
  addEdge(0, 3);
  addEdge(1, 5);
  addEdge(1, 6);
  addEdge(3, 7);
  addEdge(4, 7);

//	printf("BFS TRAVERSAL : \n");
//	bfs();
    printf("DFS TRAVERSAL : \n");
	dfs(first);

}
