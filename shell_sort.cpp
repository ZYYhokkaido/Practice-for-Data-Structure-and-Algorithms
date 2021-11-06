#include <iostream>
using namespace std;

void shell_sort(int *a, int len)
{
    int gap = (int)(len / 2), i, j, temp, k;
    for (; gap >= 1; gap /= 2)
    {
        //printf("%d\n",gap);
        for (i = 0; i < gap; i++)
        {
            for (j = i + gap; j < len; j += gap)
            {
                for (k = j - gap; k >= 0; k -= gap)
                {
                    if (a[k + gap] < a[k])
                    {
                        temp = a[k + gap];
                        a[k + gap] = a[k];
                        a[k] = temp;
                    }
                    else
                        break;
                }
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
    shell_sort(a, 5);

    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", a[i]);
    }

    return 0;
}