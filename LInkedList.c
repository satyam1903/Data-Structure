#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node* createnode()
{
    struct node *t;

    t=(struct node*)malloc(sizeof(struct node));
    return t;

}
void insertnode()
{
    int d;
    struct node *n,*t;

    n=createnode();
    printf("enter data");
    scanf("%d",&d);
    n->data=d;
    n->next=NULL;
    if(head==NULL)
    {
        head=n;
        
    }
    else{
        t=head;
        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->next=n;
    }

}
void insertatend()
{

    struct node *t,*n;
    int m;
    n=createnode();
    t=head;
    printf("enter a no to store ");
    scanf("%d",&m);
    while(t->next!=NULL)
    {
        t=t->next;
    }
    n->next=NULL;
    n->data=m;
    t->next=n; 
}
void insertatFirst()
{
    struct node *ptr;
    int m;

    ptr=(struct node*)malloc(sizeof(struct node));
    printf("enetr data to put");
    scanf("%d",&m);
    ptr->data=m;
    ptr->next=head;
    head=ptr;

}
void insertatK()
{
    int m,n;
    struct node *ptr,*t;
    t=head;
    printf("enetr position");
    scanf("%d",&n);
    ptr=createnode();
    for(m=0;m<n-1;m++);
    {
        t=t->next;
    }

    printf("enetr data to put");
    scanf("%d",&n);
    ptr->data=n;
    ptr->next=t->next;
    t->next=ptr;
}
void traverse()
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
}
void deleteFirst()
{
    struct node *p;
    p=head;
    head=head->next;
    free(p);
}
void deletelast()
{
    struct node *t,*q;
    t=head;
    q=head->next;
    while(q->next!=NULL)
    {
        t=t->next;
        q=q->next;
    }
        t->next=NULL;
        free(q);

}

void deleteatK()
{
    struct node *t,*q;
    int n;
    t=head;
    q=head->next;
    printf("enetr a no");
    scanf("%d",&n);
    for(int i=0;i<n-2;i++)
    {
        t=t->next;
        q=q->next;
    }
    t->next=q->next;
    free(q);
}
void deleteBYValue()
{
    struct node *t,*q;
    int value;
    printf("enetr a value to delete the node");
    scanf("%d",&value);
    q=head->next;
    t=head;
    while(q->data!=value && q->next!=NULL)
    {
        t=t->next;
        q=q->next;
    }
    if(q->data==value)
    {
        t->next=q->next;
    }
    free(q);
}
int main()
{ 
    int ch;
    while (1)
    {
        printf("Enter 1 for Insertion");
        printf("Enetr 2 to delete at first");
        printf("Enter 3 to enter a end");
        printf("Enter 4 to enter a end");
        printf("Enter 5 for display");
        printf("press 6 for exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                insertnode();
                break;
            case 2:
                deleteBYValue();
                break;
            case 3:
                insertatend();      
                break;
            case 4:
                insertatK();
                break;
            case 5:
                traverse();
                break; 
            case 6:
                exit(0);       
                break;
            default:
                printf("invalid input");

        }

        /* code */
    }
    
    return 0;
}