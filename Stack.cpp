#include <stdio.h>
#include <stack>

#define SIZE 25

typedef struct _QUEUE{
    int buf[SIZE];
    int head,tail;
}QUEUE;

bool empty(QUEUE *q){
    return q->head==q->tail;
}

void push(QUEUE *q, int val){
    if((q->tail+1)%SIZE==q->head) return;//满了
    q->buf[q->tail]=val;
    q->tail++;
    q->tail%=SIZE;
}

int pop(QUEUE *q){
    if(empty(q)) return -1;
    int temp=q->buf[q->head];
    q->head++;
    q->head%=SIZE;
    return temp;
}

int main(){
    QUEUE *q;
    q->buf[0]=3;
    q->buf[1]=5;
    q->buf[2]=1;
    q->buf[3]=4;
    q->buf[4]=8;
    q->head=0;
    q->tail=4;

    printf("%d%d%d%d%d%d",pop(q),pop(q),pop(q),pop(q),pop(q),pop(q));

    return 0;
}