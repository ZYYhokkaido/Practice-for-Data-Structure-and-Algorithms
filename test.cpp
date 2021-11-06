#include <stdio.h>
#include <stdlib.h>

typedef struct CELL {
    int data; struct CELL *next;
} CELL;

CELL * CELL_alloc (int data){
    CELL *p = malloc (sizeof (CELL));
    p->data = data; p->next = NULL; return p;
}

CELL * insert1 (CELL *head, int data){
    CELL *new = CELL_alloc(data);
    CELL *p = head;
    if( head == NULL || data < head->data){ //　先頭に挿入する条件
        new->next = p; //　先頭に挿入
        return new;
    }
    else{
        while( p->next != NULL && data > p->next->data ){ //　挿入箇所を探す　
            p = p->next;
        }
        new->next = p->next; p->next = new;
        return head;
    }
}

int main(){
    CELL *head=NULL;
    
    head = insert1 (head,10);
    head = insert1 (head,30);
    head = insert1 (head,20);
    CELL *cur=head;
    while(cur){
        printf("%d",cur->data);
        cur=cur->next;
    }
    return 0;
}

