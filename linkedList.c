#include <stdio.h>
#include <stdlib.h>
struct List{
	int val;
	struct List* next;
};


 struct List* head;
 void createList(int value){
 		if(!head){
 		struct List* node=(struct List*)malloc(sizeof(struct List));
	    node->val=value;
	    node->next=NULL;
 		head=node;
	 }
	 else{
	 	printf("list already created");
	 }
 
 
 }
  void append(int val){
  	if(!head){
  			printf("\n-----------------------------------------\n");
		printf("Create List First");
		printf("\n-----------------------------------------");
  		return;
	  }
	struct List* node=(struct List*)malloc(sizeof(struct List));
	node->val=val;
	node->next=NULL;
	struct List* temp=head;
	while(temp->next!=NULL)temp=temp->next;
	temp->next=node;

}


void insertatBeginning(int value){
	struct List* node=(struct List*)malloc(sizeof(struct List));
	node->val=value;
	struct List* temp=head;
	head=node;
	head->next=temp;
}

void insertatSpecificPoint(int point,int value){
	//check if position is the start point
	if(point==1){
	insertatBeginning(value);
	return;
	} 
	//for any other position
	struct List* temp=head;
	point-=2;
	while(point-->0 && temp)temp=temp->next;
	if(!temp){
			printf("\n-----------------------------------------\n");
		printf("Either the point exceeded the list or you have not created one");
		printf("\n-----------------------------------------");
		return;
	}
	struct List* node=(struct List*)malloc(sizeof(struct List));
	node->val=value;
	struct List* nextpoint=temp->next;
	if(temp->next!=NULL){
		nextpoint=temp->next;
	}
	else
	nextpoint=NULL;
	
	temp->next=node;
	node->next=nextpoint;
	
}

void delete(){
	head=head->next;
}
void display(struct List* head){
	printf("\n-----------------------------------------\n");
	while(head!=NULL){
		if(head->next!=NULL)
		printf("%d->",head->val);
		else
		printf("%d",head->val);
		head=head->next;
	}
	printf("\n-----------------------------------------");
}




int main(){
	while(1){
		printf("\nenter your choice : ");
		printf("\n1.create a list");
		printf("\n2.append a value to the list");
		printf("\n3.insert an element at the beginning");
		printf("\n4.insert at a particular point");
		printf("\n5.delete the first node");
		printf("\n6.display\n");
		int choice=0;int value=0;int point=0;
		scanf("%d",&choice);
		switch(choice){
			case 1:
				    
  	                printf("enter the first node to create the list : ");
  	                scanf("%d",&value);
  	                 createList(value);
  	                 break;
  	        case 2:
  	        	 	
  	                printf("enter an element : ");
  	                scanf("%d",&value);
  	                 append(value);
  	                 break;
  	         case 3:
  	        	 	
  	                printf("enter an element to insert at the start: ");
  	                scanf("%d",&value);
  	                 insertatBeginning(value);
  	                 break;
  	        case 4:
  	        	 	
  	                printf("enter an element to insert at the specific location: ");
  	                scanf("%d",&value);
  	                printf("enter the specific location: ");
  	                scanf("%d",&point);
  	                
  	                 insertatSpecificPoint(point,value);
  	                 break;
  	        case 5:
  	        	 delete(head);
  	        	 break;
  	        case 6:
  	        	display(head);
  	        	break;
  	        	
		}
	}
}
  
