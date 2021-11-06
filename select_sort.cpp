#include <iostream>
using namespace std;

void select_sort(int *a, int len)
{
    int i,j,temp,change;
    for(i=0;i<len-1;i++){
        temp=i;
        for(j=i+1;j<len;j++){
            if(a[temp]>a[j]){
                temp=j;
            }
        }
        change=a[temp];
        a[temp]=a[i];
        a[i]=change;
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
    select_sort(a, 5);

    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", a[i]);
    }

    return 0;
}