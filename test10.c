#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int comp(const void *a, const void *b)
{
    if (*(int *)a > *(int *)b)
        return 1;
    else
        return -1;
}

int main()
{
    int N, i, j, judge = 0;
    scanf("%d", &N);
    long long A[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &A[i]);
    }

    qsort(A, N, sizeof(long long), comp);

    for (i = 0; i < N - 1; i++)
    {
        if (A[i] == A[i+1])
        {
            judge = 1;
            break;
        }
    }

    if (judge == 1)
        printf("NO");
    else
        printf("YES");

    return 0;
}