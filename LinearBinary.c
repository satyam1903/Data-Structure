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
        printf("\n%d\n",(int)(a->ptr)[i]);
    }
}
int LinearSearch(struct Myarray *a)
{
    int n;
    printf("enter an element to search in array");
    scanf("%d",&n);
    for(int i=0;i<=a->used_size;i++)
    {
        if(a->ptr[i]==n)
        {
            return i;
        }
    }
    return -1;
    }

int BinarySearch(struct Myarray *a)
{
    int low,mid,high,n;
    low=0;
    high=a->used_size;
    
    printf("enter a elemnt to search");
    scanf("%d",&n);
    while(low<=high)
    {
        mid=(low+high)/2;
        if((a->ptr)[mid]==n)
        {
            return mid;
        }
        else if((a->ptr)[low]<n)
        {
            low=mid+1;
        }
        else{
            high=mid-1;
        }
        
    }

return -1;


}

int main()
{
    struct Myarray student;
    createArray(&student,10,5);
    setvalue(&student);
    int L=LinearSearch(&student);
    int B=BinarySearch(&student);
    printf("found element %d %d",L,B);
    show(&student);



}