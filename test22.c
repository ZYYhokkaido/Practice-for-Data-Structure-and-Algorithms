#include <stdio.h>

int compare(int a, int b){
    if(a>b){
        return a;
    }
    
    else{
        return b;
    }
    
}

int main(){
    int amount,max;
    scanf("%d %d",&amount,&max);
    int value[amount+1],weight[amount+1];
    
    for(int i=1;i<=amount;i++){
        scanf("%d %d",&value[i],&weight[i]);
    }
    int dp[amount+1][max+1];
    
    for(int i=0;i<=max;i++){
        dp[0][i]=0;
    }
    for(int i=0;i<=amount;i++){
        dp[i][0]=0;
    }
    
    for(int i=1;i<=amount;i++){
        for(int j=1;j<=max;j++){
            if(weight[i]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=compare(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
            }
        }
    }
    
    printf("%d\n",dp[amount][max]);

    
    return 0;

}