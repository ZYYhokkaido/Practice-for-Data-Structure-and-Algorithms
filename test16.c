#include <stdio.h>

int main(){
    int size;
    scanf("%d",&size);
    int arr[size];

    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    int sum=0;
    for(int i=0;i<size;i++){
        sum+=arr[i];
    }
    int average;
    average=sum/size;
    //printf("%d\n",average);
    sum=0;
    for(int i=0;i<size;i++){
        sum+=(arr[i]-average)*(arr[i]-average);
    }
    int min=sum;
    sum=0;
    for(int i=0;i<size;i++){
        sum+=(arr[i]-average+1)*(arr[i]-average+1);
    }
    if(sum<min) min=sum;
    sum=0;

    for(int i=0;i<size;i++){
        sum+=(arr[i]-average-1)*(arr[i]-average-1);
    }
    if(sum<min) min=sum;


    printf("%d",min);

    return 0;
}