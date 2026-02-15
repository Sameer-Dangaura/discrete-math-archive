#include<stdio.h>
#define MAX 30

void create(int []);
void print(int []);
void Union(int [], int [], int []);
void intersection(int [], int [], int []);
void difference(int [], int [], int []);
int member(int [], int );
int main()
{
   int set1[MAX],set2[MAX],set3[MAX];
   set1[0]=set2[0]=set3[0]=0;
   
   printf("creating first set\n");
   create(set1);
   print(set1);
   
   printf("creating second set\n");
   create(set2);
   print(set2);
   
   //calculation union
   Union(set1,set2,set3);
   
   //printing set3 using loop
   int n,i;
   n=set3[0];
   printf("set operation union is:\n");
   for(i=1;i<=n;i++)
   {
    printf("%d\t",set3[i]);
   }
   printf("\n");
   
   set3[0]=0;
   //calculation intersecion
   intersection(set1,set2,set3);
    
   //printing set3 using loop
    n=set3[0];
    printf("set operation intersection is:\n");
    for(i=1;i<=n;i++)
    {
        printf("%d\t",set3[i]);
    }
    printf("\n");

    set3[0]=0;
    //calculation difference
    difference(set1,set2,set3);

    //printing set3 using loop
     n=set3[0];
     printf("set operation difference is:\n");
     for(i=1;i<=n;i++)
     {
        printf("%d\t",set3[i]);
     }
     printf("\n");

   return 0;
}

void create(int set[])
{
    int n,i;
    set[0]=0;
    printf("enter size of array\n");
    scanf("%d",&n);
    
    printf("enter elements:\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&set[i]);
    }
    set[0]=n;
}

void print(int set[])
{
    int n,i;
    n=set[0];
    
    printf("printing elements of set:\n");
    for(i=1;i<=n;i++)
    {
        printf("%d\t",set[i]);
    }
    printf("\n");
}

void Union(int set1[], int set2[], int set3[])
{
    int n,m,i;
    set3[0]=0;
    
    //copying set1 to set3 
    n=set1[0];
    for(i=0;i<=n;i++)
    {
        set3[i]=set1[i];  //here we use i=0 to give size of set1 to set3
    }
    
    //copying set2 to set3 without repeating 
    m=set2[0];
    for(i=1;i<=m;i++)
    {
       if(!member(set3,set2[i]))  //goes inside if there is not 1
       {
        set3[++n]=set2[i];  //incrementing size of set3 and inserting non repeated to set3
       }
    }
    set3[0]=n; //update size of set3
}

int member(int set[], int x)
{
    int n,i;
    n=set[0];
    for(i=1;i<=n;i++)
    {
        if(x==set[i])
        {
            return 1;
        }
    }
    return 0;   
}

void intersection(int set1[], int set2[], int set3[])
{
    int m,n=0,i;
    set3[0]=0;

    //compare set1[i] and set2
    m=set1[0];
    for(i=1;i<=m;i++)
    {
        if(member(set2,set1[i])) //when return 1 then go inside
        {
           set3[++n]=set1[i];
        }
    }
    set3[0]=n;
}

//we are performing below set1-set2
void difference(int set1[], int set2[], int set3[])
{
    int n=0,m,i;
    set3[0]=0;

    m=set1[0];
    for(i=1;i<=m;i++)
    {
        if(!member(set2,set1[i])) //goes inside if not 1
        {
            set3[++n]=set1[i];
        }
    }
    set3[0]=n;
}