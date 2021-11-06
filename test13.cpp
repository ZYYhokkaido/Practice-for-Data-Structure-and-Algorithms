#include <stdio.h>

void merge(int a[], int m, int b[], int n, int c[], int o)
{
    int i = 0, j = 0;

    while (i != m && j != n)
    {
        printf("1111\n");
        if (a[i] < b[j])
        {
            c[i + j] = a[i];
            i++;
        }
        else
        {
            c[i + j] = b[j];
            j++;
        }
    }

    while (i != m)
        c[i + j] = a[i];
    i++;
    while (j != n)
        c[i + j] = b[j];
    j++;
}

int main()
{
    int a[3] = {1, 3, 5};
    int b[4] = {2, 4, 6, 8};
    int c[8];
    merge(a, 3, b, 4, c, 8);
    for (int i = 0; i < 2; i++)
    {
        printf("%d ", a[i]);
    }
    
    return 0;
}