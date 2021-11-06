#include <stdio.h>
#include <string.h>

int main(void)
{
    int a, b, i,len;
    scanf("%d%d", &a, &b);
    if(a<=9&&a>=1&&b<=9&&b>=1){
        char A[a+1];
        char B[b+1]; 
        //printf("%d %d\n",(int)sizeof(A),(int)sizeof(B));
        //printf("%s\n",A);
        //printf("%s\n\n",B);
        for (i = 0; i < a; i++)
        {
            A[i] = b+'0';
            //printf("%s\n",A);
        }
        A[i]='\0';

        for (i = 0; i < b; i++)
        {
            B[i] = a+'0';
        }
        B[i]='\0';
        
        if(b<a){
           printf("%s\n",A);
        }
        
        else printf("%s",B);
    }
    return 0;
}
