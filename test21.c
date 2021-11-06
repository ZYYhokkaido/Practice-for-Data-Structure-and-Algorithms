#include <stdio.h>

int main(){

    int i;
    double sum,temp=1,unknown;

    scanf("%lf",&unknown);
    sum=0;
    for(i=1;i<=100;i++){
        temp*=unknown;
        printf("%f\n",temp);
        sum+=temp;
    }

    printf("%f",sum);
    

   /*int i;
   double start,sum=0,temp=1,unknown;
   
   scanf("%lf",&unknown);
   for(i=2;i<=10000;i++){
        temp*=unknown;
        sum+=temp;
   }

   printf("%f %f",unknown,sum);
   */
    return 0;
}