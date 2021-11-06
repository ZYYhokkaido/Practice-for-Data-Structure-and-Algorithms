#include <stdio.h>
#include <stdlib.h>

int leap_year(int year, int *list, int list_num){
  if((year%4==0&&year%100!=0)||(year%400==0)){
    printf("%dはうるう年です\n",year);
    *(list+list_num*sizeof(int))=year;
    //*(list+list_num*sizeof(int))=year;
    return 1;
    }

  else{
    printf("%dはうるう年ではありません\n",year);
    return -1;
  }
}


int main(void){
  int *leap_list[5];
  int j,i,temp,year;
for(j=0;j<5;j++){
leap_list[j]=malloc(sizeof(int));
}
/*
for(j=0;j<5;j++){
printf("%p\n",leap_list[j]);
}

int test[5]={20000000,3,4,5,6};
int *testp;
testp=&test[0];
for(j=0;j<5;j++){
printf("%p\n",&test[j]);
}
for(j=0;j<5;j++){
printf("%d\n",*(testp+j));
}
*/

j=0;
  while(j<5){
    printf("年数を入力して下さい:");
    scanf("%d",&year);
    if(year<0){
      printf("入力が範囲外です\n");
    }
    else{
      if(leap_year(year,*leap_list,j)==1){
	      j++;
      }
    }
  }

  for(j=0;j<4;j++){
    for(i=j+1;i<5;i++){
      if(*leap_list[i]<*leap_list[j]){
	temp=*leap_list[j];
	*leap_list[j]=*leap_list[i];
        *leap_list[i]=temp;
      }
    }
  }
    for(j=0;j<5;j++){
      printf("%d:%d年\n",j+1,*leap_list[j]);
    }

    return 0;
  }
  