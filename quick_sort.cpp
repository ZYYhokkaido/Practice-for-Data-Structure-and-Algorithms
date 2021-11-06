#include <stdio.h>

void quick_sort(int left, int right, int a[])
{
    if(left>=right){
        return;
    }
    
    int i,j,temp;
    i=left;
    j=right;
    
    while(i<j){
        while(a[j]>=a[left]&&i<j){
            j--; 
        }
        while(a[i]<=a[left]&&i<j){
            i++;
        }
        printf("i=%d j=%d\n",i,j);
        if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    
    temp=a[i];
    a[i]=a[left];
    a[left]=temp;
    quick_sort(left,i-1,a);
    quick_sort(i+1,right,a);
}

int main()
{
    int arr[]={3,7,2,1,6,5,4,8};

    quick_sort(0,7,arr);
    for(int i=0;i<8;i++) printf("%d ",arr[i]);
        
    return 0;
}