#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *lchild;
struct node *rchild;
};
typedef struct node *NODE;
NODE root=0;
void create(NODE *);
void inorder(NODE);
void preorder(NODE);
void postorder(NODE);
int is_lchild(NODE *);
int is_rchild(NODE *);
void main()
{
printf("Creation of tree\n");
root=(NODE)malloc(sizeof(struct node));
printf("Enter the data for root node : ");
scanf("%d",&root->data);
create(&root);
printf("Tree Traversal\n");
printf("\nPreorder Traversal :\n");
preorder(root);
printf("\nInorder Traversal :\n");
inorder(root);
printf("\nPostorder Traversal :\n");
postorder(root);
}
void create(NODE *root1)
{
NODE temp,temp1;
if(is_lchild(&(*root1)))
{
(*root1)->lchild=(NODE)malloc(sizeof(struct node));
temp=(*root1)->lchild;
printf("Enter data for left child : ");
scanf("%d",&temp->data);
create(&temp);
}
else
(*root1)->lchild=0;
if(is_rchild(&(*root1)))
{
(*root1)->rchild=(NODE)malloc(sizeof(struct node));
temp1=(*root1)->rchild;
printf("Enter data for right child : ");
scanf("%d",&temp1->data);
create(&temp1);
}
else
(*root1)->rchild=0;
return;
}
int is_lchild(NODE *root2)
{
int ch;
printf("Do you want to create lchild of %d 1=Yes/0=No : ",(*root2)->data);
scanf("%d",&ch);
if(ch==1)
return(1);
else
return(0);
}
int is_rchild(NODE *root2)
{
int ch1;
printf("Do you want to create rchild of %d 1=Yes/0=No : ",(*root2)->data);
scanf("%d",&ch1);
if(ch1==1)
return(1);
else
return(0);
}
void preorder(NODE root4)
{
if(root4!=0)
{
printf("%d->",root4->data);
preorder(root4->lchild);
preorder(root4->rchild);
}
}
void inorder(NODE root5)
{
if(root5!=0)
{
inorder(root5->lchild);
printf("%d->",root5->data);
inorder(root5->rchild);
}
}
void postorder(NODE root6)
{
if(root6!=0)
{
postorder(root6->lchild);
postorder(root6->rchild);
printf("%d->",root6->data);
}
}