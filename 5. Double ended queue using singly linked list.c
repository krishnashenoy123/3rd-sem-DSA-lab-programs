#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};


typedef struct node *NODE;
NODE insert_front(NODE);
NODE insert_rear(NODE);
NODE delete_front(NODE);
NODE delete_rear(NODE);
void display(NODE);


int main()
{
    int ch=1,choice,choice1,p=1,q=1;
    NODE first=0; 
    while(ch==1)
    {
        printf("Double ended queue operation\n");
        printf("1.Input restricted Dequeue\n2.Output restrited Dequeue\n3:Display\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: p=1;
            while(p==1)
            {
                printf("Input restricted dequeue\n");
                printf("1:Insert from rear\n2:Delete from rear\n3:Delete from front\n");
                printf("Enter your choice : ");
                scanf("%d",&choice1);
                switch(choice1)
                {
                    case 1: first=insert_rear(first);
                    break;
                    case 2: first=delete_rear(first);
                    break;
                    case 3: first=delete_front(first);
                    break;
                    default: printf("Invaild choice\n");
                    break;
                }
                printf("Press 1 to continue\n");
                scanf("%d",&p);
            }
            break;
            case 2: q=1;
            while(q==1)
            {
                printf("Output restricted Dequeue\n");
                printf("1:Insert from rear\n2:Insert from front\n3:Delete from front\n");
                printf("Enter your choice : ");
                scanf("%d",&choice1);
                switch(choice1)
                {
                    case 1: first=insert_rear(first);
                    break;
                    case 2: first=insert_front(first);
                    break;
                    case 3: first=delete_front(first);
                    break;
                    default: printf("Invalid choice\n");
                    break;
                }
                printf("Press 1 to continue\n");
                scanf("%d",&q);
            }
            break;
            case 3:display(first);
            break;
            default :printf("Invalid choice\n");
            break;
        }
        printf("\nDo you want to continue 1-yes or 0-No\n");
        scanf("%d",&ch);
    }
    return 0;
}


NODE insert_front(NODE first)
{
    NODE newnode;
    newnode=(NODE)malloc(sizeof(struct node));
    newnode->link=0;
    printf("Enter the data to be stored\n");
    scanf("%d",&newnode->data);
    if(first==0)
    {
        first=newnode;return(first);
    }
    else
    {
        newnode->link=first;
        first=newnode;return(first);
    }
}


NODE delete_front(NODE first)
{
    NODE temp;
    if(first==0)
    {
        printf("No nodes present in list\n");
        return(first);
    }
    else
    {
        printf("Node to be deleted = %d\n",first->data);
        temp=first;
        if(first->link==0)
        {
            free(first);
            first=0;return(first);
        }
        else
        {
            first=first->link;free(temp);
            return(first);
        }
    }
}


NODE insert_rear(NODE first)
{
    NODE newnode,temp;
    newnode=(NODE)malloc(sizeof(struct node));
    newnode->link=0;
    printf("Enter the data to be stored\n");
    scanf("%d",&newnode->data);
    if(first==0)
    {
        first=newnode;return(first);
    }
    else
    {
        temp=first;
        while(temp->link!=0)
        temp=temp->link;
        temp->link=newnode;
        return(first);
    }
}


NODE delete_rear(NODE first)
{
    NODE temp,temp1;
    if(first==0)
    {
        printf("No nodes present in list\n");
        return(first);
    }
    else
    {
        temp=first;
        if(temp->link==0)
        {
            printf("Node to be deleted = %d\n",temp->data);
            free(temp);first=0;return(first);
        }
        while(temp->link!=0)
        {
            temp1=temp;
            temp=temp->link;
        }
        printf("Node to deleted = %d\n",temp->data);
        free(temp);
        temp1->link=0;
        return(first);
    }
}


void display(NODE first)
{
    NODE temp;
    if(first==0)
    printf("No nodes are present in list\n");
    else
    {
        printf("The contents of the list are\n");
        for(temp=first;temp!=0;temp=temp->link)
        printf("%d\t",temp->data);
    }
    printf("\n");
}
