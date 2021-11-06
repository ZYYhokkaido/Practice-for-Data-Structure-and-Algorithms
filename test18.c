#include <stdio.h>
#include <string.h>

int main()
{
    int len,judge=0;
    char arr[10];
    scanf("%s",arr);
    len=strlen(arr);

    if(arr[0]=='h'&&len%2==0){   
        for(int i=0;i<=len-2;i=i+2){
            if(arr[i]!='h'||arr[i+1]!='i'){
                judge=1;
                break;
            }
        }
        if(judge==1) printf("No");
        else printf("Yes");
    }

    else printf("No");

    return 0;
}