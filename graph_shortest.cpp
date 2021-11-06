#include <stdio.h>

#define N 5
int visited[N]={0,0,0,0,0};
int dis[N]={10000,10000,10000,10000,10000};

int findMin(int graph[][N],int vertex){
    int min=10000,index;

    for(int i=0;i<N;i++){
        if(graph[vertex][i]<min && visited[i]==0){
            index=i;
            min=graph[vertex][i];
        }
    }

    return index;
}

int shortestPath(int graph[][N],int start,int end){
    dis[start]=0;
    visited[start]=1;
    int cur=start;
    int finish=0;

    while(finish==0){
        for(int i=0;i<N;i++){
            if(graph[cur][i]+dis[cur]<dis[i] && visited[i]==0){
                dis[i]=graph[cur][i]+dis[cur];
            }
        }
        
        visited[cur]=1;

        finish=1;
        for(int i=0;i<N;i++){
            if(visited[i]==0){
                finish=0;
            }
        }

        cur=findMin(graph,cur);
    }

    return dis[end];
}

int main(){

    int graph[N][N]={{0,10,3,10000,10000},{10000,0,10000,5,10000},{10000,2,0,10000,15},{10000,10000,10000,0,11},{10000,10000,10000,10000,0}};

    return 0;
}