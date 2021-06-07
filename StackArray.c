#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};
    struct stack *s;

void createstack()
{
    s=(struct stack *)malloc(sizeof(struct stack));
    s->top=-1;
    s->size=6;
    s->arr=(int*)malloc(6*sizeof(int));
}

int isempty(struct stack **s)
{
     
    if((*s)->top==-1)
    {
        return 1;
    }
    return 0;
}
int isfull(struct stack **s )
{   
    if((*s)->top==((*s)->size)-1)
    {
        return 1;
    }
    
    return 0;
}
void push(struct stack **s ,int value)
{
    if(isfull(s))
    {
        printf("stack is Full");    }
    else{
        (*s)->top++;
        (*s)->arr[(*s)->top]=value;
        
    }
}
int pop(struct stack **s)
{
    if(isempty(s))
    {
        printf("stack is empty");
    }
    else{
        int m=(*s)->arr[(*s)->top];
    
        (*s)->top--;
        return m;   
    }
}
void traversal(struct stack **s)
{
    
    for(int i=0;i<=(*s)->top;i++)
    {
        printf("%d\n",(*s)->arr[i]);
    }
}
int peek(struct stack **s,int i)
{
    int ArrayIndex=(*s)->top-i+1;   
    if(ArrayIndex<0)
    {
        printf("invalid position");
    }
    else{
        return (*s)->arr[ArrayIndex];
    }
}
void main()
{
    int ch,value,n,m,i;
        createstack();
    
    while(1)
    {
        printf("Enter 1 for push");
        printf("Enetr 2 to pop");
        printf("Enter 3 to traverse");
        printf("Enter 4 to peek");
        printf("Enter 5 for exit");
        scanf("%d",&ch);
        switch(ch)   
        {
            case 1:
                printf("enter a no ");
                scanf("%d",&value);
                push(&s,value);
                break;
            case 2:
                n=pop(&s);
                printf("pop value is %d \n: ",n);
                break;
            case 3:
                traversal(&s);
                break;
            case 4:
                printf("enter a no ");
                scanf("%d",&i);
                m= peek(&s,i);    
                printf("peek value is %d \n:",m);
                    break; 
             case 5:
                exit(0);      
                break; 
            // case 6:
            //     deletelastnode();     
            //     break;
            default:
                printf("invalid input");

        }
    }
}

