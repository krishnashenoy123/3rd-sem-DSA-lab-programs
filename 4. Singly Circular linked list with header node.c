#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *rlink;
};
typedef struct node *NODE;
int i,choice,ch1=1,choice1,ch2=1,choice2,ch3=1;
NODE insert_front(NODE);
NODE insert_end(NODE);
NODE insert_pos(NODE);
NODE delete_front(NODE);
NODE delete_end(NODE);
NODE delete_pos(NODE);
void display(NODE);
void main()
{
NODE head=0;
head=(NODE)malloc(sizeof(struct node));
head->rlink=head;
while(ch1==1)
{
printf("Circular Singly Linked list implementation\n");
printf("1:Insert\n2:Delete\n3:Display\n4:Exit\n");
printf("Enter your choice : ");
scanf("%d",&choice);
switch(choice)
{
case 1: printf("Insert Implementation\n");
ch2=1;
while(ch2==1)
{
printf("1:Insert_front\n2:Insert_end\n3:Insert_at_specified_position\n");
printf("Enter your choice : ");
scanf("%d",&choice1);
switch(choice1)
{
case 1: head=insert_front(head);
break;
case 2: head=insert_end(head);
break;
case 3: head=insert_pos(head);
break;
default : printf("Wrong choice\n");
break;
}
printf("Do you want to insert again 1-Yes or 0-No\n");
scanf("%d",&ch2);
}
break;
case 2: printf("Delete Implementation\n");
ch3=1;
while(ch3==1)
{
printf("1:Delete_front\n2:Delete_end\n3:Delete_at_specified_position\n");
printf("Enter your choice : ");
scanf("%d",&choice2);
switch(choice2)
{
case 1: head=delete_front(head);
break;
case 2: head=delete_end(head);
break;
case 3: head=delete_pos(head);
break;
default :printf("Wrong choice\n");
break;
}
printf("Do you want to delete again 1-Yes or 0-No\n");
scanf("%d",&ch3);
}
break;
case 3: display(head);
break;
case 4: exit(0);
default : printf("Wrong choice\n");
break;
}
printf("Do you want to continue 1-Yes or 0-No\n");
scanf("%d",&ch1);
}
}
NODE insert_front(NODE head)
{
NODE newnode,first;
newnode=(NODE)malloc(sizeof(struct node));
newnode->rlink=0;
printf("Enter the data\n");
scanf("%d",&newnode->data);
if(head->rlink==head)
{
head->rlink=newnode;
newnode->rlink=head;
return head;
}
first=head->rlink;
head->rlink=newnode;
newnode->rlink=first;
return(head);
}
NODE insert_end(NODE head)
{
NODE newnode,next;
newnode=(NODE)malloc(sizeof(struct node));
newnode->rlink=head;
printf("Enter the data\n");
scanf("%d",&newnode->data);
if(head->rlink==head)
{
head->rlink=newnode;
newnode->rlink=head;
return(head);
}
next=head->rlink;
while(next->rlink!=head)
next=next->rlink;
next->rlink=newnode;
newnode->rlink=head;
return(head);
}
NODE delete_front(NODE head)
{
NODE temp,first;
if(head->rlink==head)
{
printf("No nodes in the list\n");
return(first);
}
temp=head->rlink;
if(temp->rlink==0)
{
printf("Deleted data = %d\n",temp->data);
head->rlink=head;
free(temp);
return(head);
}
first=temp->rlink;
printf("Delete data = %d\n",temp->data);
head->rlink=first;
free(temp);
return(head);
}
NODE delete_end(NODE head)
{
NODE temp,prev;
if(head->rlink==head)
{
printf("No nodes in the list\n");
return(head);
}
temp=head->rlink;
if(temp->rlink==head)
{
printf("Deleted data = %d\n",temp->data);
head->rlink=head;
free(temp);
return(head);
}
while(temp->rlink!=head)
{
prev=temp;
temp=temp->rlink;
}
printf("Deleted data = %d\n",temp->data);
prev->rlink=head;
free(temp);
return(head);
}
void display(NODE head)
{
NODE next;
if(head->rlink==head)
{
printf("No nodes in the list\n");
}
else
{
next=head->rlink;
printf("The contents of Singly Circular linked list are\n");
while(next!=head)
{
printf("%d \t",next->data);
next=next->rlink;
printf("\n");
}
}
}
NODE insert_pos(NODE head)/*at specified position*/
{
NODE newnode,prev,next;
int i,pos;
newnode=(NODE)malloc(sizeof(struct node));
newnode->rlink=newnode;
printf("Enter the data to be inserted at specified position\n");
scanf("%d",&newnode->data);
printf("Enter the position where node to be inserted\n");
scanf("%d",&pos);
next=head->rlink;
if(pos==1)
{
head->rlink=newnode;
newnode->rlink=next;
return(head);
}
for(i=1;i<pos;i++)
{
if(next==head)
{
printf("Invalid position\n");
return(head);
}
prev=next;
next=next->rlink;
}/*end of for loop*/
prev->rlink=newnode;
newnode->rlink=next;
return(head);
}
NODE delete_pos(NODE head)
{
NODE prev,next;
int i,pos;
if(head->rlink==head)
{
printf("No nodes in the list\n");
return(head);
}
printf("Enter the position where the node to be deleted\n");
scanf("%d",&pos);
next=head->rlink;
if(pos==1 && next->rlink==head)
{
printf("Node to be deleted = %d\n",next->data);
head->rlink=head;
free(next);
return(head);
}
if(pos==1)
{
printf("Node to be deleted = %d\n",next->data);
head->rlink=next->rlink;
free(next);
return(head);
}
for(i=0;i<pos;i++)
{
if(next==head)
{
printf("Invalid position\n");
return(head);
}
prev=next;
next=next->rlink;
}/*end of for loop*/
printf("Node to be deleted = %d\n",next->data);
prev->rlink=next->rlink;
free(next);
return(head);
}