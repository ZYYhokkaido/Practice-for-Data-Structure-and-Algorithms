#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fibonacci(int N,int arr[]){
    if(N==0) return arr[N];
    if(N==1) return arr[N];
    if(arr[N]!=0) return arr[N];
    arr[N]=fibonacci(N-1,arr)+fibonacci(N-2,arr);
    return arr[N];
}

int fib(int N){
    if(N==0) return 0;
    if(N==1) return 1;
    int arr[N+1];
    arr[0]=0;
    arr[1]=1;
    for(int i=2;i<=N;i++){
        arr[i]=0;
    }

    return fibonacci(N,arr);
}

int main(){
    printf("%d",fib(2));


    return 0;
}