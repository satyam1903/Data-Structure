#include<stdio.h>
#include<stdlib.h>

#include<conio.h>
// main file
struct node
{
    int data;
    struct node *next;
};
struct node *last=NULL;
struct node* createnode()
{
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    return n;
}
void traversal()
{
    struct node *t;
    
    t=last->next;
    do
    {
        printf("%d",t->data);
        t=t->next;
    } while(t!=last);
    printf("%d",t->data);
    
}
void insertnodeatbeg()
{
    struct node *t;
    int m;
    t=createnode();
    t->next=last->next;
    printf("enter a no to store");
    scanf("%d",&m);
    t->data=m;
    last->next=t;

}

void insertnode()
{
    int n;
    struct node *t,*temp,*q;
    t=createnode();
    printf("enetr a no");
    scanf("%d",&n);
    t->data=n;
    if(last==NULL)
    {
    last=t;
    t->next=t;
    }
     if(last->next==last)
    {
        t->next=last;
        last->next=t;
    }
    else{
        q=last;
        t->next=last;
        while(q->next!=last)
        {
        q=q->next;
        }
        q->next=t;

    }
}

void insertafter()
{
    struct node *t,*temp;
    int n,item;
    printf("enter a no to find node");
    scanf("%d",&item);
    printf("enter a no to store");
    scanf("%d",&n);
    temp=createnode();
    temp->data=n;
    t=last->next;
    do
    {
        if(t->data==item)
        {
            temp->next=t->next;
            t->next=temp;
            if(t==last)
            {
                last=temp;
            }

        }
    }while(t!=last);
    
    
}
void insertatend()
{
    struct node *t;
    int n;
     t=(struct node*)malloc(sizeof(struct node *));
    printf("enter a no");
    scanf("%d",&n);
    t->data=n;
    t->next=last->next;
    last->next=t;
    last=t;
}
void deletefirstnode()
{
    struct node *t;
    t=last->next;
    last->next=t->next;
    free(t);
}
void deletelastnode()
{
    struct node *m,*n;
    m=last->next;
    while(m->next!=last)
    {
        m=m->next;
    }
    n=m->next;
    m->next=last->next; 
    last=m;
    free(n);
}
void deletenodewithtem()
{
    struct node *t,*q,*temp;
    int item;
    temp=last;

    t=last->next;
    printf("enter a no");
    scanf("%d",&item);
    if(item==temp->data)
    {
        deletelastnode();
    }
    else if(item==temp->next->data)
    {
        deletefirstnode();
    }
    else{
    while(item!=t->next->data && t->next!=last)
    {
        t=t->next;
    }
    q=t->next;
    t->next=q->next;
    free(q);
    }





}

void main()
{
    int ch;
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
                insertnode();
                break;
            case 2:
                traversal();
                break;
            case 3:
                exit(0);      
                break;
            case 4:
                insertnodeatbeg();
                break;
            case 5:
                deletenodewithtem();
                break; 
            case 6:
                deletelastnode();     
                break;
            default:
                printf("invalid input");

        }
    }
}