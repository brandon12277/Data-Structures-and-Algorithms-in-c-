
#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
    int key;
    struct tree *left,*right;
    int height;
}NODE;
NODE *node=NULL;
NODE *insert(NODE *,int);
void inorder(NODE *);
void preorder(NODE *);
void inorder(NODE *);
void postorder(NODE *);
int height(NODE *);
NODE *postorder_a(NODE *);
NODE *rightRotate(NODE *);
NODE *leftRotate(NODE *);
int balanceFactor(NODE *);
NODE *insert(NODE *node,int k)
{

    if (node == NULL)
    {
        node=(NODE*)malloc(sizeof(NODE));
        node->key=k;
        node->left=NULL;
        node->right=NULL;
    }
    if (k < node->key)
        node->left  = insert(node->left, k);
    else if (k > node->key)
        node->right = insert(node->right, k);
    else
        return node;
    
    node->height=height(node);
    NODE *y = postorder_a(node);
    int b = balanceFactor(y);
    if(b>1 && k < y->left->key)
    {
    	printf("yes1 %d height : %d",y->right->key,b);
        return rightRotate(y);
    }
    if(b<-1 && k > y->right->key)

    {
    	printf("yes2 %d height : %d",y->right->key,b);
        return leftRotate(y);
    }
    if(b>1 && k > y->left->key)
    {
    	printf("yes3 %d height : %d",y->left->key,b);
        y->left = leftRotate(y->left);
        return rightRotate(y);
    }
    if(b<-1 && k < y->right->key)
    {
    	printf("yes4 %d height : %d",y->right->key,b);
        y->right = rightRotate(y->right);
        return leftRotate(y);
    }
    return node;
}
NODE *postorder_a(NODE *node)
{
    if(node)
    {
        postorder_a(node->left);
        postorder_a(node->right);

        if(balanceFactor(node)==2||balanceFactor(node)==-2)
        {
            return node;
        }
    }
    return node;
}
int max(int a,int b){
	if(a>b)return a;
	else return b;
}
int height(NODE *node)
{
	if(node==NULL)return 0;
    int lh,rh;
    if(node==NULL)
        return 0;
    if(node->left==NULL)
        lh=0;
    else
        lh=1+node->left->height;
    if(node->right==NULL)
        rh=0;
    else
        rh=1+node->right->height;

    if(lh>rh)
        return(lh);
    return(rh);
}
int balanceFactor(NODE *node)
{     
    int lh,rh;
    if(node==NULL)
        return 0;
    
    if(node->left==NULL)
        lh=0;
    else if(node->left->height>0)
        lh=1+node->left->height;
    else
      lh=1;
    
    if(node->right==NULL)
        rh=0;
    else if(node->right->height>0)
        rh=1+node->right->height;
    else
      rh=1;
    return(lh-rh+1);
}

NODE *rightRotate(NODE *y)
{
	printf("yes");
    NODE *x = y->left;
    NODE *T2 = x->right;
 
    x->right = y;
    y->left = T2;
 
    x->height = height(x);
    y->height = height(y);
 
    return x;
}
NODE *leftRotate(NODE *x)
{
    NODE *y = x->right;
    NODE *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = height(x);
    y->height = height(y);

    return y;
}
void inorder(NODE *node)
{
    if(node)
    {
        inorder(node->left);
        printf("%d\t",node->key);
        inorder(node->right);
    }
}
void preorder(NODE *node)
{   
    if(node)
    {
        printf("%d\t",node->key);
        preorder(node->left);
        preorder(node->right);
    }
}
void postorder(NODE *node)

{
    if(node)
    {
        postorder(node->left);
        postorder(node->right);
        printf("%d\t",node->key);
    }
}
int main()
{
    int k,ch=1;
    while(1)
    {
        printf("\n\tMENU");
        printf("\n1.Insert a key");
        printf("\n2.Inorder traversal");
        printf("\n3.Preorder traversal");
        printf("\n4.Postorder traversal");
        printf("\n5.Exit");
        printf("\nEnter your choice [1-5]:");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:printf("\nEnter the key:");
                   scanf("%d",&k);
                   node=insert(node,k);
                   break;
            case 2:inorder(node);
                   break;
            case 3:preorder(node);
                   break;
            case 4:postorder(node);
                   break;
            case 5:exit(0);
                   break;
            default:printf("\nWrong Choice!!");
                    break;
        }
    }
    return 0;
}

