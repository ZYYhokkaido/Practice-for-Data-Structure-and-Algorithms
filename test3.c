#include <stdio.h>

#define N 8
#define HEAD 0
#define TAIL ((N)+1)

typedef struct _list{
    int prev;
    int next;
} DLLIST;
DLLLIST list[N+2];

void init_list(void){
    list[HEAD].next = TAIL;
    list[TAIL].prev = HEAD;
}

void insert_elem(int elem){
    int next;
    if((elem <= HEAD) || (elem >= TAIL)) return;
    next = list[HEAD].next;
    list[elem].next = next;
    list[next].prev = elem;
    list[HEAD].next = elem;
    list[elem].prev = HEAD;
}

void delete_elem(int elem){
    int next, prev;
    if((elem <= HEAD) || (elem >= TAIL)) return;
    list[elem].prev.next = list[elem].next;
    list[elem].next.prev = list[elem].prev;

}