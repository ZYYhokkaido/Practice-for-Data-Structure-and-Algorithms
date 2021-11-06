#include <stdio.h>
#include <queue>

#define N 5
using namespace std;
queue<int> q;

int visited[N]={0,0,0,0,0};

void DFS(int graph[][N],int number){
    visited[number]=1;
    printf("%d ",number);

    for(int i=0;i<N;i++){
        if(graph[number][i]>0 && visited[i]==0){
            DFS(graph,i);
        }
    }
}

void BFS(int graph[][N],int number){
    q.push(number);

    while(!q.empty()){
        int front=q.front();
        q.pop();
        visited[front]=1;
        printf("%d ",front);

        for(int i=0;i<N;i++){
            if(graph[front][i]>0 && visited[i]==0){
                q.push(i);
                visited[i]=1;
            }
        }
    }    

}

int main(){
    int graph[N][N]={{0,10,3,0,0},{0,0,0,5,0},{0,2,0,0,15},{0,0,0,0,11},{0,0,0,0,0}};

    //DFS(graph,0);

    BFS(graph,0);

    return 0;
}