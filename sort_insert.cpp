#include <iostream>
using namespace std;

void insert_sort(int *a, int len)
{
    int temp;
    int i,j;
    for (i = 1; i < len; i++)
    {
        for (j = i; j > 0; j--)
        {
            if (a[j] < a[j-1])
            {   
                temp = a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
            }
            else break;
        }
    }
}

int main()
{
    int a[5] = {3, 9, 2, 7, 1};
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", a[i]);
    }
    printf("\n");
    insert_sort(a, 5);

    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", a[i]);
    }

    return 0;
}