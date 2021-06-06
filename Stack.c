#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};

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
        printf("stack is empty");    }
    else{
        (*s)->arr[(*s)->top]=value;
        (*s)->top++;
    }
}
void pop(struct stack **s)
{
    if(isempty(s))
    {
        printf("stack is empty");
    }
    else{
    
        (*s)->top--;
        
    }
}
void traversal(struct stack **s)
{
    
    for(int i=0;i<(*s)->top;i++)
    {
        printf("%d",(*s)->arr[i]);
    }
}
void main()
{
    int ch,value;
    struct stack *s;
     s->arr=(int*)malloc(s->size*sizeof(int));
    
    while(1)
    {
        printf("Enter 1 for push");
        printf("Enetr 2 to pop");
        printf("Enter 3 to exit");
        printf("Enter 4 to traverse");
        printf("Enter 5 for display");
        printf("press 6 for exit");
        scanf("%d",&ch);
        switch(ch)   
        {
            case 1:
                printf("enter a no ");
                scanf("%d",&value);
                push(&s,value);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                exit(0);      
                break;
            case 4:
                traversal(&s);
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

