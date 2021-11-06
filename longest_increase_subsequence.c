#include <stdio.h>

int lengthOfLIS(int* nums, int numsSize){
    if(numsSize==0){
        return 0;
    }
    
    int dp[numsSize];
    for(int i=0;i<numsSize;i++){
        dp[i]=0;
    }
    
    for(int i=0;i<numsSize;i++){
        int max=0;
        for(int j=i-1;j>=0;j--){
            if(nums[j]<nums[i] && dp[j]>max){
                dp[i]=dp[j]+1;
                max=dp[j];
            }
        }
        if(dp[i]==0){
                dp[i]=1;
        }
    }
    
    int max=0;
    int index;
    for(int i=0;i<numsSize;i++){
        if(dp[i]>max){
            max=dp[i];
            index=i;
        }
    }
    
    return dp[index];
}

int main(){
    int array[1]={10};
    lengthOfLIS(array,1);

    return 0;
}

