#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
struct node
{
int data;
struct node *lchild;
struct node *rchild;
};
typedef struct node *NODE;
int i=1,num,req;
void insert(NODE*,int) ;
void node_delete(NODE*);
void search(NODE*,int,NODE*,NODE*,int*);
void inorder(NODE root4);
void main()
{
NODE root=0;
printf("Enter the num of nodes\n");
scanf("%d",&req);
while(i++<=req)
{
printf("Enter the data : ");
scanf("%d",&num);
insert(&root,num);
}
printf("\nNodes before deletion\n");
inorder(root);
node_delete(&root);
printf("\nNodes after deletion\n");
inorder(root);
printf("\n");
}
void insert(NODE *(root1),int num)
{
if((*root1)==0)
{
(*root1)=(NODE)malloc(sizeof(struct node));
(*root1)->lchild=(*root1)->rchild=0;
(*root1)->data=num;
}
else
{
if(num<((*root1)->data))
insert(&((*root1)->lchild),num);
else
insert(&((*root1)->rchild),num);
}
return;
}
void inorder(NODE root4)
{
if(root4!=0)
{
inorder(root4->lchild);
printf("%d->",root4->data);
inorder(root4->rchild);
}
}
void search(NODE *root3,int num2,NODE *par,NODE *x,int *found)
{
NODE q;
q=*root3;
*found=FALSE;
*par=0;
while(q!=0)
{
if(num2==q->data)
{
*found=TRUE;
*x=q; return;
}
*par=q;
if(num2<q->data)
q=q->lchild;
else
q=q->rchild;
}
}
void node_delete(NODE *root2)
{
int num,found;
NODE parent,x,xsucc;
parent=0;x=0;
if(*root2==0)
{
printf("Tree is empty\n");
return;
}
printf("\n");
printf("\nEnter data to be deleted\n");
scanf("%d",&num);
search(&(*root2),num,&parent,&x,&found);
if(found==FALSE)
{
printf("Data to be deleted %d is not found\n",num);
return;
}
printf("Data to be deleted %d is found\n",num);
if(x->lchild!=0&&x->rchild!=0)
{
parent=x;
xsucc=x->rchild;
while(xsucc->lchild!=0)
{
parent=xsucc;
xsucc=x->lchild;
}
x->data=xsucc->data;
x=xsucc;
}
if(x->lchild!=0&&x->rchild!=0)
{
if(parent->lchild==x)
parent->lchild=x->lchild;
else
parent->rchild=x->lchild;
free(x);
return;
}
if(x->rchild!=0&&x->lchild==0)
{
if(parent->lchild==x)
parent->lchild=x->rchild;
else
parent->rchild=x->rchild;
free(x);
return;
}
if(x->lchild==0&&x->rchild==0)
{
if(parent->rchild==x)
parent->lchild=0;
else
parent->lchild=0;
free(x);
return;
}
}