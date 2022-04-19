#include <stdio.h>
#define max 100



struct Tree{

int data;

struct Tree* left;

struct Tree* right;

};

struct Tree* root=NULL;

struct Tree* stack[max];
int top=-1;

void push(struct Tree* root){
	if(top>=max)printf("Overflow");
	else
	stack[++top]=root;
}

void pop(){
	if(top==-1)printf("Underflow");
	else
	top--;
}

int empty(){
	if(top==-1)return 1;
	else return 0;
}

void insert(int data) {

struct Tree* temp = root;

struct Tree* prev=NULL;

struct Tree* newnode=(struct Tree*)malloc(sizeof(struct Tree*));

newnode->data=data;

newnode->left=NULL;

newnode->right=NULL;

if (root == NULL){

root=newnode;

return;

}

while (temp != NULL) {

prev=temp;

if (data > temp->data)

temp = temp->right;

else

temp = temp->left;

}

if(data>prev->data)prev->right=newnode;

else

prev->left=newnode;

}

void inorder(struct Tree* root) {

if (root != NULL) {

inorder(root->left);

printf("%d ",root->data);

inorder(root->right);

}

}

void preorder(struct Tree* root) {

if (root != NULL) {

printf("%d ",root->data);

inorder(root->left);

inorder(root->right);

}

}

void postorder(struct Tree* root) {

if (root != NULL) {

inorder(root->left);

inorder(root->right);

printf("%d ",root->data);

}

}


void inorderiterative(struct Tree* root){
	 
	 struct Tree* curr=root;
	 while(curr!=NULL || empty()!=1){
	 	
	 	while(curr!=NULL){
	 		push(curr);
	 		curr=curr->left;
		 }
		 curr=stack[top];
		 pop();
		 printf("%d\n",curr->data);
		 curr=curr->right;
	 	
	 }
	 
}

void preorderiterative(struct Tree* root){
	 struct Tree* curr=root;
	 while(curr!=NULL || empty()!=1){
	 	
	 	while(curr!=NULL){
	 		push(curr);
	 		printf("%d\n",curr->data);
	 		curr=curr->left;
		 }
		 curr=stack[top];
		 pop();
		 
		 curr=curr->right;
	 	
	 }
}
void postorderiterative(struct Tree* root){
 struct Tree* curr=root;
	do{
		while(curr!=NULL){
			if(curr->right!=NULL)push(curr->right);
			push(curr);
			curr=curr->left;
		}
		curr=stack[top];
		pop();
		if(curr->right!=NULL && stack[top]==curr->right){
			pop();
			push(curr);
			curr=curr->right;
		}
		else{
			printf("%d\n",curr->data);
			curr=NULL;
		}
		
	}
	while(empty()!=1);
}



struct Tree* change(struct Tree* root){

if(root->left==NULL)return root->right;

else if(root->right==NULL)return root->left;

struct Tree* node=root->right;

while(node->left!=NULL)node=node->left;

node->left=root->left;

return root->right;

}



void delete(int data){

struct Tree* par=root;
struct Tree* copy=root;
struct Tree* node;

while(copy!=NULL){

if(copy->data>data){

par=copy;

copy=copy->left;

continue;

}

if(copy->data==data){

node=copy;

break;

}

if(copy->data<data){

par=copy;

copy=copy->right;

continue;

}

}
if(copy==NULL)printf("Error node not present");
else
{
	if(par->left==copy){

par->left=change(copy);

}

else if(par->right==copy){

par->right=change(copy);

}
else if(par==root){
	root=change(copy);
}
}


}



int main(){

//printf("enter root element : ");
//
//int n;
//
//scanf("%d",&n);
//
//insert(n);
//
//while(1){
//
//int n;
//
//printf("do you want to enter another element 0 to exit 1 to continue: ");
//
//int choice=0;
//
//scanf("%d",&choice);
//
//if(choice){
//
//printf("enter element : ");
//
//scanf("%d",&n);
//
//insert(n);
//
//}
//
//else
//
//break;
//
//}

insert(5);
insert(6);
insert(10);
insert(3);
insert(4);
insert(2);
printf("inorder : \n");

inorderiterative(root);
printf("preorder : \n");

preorderiterative(root);
printf("postorder : \n");

postorderiterative(root);

delete(1);

printf("\ninorder after deletion : \n");

inorder(root);

return 0;

}
