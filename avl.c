
#include<stdio.h>
#include<stdlib.h>

typedef struct Tree
{
    int key;
    struct Tree *right,*left;
    int height;
}NODE;


int getHeight(NODE *n)
{
    if(n==NULL)
    {
        return 0;
    }
    return n->height;

}
NODE *createNode(int key)

{
    NODE *x=(NODE *)malloc(sizeof(NODE));
    x->key=key;
    x->left=x->right=NULL;
    x->height=1;

    return x;
}

int getBalanceFactor(NODE *n)
{
    if(n==NULL)
     return 0;
    return getHeight(n->left) - getHeight(n->right);
}

int max(int a,int b)
{
    return (a>b)?a:b;
}


//LL
NODE *rightRotation(NODE *y)
{
    NODE *x=y->left;
    NODE *t2=x->right;

    x->right=y;
    y->left=t2;

    y->height= 1 + max(getHeight(y->right),getHeight(y->left));
    x->height= 1 + max(getHeight(x->right),getHeight(x->left));

    return x;   
}

//RR
NODE *leftRotation(NODE *x)
{

    NODE *y=x->right;
    NODE *t2=y->left;

    y->left=x;
    x->right=t2;

    y->height= 1 + max(getHeight(y->right),getHeight(y->left));
    x->height= 1 + max(getHeight(x->right),getHeight(x->left));

    return y;   
}

NODE *insert(NODE *node,int key)
{
    
    if(node==NULL)
        return createNode(key);
    if(key > node->key)
        node->right = insert(node->right,key);

    else if(key < node->key)
        node->left=insert(node->left,key);
    else
        return node;

    node->height = 1 +  max(getHeight(node->left),getHeight(node->right));
    int bf=getBalanceFactor(node);

    //LL case
    if(bf > 1 && key < node->left->key)
    {
        return rightRotation(node);
    }
    //RR case
    if(bf<-1 && key > node->right->key)
    {
        return leftRotation(node);
    }
    //RL case
    if(bf<-1 && key < node->right->key)

    {
        node->right=rightRotation(node->right);
        return leftRotation(node);
    }
    //LR case
    if(bf>1 && key > node->left->key)
    {
        node->left=leftRotation(node->left);
        return rightRotation(node);
    }

    return node;
}

void inorder(NODE *r)
{
    if(r)
    {
        inorder(r->left);
        printf("%d\t",r->key);
        inorder(r->right);

    }
}
void preorder(NODE *r)
{
    if(r)
    {
        printf("%d\t",r->key);
        preorder(r->left);
        preorder(r->right);
    }
}

void postorder(NODE *r)
{
    if(r)
    {
        postorder(r->left);
        postorder(r->right);
        printf("%d\t",r->key);
    }
}


int main()
{
    NODE *root=NULL; 
    int k1;
    int ch;
    while(1)
    {
        printf("\n1.create AVL tree 2.inorder traversal 3.preorder traversal 4.postorder traversal 5.exit\n");
        scanf("%d",&ch);
        switch (ch)
        {
            
        case 1:
            printf("\n");
            printf("enter the key value:");
            scanf("%d",&k1);
            root=insert(root,k1);
            break;

        case 2:
            printf("\n");
            inorder(root);
            break;
        
        case 3:
            printf("\n");
            preorder(root);
            break;
        case 4:
            printf("\n");
            postorder(root);
            break;

        case 5:
            exit(1);
            break;   
        default:
            break;
        }
        

    }
    
    return 0;
}

