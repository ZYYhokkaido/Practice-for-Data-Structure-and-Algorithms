#include <stdio.h>
#include <stdlib.h>

double absolute(double a,double b){
  if(a>=b){
    return a-b;
  }

  else return b-a;
}


int main(void){

  FILE *fp;
  int n,j;

  if((fp=fopen("list.txt","r"))==NULL){
    fprintf(stderr,"File open error\n");
    exit(1);
  }
  fscanf(fp,"%d",&n);

  struct keisoku{
    char name[10];
    int age;
    int height;
    int weight;
    double BMI;
  };

  struct keisoku data[n];
  
  for(j=0;j<n;j++){
    fscanf(fp,"%s",data[j].name);
    fscanf(fp,"%d",&data[j].age);
    fscanf(fp,"%d",&data[j].height);
    fscanf(fp,"%d",&data[j].weight);
    double bmi;
    int p;
    bmi=(double)data[j].weight/(data[j].height/100.0*data[j].height/100.0);//25.7600
    p=(int)(bmi*10);//257
    bmi=p/10.0;//25.700000
    data[j].BMI=bmi;
  }

  struct keisoku temp[n],tem;
  for(j=0;j<n;j++){
  temp[j]=data[j];
  }
  int isa,jsa,i;
for(i=0;i<n-1;i++){
  for(j=i+1;j<n;j++){
    /*
    if(temp[i].BMI<22){
      isa=22-temp[i].BMI;}
    else if(temp[i].BMI>=22){
      isa=temp[i].BMI-22;}
    if(temp[j].BMI<22){
      jsa=22-temp[j].BMI;}
    else if(temp[j].BMI>=22){
      jsa=temp[j].BMI-22;}
      */
     if(absolute(temp[j].BMI,22)<absolute(temp[i].BMI,22)){
        tem=temp[i];
        temp[i]=temp[j];
        temp[j]=tem;
      }
  }
}

for(j=0;j<5;j++){
printf("%s(%d)\t%d %d %.1f\n",temp[j].name,temp[j].age,temp[j].height,temp[j].weight,temp[j].BMI);
}

double test=14.50;
printf("%.1f\n",test);

double test_1;
test_1=2/3;
printf("%f",test_1);


  return 0;
}
