#include <stdio.h>

void DFS(int **graph,int visit[],int number){
    visit[number]=1;
    printf("%d",number);

    for(int i=0;i<5;i++){
        if(graph[number][i]>0 && visit[i]==0){
            DFS(graph,visit,i);
        }
    }
}

int main(){

    int graph[5][5]={{0,10,3,0,0},{0,0,0,5,0},{0,2,0,0,15},{0,0,0,0,11},{0,0,0,0,0}};

    int visit[5]={0,0,0,0,0};

    DFS(graph,visit,0);

    return 0;
}