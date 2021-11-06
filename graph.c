#include <stdio.h>
#include <stdbool.h>
#define N 7

const int a[N][N] = {
    {0,1,1,0,0,0,0},
    {1,0,1,1,0,0,0},
    {1,1,0,0,1,0,0},
    {0,1,0,0,1,1,0},
    {0,0,1,1,0,0,1},
    {0,0,0,1,0,0,0},
    {0,0,0,0,1,0,0},
};

void print_path(int n, int path[])
{
    for (int i=0;i<n;i++){
        printf("%d", path[i]);
    }
    printf("\n");
}

void dfs(int step, int goal, int path[], bool visited[]){
    printf("1\n");
    int x = path[step - 1];
    if(x==goal){
        print_path(step,path);
    } 
    else{
        for(int i = 0; i < N; i++){
            if(a[x][i]==0) continue;
            if(!visited[i]){
                path[step] = i;
                visited[i] = true;
                dfs( step+1, goal , path, visited);
                visited[i] = false;
            }
        }
    }
}
/*

      2 
    /   \
  1       4 -- 5
    \   /
      3 

path: 1 2 4 5   //print

path: 1 3 4 5   //print

递归：
1. 由当前的情况，求下一个情况
2. 终止条件

f(n) = f(n-1) + f(n-2)
f1=1
f2=1

1 1 2 3 5 
f(5) = f(4) + f(3) 

int fib(int n){
    if(n==2||n==1) return 1;
    return fib(n-1)+fib(n-2);
}

访问v
void DFS(Vertex v){
    visited[v] = true;
    //TODO
    
    for(Vertex w: v的相邻点){
        if( ! visited[w]){
            DFS(w);
        }
    }
}

DFS(1)
相邻点:2 3 
将要执行DFS(2)
还剩: 3


DFS(2)
相邻点: 4 5
将要执行DFS(4)
还剩: 5

DFS(4)
相邻点: 8 9
将要执行DFS(8)
还剩: 9

DFS(8)


void DFS(Vertex start){
    Stack<> stack;
    stack.push(start);
    Vertex current;
    
    while( !stack.empty()){
        current = stack.pop();
        visited[v] = true;
        for(Vertex v: current的相邻点){
            if( ! visited[v]){
                stack.push(v);
            }
        }
        
    }


    bool seen[]

    stack.push(start);
    seen[start] = true;

    
    for(i=0;i<N;i++){
        a[start][i] != 0;
        stack.push(i);
    }
}

*/
void traverse(int start, int goal){
    int path[N];
    bool visited[N];

    for (int i=0;i<N;i++){
        visited[i]=false;
    }

    path[0] = start;
    visited[start] = true;

    dfs(1, goal, path, visited);    
}

int main(void){
    traverse(0,6);
    return 0;
}