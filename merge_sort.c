#include <stdio.h>

void merge(int arr1[], int arr2[], int start, int mid, int end)
{
    int i=start, j=mid+1, k=start;
    while (i <= mid && j <= end)
    {
        if(arr1[i]>arr1[j]){
            arr2[k++]=arr1[j++];
        }

        else arr2[k++]=arr1[i++];
    }

   while(j<=end){
        arr2[k++]=arr1[j++];
    }
    
    while(i<=mid){
        arr2[k++]=arr1[i++];
    }
    
    for(i=start;i<=end;i++){
        arr1[i]=arr2[i];
    }

    return;
}

void merge_sort(int arr1[], int arr2[], int left, int right)
{
    if(left==right) return;

    int mid=(left+right)/2;
    merge_sort(arr1,arr2,left,mid);
    merge_sort(arr1,arr2,mid+1,right);
    merge(arr1, arr2, left, mid ,right);
}

int main()
{
    int arr1[]={3,7,2,1,6,5,4,8};
    int arr2[8];

    merge_sort(arr1,arr2,0,7);
    for(int i=0;i<8;i++) printf("%d ",arr1[i]);

    return 0;
}