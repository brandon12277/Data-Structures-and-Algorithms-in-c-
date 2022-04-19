#include <stdio.h>
#define INT_MAX 2000000
#define max 5


int adj[max][max];
int p[max][max];
int w[max][max];
int visited[max];
int front=0,rear=0;
int first=-1;

void addEdge(int start,int end){
	if(start>=0 && start<max && end>=0 && end<max){
		adj[start][end]=1;
		p[start][end]=1;
		if(first==-1)first=start;
	}
}

void addEdgeWithWeight(int start,int end,int weight){
	if(start>=0 && start<max && end>=0 && end<max){
		adj[start][end]=1;
		w[start][end]=weight;
		if(first==-1)first=start;
	}
}

void display(){
	int i,j;
	for(i=0;i<max;i++){
		for(j=0;j<max;j++){
			if(w[i][j]!=INT_MAX)
			printf("%d,",w[i][j]);
			else
			printf("x,");
		}
		printf("\n");
	}
}

void createGraph(){
	
	int i,j;
	for(i=0;i<max;i++){
		visited[i]=0;
		for(j=0;j<max;j++){
			adj[i][j]=0;
			p[i][j]=0;
			w[i][j]=INT_MAX;
		}
	}
}

int min(int a,int b){
	if(a>b)return b;
	else
	return a;
}
void warshal(){

	int i=0,j=0,k=0;
	for(k=0;k<max;k++){
			for(j=0;j<max;j++){
					for(i=0;i<max;i++){
						p[i][j]=p[i][j] || (p[i][k] && p[k][j]);
					}
					   
			}
	}
	
	
}

void floyd(){
		int i=0,j=0,k=0;
	for(k=0;k<max;k++){
			for(j=0;j<max;j++){
					for(i=0;i<max;i++){
						w[i][j]=min(w[i][j],(w[i][k] + w[k][j]));
					}
					   
			}
	}
}

int main(){
	createGraph();
	
	int origin=0,end=0,weight=0;
	while(1){
		if(origin==-1 && end==-1)break;
		printf("Add an edge to a graph giving value of origin and end(to exit put -1 -1 as origin and end)->\n");
	    printf("Origin : ");
		scanf("%d",&origin);
		printf("\nEnd : ");
		scanf("%d",&end);
		printf("\nEnter weight : ");
		scanf("%d",&weight);
		addEdgeWithWeight(origin,end,weight);
	}

	floyd();
	display();
	

}

