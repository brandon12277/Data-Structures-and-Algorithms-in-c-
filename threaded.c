#include <stdio.h>

#include <stdlib.h>

struct bTree{

int data;

struct bTree* left;

struct bTree* right;

int lptr;

int rptr;

};

struct bTree* root=NULL;

void insert(int data){

struct bTree* newnode=(struct bTree*)malloc(sizeof(struct bTree));

newnode->left=NULL;

newnode->right=NULL;

newnode->lptr=1;

newnode->rptr=1;

struct bTree* p2;

struct bTree* p1=root;

newnode->data=data;

int n;

if(root==NULL){

root=newnode;

return;

}

while(p1){

p2=p1;

printf("\ndo u want to insert it in the left or right of the node %d :",p1->data);

scanf("%d",&n);

if(n)

{

if(p1->lptr==1)

p1=p1->left;

else

p1=NULL;

}

else{

if(p1->rptr==1)

p1=p1->right;

else

p1=NULL;

}

}

if(n)

{

if(p2->lptr==0){

newnode->left=p2->left;

newnode->lptr=0;

}

newnode->right=p2;

newnode->rptr=0;

p2->left=newnode;
p2->lptr=1;

}

else{

if(p2->rptr==0){

newnode->right=p2->right;

newnode->rptr=0;

}

p2->right=newnode;

newnode->left=p2;

newnode->lptr=0;
p2->rptr=1;

}

}
struct bTree* inorder_pre(struct bTree* node){
   if(node!=NULL){
   	if(node->lptr==0)return node->left;
   	else{
   		if(node->left!=NULL)node=node->left;
   		else
   		return node;
   		while(node->rptr==1 && node->right!=NULL)node=node->right;
   		return node;
	   }
    }
}
struct bTree* inorder_succ(struct bTree* node){
   if(node!=NULL){
   	if(node->rptr==0)return node->right;
   	else{
   		if(node->right!=NULL)node=node->right;
   		else
   		return node;
   		while(node->lptr==1 && node->left!=NULL)node=node->left;
   		return node;
	   }
    }
}
void inorder(struct bTree* root){

while(root->left!=NULL){

root=root->left;

}

while(root!=NULL){
struct bTree* node=inorder_succ(root);
if(node->data==root->data)
printf("node-%d-Successor-No succ",root->data);
else
printf("node-%d-Successor-%d",root->data,node->data);

if(!root->rptr || root->right!=NULL)root=root->right;

else if(root->right==NULL)break;

else

{

while(root->left!=NULL){

root=root->left;

}

}

}

}

int main(){

printf("enter root element : ");

int n;

scanf("%d",&n);

insert(n);

while(1){

int n;

printf("do you want to enter another element 0 to exit 1 to continue: ");

int choice=0;

scanf("%d",&choice);

if(choice){

printf("enter element : ");

scanf("%d",&n);

insert(n);

}

else

break;

}

inorder(root);

}

//inorder – 7 8 6 5 9
