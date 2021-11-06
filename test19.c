#include <stdio.h>
#include <string.h>

int coupon[100000][100000];

int main()
{
    int A,B,M,temp1,temp2,temp3;
    scanf("%d %d %d",&A,&B,&M);
    int a[A],b[B];
    int sum[A][B];

    for(int i=1;i<=A;i++){
        scanf("%d",&a[i]);
    }

    for(int i=1;i<=B;i++){
        scanf("%d",&b[i]);
    }

    for(int i=1;i<=M;i++){
        scanf("%d %d %d",&temp1,&temp2,&temp3);
        if(temp3>coupon[temp1][temp2]) coupon[temp1][temp2]=temp3;
        else continue;
    }

    for(int i=1;i<=A;i++){
        for(int j=1;j<=B;j++){
            sum[i][j]=a[i]+b[j]-coupon[i][j];
        }
    }

    int min=1000001;
    for(int i=1;i<=A;i++){
        for(int j=1;j<=B;j++){
            if(sum[i][j]<min) min=sum[i][j];
        }
    }

    printf("%d\n",min);

    return 0;
}