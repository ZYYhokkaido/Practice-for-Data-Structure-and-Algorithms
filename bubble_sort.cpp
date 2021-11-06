#include <iostream>
using namespace std;

void bubble_sort(int *a, int len)
{
    int i, j, temp;
    for (i = len - 1; i >= 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
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
    bubble_sort(a, 5);

    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", a[i]);
    }

    return 0;
}