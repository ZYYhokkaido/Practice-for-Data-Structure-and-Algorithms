#include <stdio.h>

void merge(int data[], int tmp[], int left, int mid, int right){
    int i=left,j=mid+1,k=0;

    while(i<=mid&&j<=right){
        if(data[i]<data[j]){
            tmp[k]=data[i];
            i++;
        }
        else{
            tmp[k]=data[j];
            j++;
        }
        k++;
    }

    while(i<=mid){
        tmp[k]=data[i];
        i++;
        k++;
    }

    while(j<=right){
        tmp[k]=data[j];
        j++;
        k++;
    }
    k=0;

    for(i=left;i<=right;i++){
        data[i]=tmp[k++];
    }

}

void mSort(int data[], int tmp[], int left, int right){
    if(right==left) return;
    int mid=(left+right)/2;
    mSort(data,tmp,left,mid);
    mSort(data,tmp,mid+1,right);
    merge(data,tmp,left,mid,right);
}

int main(){
    int data[8]={2,4,6,8,1,3,5,9};
    int tmp[8];
    mSort(data,tmp,0,7);
    for(int i=0;i<8;i++) printf("%d",data[i]);

    return 0;
}

