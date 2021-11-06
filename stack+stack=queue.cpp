#include <stdio.h>
#include <stdlib.h>
#include <stack>

using namespace std;

typedef struct
{
    stack<int> s1;
    stack<int> s2;
}QUEUE;

bool empty(QUEUE *q)
{
    return q->s1.empty()&&q->s2.empty();
}

void push(QUEUE *q, int x)
{
    if(q->s1.empty()) printf("2222\n");
    q->s1.push(x);
}

int pop(QUEUE *q){
    if(q->s1.empty()&&q->s2.empty()) return -1;
    int temp;
    if(q->s2.empty()){
        while(!q->s1.empty()){
            q->s2.push(q->s1.top());
            q->s1.pop();
        }
        temp=q->s2.top();
        q->s2.pop();
        return temp;
    }
    else{
        temp=q->s2.top();
        q->s2.pop();
        return temp;
    }
}

int main(){
    
    printf("!!!!\n");
    
    QUEUE *q=(QUEUE*)malloc(sizeof(QUEUE));

    printf("!!\n");

    push(q,5);
    printf("5\n");

    push(q,8);
    printf("8\n");

    push(q,6);
    printf("6\n");


    printf("%d",pop(q));
    
    return 0;
}