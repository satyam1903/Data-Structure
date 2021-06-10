#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct stack
{
    int data;
    struct stack *next;
};
struct stack* createnode()
{
    struct stack *t;
    t=malloc(sizeof(struct stack));
}

void push(struct stack **top,int value)
{
    struct stack *t,*temp;
    t=createnode();
    t->data=value;
    t->next=NULL;
    if(*top==NULL)
    {
        *top=t;
    }
    else{
        temp=*top;
        t->next=temp;
        *top=t;
        }
}
int pop(struct stack **top)
{
    struct stack *d;
    int n;
    d=*top;
    n=d->data;
    *top=d->next;
    free(d);
    return n;
}
void traverse(struct stack **top)
{
    struct stack *t;
    t=*top;
    while (t!=NULL)
    {
        printf("%d \n",t->data);
        t=t->next;
    }
}
int peek(struct stack **top)
{
    return (*top)->data;
}
void main()
{   
    struct stack *top=NULL;
    int ch,value,j,m,i;
    
    while(1)
    {
        printf("Enter 1 for push");
        printf("Enetr 2 to pop");
        printf("Enter 3 to traverse");
        printf("Enter 4 to epeek");
        printf("Enter 5 for exit");
        scanf("%d",&ch);
        switch(ch)   
        {
            case 1:
                printf("enter a no ");
                scanf("%d",&value);
                push(&top,value);
                break;
            case 2:
                j=pop(&top);
                printf("pop value is %d \n: ",j);
                break;
            case 3:
                traverse(&top);
                break;
            case 4:
                // printf("enter a no ");
                // scanf("%d",&i);
                m= peek(&top);    
                printf("peek value is %d \n:",m);
                    break; 
             case 5:
                exit(0);      
                break; 
       
            default:
                printf("invalid input");

        }
    }
}


