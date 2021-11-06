#include <stdio.h>

void merge(int a[], int m, int b[], int n, int c[], int o)
{
    int i = 0, j = 0;

    while (i != m && j != n)
    {
        printf("1111111\n");
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
    {
        c[i + j] = a[i];
        i++;
    }
    while (j != n)
    {
        c[i + j] = b[j];
        j++;
    }
}

void swap(int a, int b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}

void reverse(int a[], int n)
{   
    int i,j=0,temp[n];
    for(i=n-1;i>=0;i--){
        printf("%d",j);
        temp[j++]=a[i];
        
    }
    for(int i=0;i<n;i++){
        printf("%d\n",temp[i]);
    }
    for(i=0;i<n;i++){
        a[i]=temp[i];
    }
}

int main()
{
    //int a[3] = {1, 3, 5};
    int b[5] = {1, 5, 2, 4, 8};
    reverse(b, 5);
    for(int i=0;i<5;i++){
        printf("%d\n",b[i]);
    }
    return 0;
}