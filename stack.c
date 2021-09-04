#include<stdio.h>
#define MAX 10000
int top=-1;
int a[MAX];
int push(int num){
	if(top==MAX)printf("cannot push");
	else{
		a[++top]=num;
	}
}
int pop(){
	if(top==-1)return -1;
	else{
	
		return a[top--];
	}
}
void display(){
		
	  	int i=0;
	  	if(top!=-1){
	  		printf("\nelements :\n");
	  		for(i=top;i>=0;i--)printf("%d\n",a[i]);
		  }
	  	
	  	else
	  	printf("\nempty stack\n");
}
int main(){
	int choice=0;
	while(1){
	 int num=0;
	  printf("\nenter your choice : \n");
	  printf("1. push \n");
	  printf("2. pop \n");
	  printf("3. display \n");
	  printf("4. exit \n");
	  scanf("%d",&choice);
	  switch(choice){
	  	case 1:
	  		printf("\nEnter the element : ");
            scanf("%d",&num);
            push(num);
            break;
	  	case 2:
	  	    num=pop();
	  	    if(num!=-1)
	  		printf("\npopped element : %d\n",num);
	  		else
	  		printf("\ncannot pop\n");
            break;
	  	case 3:
	  	    display();
	  		break;
	  	case 4:
	  		exit(0);
			  	  
	}
  }
}
