#include <stdio.h>

double qidaizhi(int a){
    double sum=0;
    for(int i=1;i<=a;i++){
        sum+=i;
    }
    return sum/a;
}

int main()
{
    int N,K;
    double max,sum=0;
    scanf("%d%d",&N,&K);
    int p[N];
    for(int i=0;i<N;i++){
        scanf("%d",&p[i]);
    }

    int head=K-1,tail=0;
    for(int i=0;i<K;i++){
        sum+=qidaizhi(p[i]);
    }
    max=sum;

    while(head!=N-1){
        head++;
        sum=sum+qidaizhi(p[head])-qidaizhi(p[tail]);
        tail++;
        if(sum>max) max=sum;
    }

    printf("%f",max);

    return 0;
}