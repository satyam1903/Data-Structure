#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node* createnode()
{
    struct node *t;
    t=(struct node*)malloc(sizeof(struct node));
    return t;
}
void insertnode(struct node **head,int value)
{
    struct node *t,*temp,*n;
    n=*head;
    t=createnode();
    t->data=value;
    if(*head==NULL)
    {
        t->next=NULL;
        t->prev=NULL;
        *head=t;
    }
    else{
        temp=*head;
        t->next=NULL;
        while(temp->next!=NULL)
        {
         temp=temp->next;
        }
        temp->next=t;
        t->prev=temp;
    }  
      while(n!=NULL)
    {
        printf("%d",n->data);
        n=n->next;
    }
}
void traversal(struct node **head)
{
    struct node *t;
    t=*head;
    while(t!=NULL)
    {
        printf("%d",t->data);
        t=t->next;
    }
}
void deletenode(struct node **head,int value)
{
    struct node *t,*temp;
    t=*head;
    while(t->data!=value)
    {
        t=t->next;
    }
        if(t->next==NULL)
    {
        t->prev->next=NULL;
    }
    else{
        t->prev->next=t->next;
        t->next->prev=t->prev;
    }
    temp=t;
    free(temp);


}

void main()
{
    int ch,value;
    struct node *head;
    while(1)
    {
        printf("Enter 1 for Insertion");
        printf("Enetr 2 to delete at first");
        printf("Enter 3 to enter at beggining");
        printf("Enter 4 to enter a end");
        printf("Enter 5 for display");
        printf("press 6 for exit");
        scanf("%d",&ch);
        switch(ch)   
        {
            case 1:
                printf("enter a no ");
                scanf("%d",&value);
                insertnode(&head,value);
                break;
            case 2:
                traversal(&head);
                break;
            case 3:
                exit(0);      
                break;
            case 4:
            printf("eneter a value to delete");
            scanf("%d",&value);
                deletenode(&head,value);
                break;
            // case 5:
            //     deletenodewithtem();
            //     break; 
            // case 6:
            //     deletelastnode();     
            //     break;
            default:
                printf("invalid input");

        }
    }
}