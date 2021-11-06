#include <stdio.h>

int max(int arr[], int left, int right){
    if(arr[left]>arr[right]) return left;
    else return right;
}

void heapify(int arr[],int number,int size){
    int cur=number;
    int j=cur;
    int left=cur*2+1;
    while(left<size){

        if(left+1<size){
            j = max(arr,left,left+1);
            if(arr[j]>arr[cur]){
                int temp=arr[cur];
                arr[cur]=arr[j];
                arr[j]=temp;
            }
        }

        else{
            if(arr[left]>arr[cur]){
                j=left;
                int temp=arr[cur];
                arr[cur]=arr[j];
                arr[j]=temp;
            }
        }

        if(j==cur) return;

        cur=j;
        left=cur*2+1;
    }

    return;
}

void build_heap(int arr[],int size){
    int last=(size-1-1)/2;
    for(int i=last;i>=0;i--){
        heapify(arr,i,size);
    }
}

void removemax(int arr[],int i){
        int temp=arr[i];
        arr[i]=arr[0];
        arr[0]=temp;
        heapify(arr,0,i);
}

void heap_sort(int arr[], int size){
    build_heap(arr, size);
    for(int i=size-1;i>=0;i--) {
        removemax(arr, i); 
    }
}

int main(){
    int array[]={34,70,13,55,21,89,41};

    heap_sort(array,7);
    for(int j=0;j<7;j++){
            printf("%d\n",array[j]);
        }
    return 0;
}

