#include <stdio.h>
#include <stdlib.h>

#define SIZE 24

typedef struct _NODE{
    int val;
    _NODE *next;
}NODE;

typedef struct _QUEUE{
    NODE *head,*tail;
}QUEUE;

bool empty(QUEUE *q){
    return q->head==NULL;
}

void push(QUEUE *q, int val){
    NODE *new_node=(NODE*)malloc(sizeof(NODE));
    new_node->val=val;
    new_node->next=NULL;
    if(!q->head){
        q->head=new_node;
        q->tail=new_node;
    }
    else{
        q->tail->next=new_node;
        q->tail=new_node;
    }
}

int pop(QUEUE *q){
    if(empty(q)) return -1;

    NODE* temp=q->head;
    int v_temp=temp->val;
    q->head=q->head->next;
    delete temp;
    return v_temp;
}

int main(){
    QUEUE *q=(QUEUE*)malloc(sizeof(QUEUE));
    push(q,5);
    push(q,8);
    push(q,6);

    printf("%d%d%d%d",pop(q),pop(q),pop(q),pop(q));

    return 0;
}