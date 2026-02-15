#include <stdio.h>
#define MAX 30

void create(int []);
void print(int []);
void Union(int [], int [], int []);
int member(int [], int );

int main()
{
    int set1[MAX], set2[MAX], set3[MAX];
    set1[0] = set2[0] = set3[0] = 0;

    printf("Creating first set\n");
    create(set1);
    print(set1);

    printf("Creating second set\n");
    create(set2);
    print(set2);

    // Calculating union
    Union(set1, set2, set3);

    // Printing set3 using loop
    int n, i;
    n = set3[0];
    printf("Union of the sets: ");
    for (i = 1; i <= n; i++)
    {
        printf("%d\t", set3[i]);
    }

    return 0;
}

void create(int set[])
{
    int n, i;
    printf("Enter size of array\n");
    scanf("%d", &n);
    printf("\nEnter elements:\n");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &set[i]);
    }
    set[0] = n;
}

void print(int set[])
{
    int n, i;
    n = set[0];
    printf("Printing elements of set:\n");
    for (i = 1; i <= n; i++)
    {
        printf("%d\t", set[i]);
    }
    printf("\n");
}

void Union(int set1[], int set2[], int set3[])
{
    int n, m, i;
    set3[0] = 0;

    // Copying set1 to set3
    n = set1[0];
    for (i = 0; i <= n; i++)
    {
        set3[i] = set1[i];
    }

    // Copying set2 to set3 without repeating
    m = set2[0];
    for (i = 1; i <= m; i++)
    {
        if (!member(set3, set2[i]))
        {
            set3[++n] = set2[i];
        }
    }

    set3[0] = n; // Update the size of set3
}

int member(int set[], int x)
{
    int n, i;
    n = set[0];
    for (i = 1; i <= n; i++)
    {
        if (x == set[i])
        {
            return 1;
        }
    }
    return 0; // Return 0 after checking all elements
}

