#include <stdio.h>

int coinChange(int* coins, int coinsSize, int amount){
    if(coinsSize==0) return -1;
    if(amount==0) return 0;
    if(amount<coins[0]) return -1;
    if(amount==coins[coinsSize-1]) return 1;
    int dp[amount+1],i,j;
    
    for(i=0;i<coins[0];i++) dp[i]=-1;
    for(i=0;i<coinsSize;i++){
        if(coins[i]>amount) break;
        else dp[coins[i]]=1;
    }
    
    for(i=coins[0]+1;i<=amount;i++){
        if(dp[i]==1) continue;
        for(j=coinsSize-1;j>=0;j--){
            if(i>coins[j]) break;
        }
        if(dp[coins[j]]==-1||dp[i-coins[j]]==-1) dp[i]=-1;
        else dp[i]=dp[coins[j]]+dp[i-coins[j]];
    
    }
    
    return dp[amount];
}

int main(){
    int coins[3]={1,2,5};

    printf("%d\n",coinChange(coins,3,100));

    return 0;
}