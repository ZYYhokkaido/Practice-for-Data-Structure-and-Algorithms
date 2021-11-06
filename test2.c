#include <stdio.h>
#include <stdlib.h>

typedef struct CELL {
    int data; struct CELL *next;
} CELL;

CELL * CELL_alloc (int data){
    CELL *p = malloc (sizeof (CELL));
    p->data = data; p->next = NULL; return p;
}

void insert2 (CELL **head_p, int data){
    CELL *new = CELL_alloc (data);
    CELL **p = head_p;
    while((*p)!=NULL && (*p)->data < data ){
        p = &(*p)->next;// 次のnextメンバーを指す
    }
    new->next = *p;
    *p = new;
}

int main(){
    CELL *head = NULL;
    
    insert2 (&head,10);
    insert2 (&head,30);
    insert2 (&head,20);
    CELL *cur = head;
    
    while(cur){
        printf("%d",cur->data);
        cur=cur->next;
    }

    return 0;
}

