#include <stdio.h>
#define SIZE 5

int front=-1,rear=-1,count=0;

int a[SIZE];
void insert(int x){
   if(front==0 && rear>=SIZE-1 || (rear+1==front)){
   	printf("OVERFLOW");
   }
   else{
   	if(front==-1){
   		front=0;
   		rear=0;
   		count++;
	   }
	else{
		if(rear>=SIZE-1)rear=0;
		else{
			rear++;
			count++;
		}
		
		
	}
		a[rear]=x;
	
   }
   
   
   
}
void delete(){
	if(front==-1 || rear<front)printf("\nUNDERFLOW");
	else{
		int deleted_num=a[front++];
		count--;
		printf("\ndeleted element : %d\n",deleted_num);
	}
}
void display(){
	printf("\n elements in queue : \n");
	int i=0;
	 for(i=front;i<=count;i=(i+1)%SIZE){
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

