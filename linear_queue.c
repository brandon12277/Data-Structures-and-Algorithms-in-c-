#include <stdio.h>
#define SIZE 6

int a[SIZE];
int front=-1,rear=-1;
void insert(int x){
	if(rear>=SIZE-1)printf("\nOVERFLOW");
	if(front==-1)front=0;
	rear++;
	a[rear]=x;
}
void delete(){
	if(front==-1 || rear<front)printf("\nUNDERFLOW");
	else{
		int deleted_num=a[front++];
		printf("\ndeleted element : %d\n",deleted_num);
	}
}
void display(){
	printf("\nelements elements : \n");
	int i=0;
	if(front !=-1 || rear!=-1)
	 for(i=front;i<=rear;i++){
	 	printf("%d\n",a[i]);
	 }
}
int main(){
	while(1){
		printf("Menu:\n");
		printf("1. Insert:\n");
		printf("2. Delete:\n");
		printf("3. Display:\n");
		printf("4. Exit:\n");
	    int choice=0;
	    scanf("%d",&choice);
	    switch(choice){
	    	case 1:
	    		printf("\nenter element :");
	    		int num;
	    		scanf("%d",&num);
	            insert(num);
	    		break;
	    	case 2:
	    		delete();
	    		break;
	    	case 3:
	    		display();
	    		break;
	    	case 4:
	    		exit(0);
	    		break;
		}
	    
	}
	return 0;
}

