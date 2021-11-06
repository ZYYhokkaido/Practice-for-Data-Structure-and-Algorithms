#include <stdio.h>

int main(){
    int N,i,cnt=0;
    scanf("%d",&N);
    int P[N+1];
    for(i=1;i<=N;i++){
        scanf("%d",&P[i]);
    }

    int min=P[1];

    for(i=1;i<=N;i++){
        if(P[i]<=min){
        min=P[i];
        cnt++;
        }
    }
    printf("%d\n",cnt);

    return 0;
}