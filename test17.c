#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(char *s)
{
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++)
    {
        swap(&s[i], &s[len - 1 - i]);
    }
}

int main()
{
    char arr[250000], read;
    int num, judge1, judge2, len;

    scanf("%s", arr);
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &judge1); 

        if (judge1 == 1)
            reverse(arr);
        else
        {
            scanf("%d", &judge2);
            scanf(" %c", &read);
            len = strlen(arr);
            if (judge2 == 1)
            {
                for (int j = len; j >= 1; j--)
                {
                    arr[j] = arr[j - 1];
                }
                arr[0] = read;
                arr[len + 1] = '\0';
            }
            else
            {
                arr[len] = read;
                arr[len + 1] = '\0';
            }
        }
    }

    printf("%s", arr);

    return 0;
}