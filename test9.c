#include <stdio.h>
#include <math.h>

bool zhishujudge(int a){
    int i;
    for(i=1;i<a/2;i++){
        if(a%i!=0) break;
    }
    if(i==a/2+1) return true;
    else return false;  
}

void suyinshu(int a){
    int i;
    for(i=1;i<=a;i++){
        if(a%i==0 && zhishujudge(i)==true){
            
        }
    }
}






int main(){


    return 0;
}