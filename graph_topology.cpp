#include <stdio.h>
#include <queue>

using namespace std;
#define N 5
queue<int> q;

int indegree[N]={0,0,0,0,0};
void calIndegree(int graph[][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(graph[i][j]>0 && graph[i][j]!=10000){
                indegree[j]++;
            }
        }
    }
}

void topology(int graph[][N]){
    for(int i=0;i<N;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int cur=q.front();
        printf("%d ",cur);
        q.pop();
        for(int i=0;i<N;i++){
            if(graph[cur][i]>0 && graph[cur][i]!=10000){
                indegree[i]--;
                if(indegree[i]==0){
                q.push(i);
                }   
            } 
        }
    }
}

int main(){
    int graph[N][N]={{0,10,3,10000,10000},{10000,0,10000,5,10000},{10000,2,0,10000,15},{10000,10000,10000,0,11},{10000,10000,10000,10000,0}};

    calIndegree(graph);
    topology(graph);

    return 0;
}