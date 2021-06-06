#include<stdio.h>
#include<stdlib.h>
struct Myarray
{
    int total_size;
    int used_size;
    int *ptr;
};
int IndInsertion(struct Myarray *a)
{
    int n,ind;
    printf("enter a element");
    scanf("%d",&n);
    printf("enter a index no");
    scanf("%d",&ind);
    for(int i=a->used_size;i>=ind;i--)
    {
        (a->ptr)[i+1]=(a->ptr)[i];
    }
    a->ptr[ind]=n;
    (a->used_size)+=1;



}

void Deletion(struct Myarray *a)
{
    int n;
    printf("enetr a index no to delete a element");
    scanf("%d",&n);
    for(int i=n;i<=(a->used_size);i++)
    {
        (a->ptr)[i]=a->ptr[i+1];
    }
    a->used_size-=1;
}
void createArray(struct Myarray *a,int t,int u)
{
    a->total_size=t;
    a->used_size=u;
    a->ptr=(int*)malloc(t * sizeof(int));
    
}
void setvalue(struct Myarray *a)
{   
    int n;
    for(int i=0;i<a->used_size;i++)
    {
        printf("enter student roll no");
        scanf("%d",&n);
        (a->ptr)[i]=n;
    }
}
void show(struct Myarray *a)
{  
    for(int i=0;i<a->used_size;i++)
    {
        printf("%d\n",(int)(a->ptr)[i]);
    }
}

int main()
{
    struct Myarray student;
    createArray(&student,10,3);
    setvalue(&student);
    IndInsertion(&student);
    Deletion(&student);
    show(&student);



}