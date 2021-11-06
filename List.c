#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct _NODE{
    int val;
    struct _NODE *next;
}NODE;

void trvl_r(NODE *h){
    if(h==NULL) return;
    printf("%d\n",h->val);
    trvl_r(h->next);
}

void trvl(NODE *h){
    NODE* temp=h;
    while(temp){
        printf("%d\n",temp->val);
        temp=temp->next;
    }
}

bool search(NODE* h, int v){
    NODE *temp=h;
    while(temp){
        if(temp->val==v) return true;
        temp=temp->next;
    }
    return false;
}

NODE *insert_head(NODE* h,int v){
    NODE* temp=(NODE*)malloc(sizeof(NODE));
    temp->val=v;
    if(!h) return temp;
    temp->next=h;
    return temp;
}

NODE *insert_tail(NODE* h,int v){
    NODE* node=(NODE*)malloc(sizeof(NODE));
    node->val=v;
    node->next=NULL;
    if(!h) return node;
    NODE* temp=h;
    while(temp->next){
        temp=temp->next;
    }
    temp->next=node;
    return h;
}

NODE *del(NODE *h, int v){
	if(h->val==v){
		free(h);
		return NULL;
	} 
	NODE* temp=h;
	while(temp->next!=NULL&&temp->next->val!=v){
		temp=temp->next;
	}
	if(temp->next==NULL) return h;
	NODE* delete=temp->next;
	temp->next=temp->next->next;
	free(delete);
	return h;
}

NODE* merge(NODE* h1, NODE* h2){
    //NODE* new_node=(NODE*)malloc(sizeof(NODE));
    //new_node->val=0;
	NODE* head;
	NODE* i;
    if(h1->val<h2->val){
        head=h1;
        i=h1;
        h1=h1->next;
    }
    else{
        head=h2;
        i=h2;
        h2=h2->next;
    }

	while(h1&&h2){
		if(h1->val<h2->val){
			i->next=h1;
			h1=h1->next;
		}
		else{
			i->next=h2;
			h2=h2->next;
		}
        i=i->next;
	}

    if(!h2) i->next=h1;
    if(!h1) i->next=h2;

    return head;
}

NODE *insert_sorted(NODE *h, int v)
{
    NODE* new_node=(NODE*)malloc(sizeof(NODE));
    new_node->val=v;
    if(!h) return new_node;
    NODE* head=h;
    while(h){
        if(v>h->val&&v<h->next->val) break;
        h=h->next;
    }
    new_node->next=h->next;
    h->next=new_node;

    return head;
}

NODE *reverse(NODE* h){
    if(h==NULL) return NULL;
    if(!h->next) return h;
    NODE *next,*pre;
    next=h->next;
    h->next=NULL;
    pre=h;
    h=next;
    while(h){
        next=h->next;
        h->next=pre;
        pre=h;
        h=next;
    }

    printf("%d",pre->val);
    return pre;

}

NODE *del_repeat_remain_one(NODE *h)
{
    if(!h) return NULL;
    NODE *i=h,*j;
    while(i->next&&i->val!=i->next->val){
        i=i->next;
    } 
    if(!i->next) return h;
    else{
        j=i->next;
        while(j->next&&j->val==j->next->val) j=j->next;
        i->next=j->next;
    }
    return h;

}

NODE *del_repeat(NODE *h)
{
    if(!h) return NULL;
    if(!h->next) return h;
    if(h->val==h->next->val) return NULL;
    NODE *i=h,*j;
    while(i->next&&i->next->next&&i->next->val!=i->next->next->val){
        i=i->next;
    } 
    if(!i->next->next) return h;
    else{
        j=i->next->next;
        while(j->next&&j->val==j->next->val) j=j->next;
        i->next=j->next;
    }

    return h;
}


int main()
{
    NODE* node1=(NODE*)malloc(sizeof(NODE));
    node1->val=1;
    NODE* node2=(NODE*)malloc(sizeof(NODE));
    node2->val=5;
    node1->next=node2;
    NODE* node3=(NODE*)malloc(sizeof(NODE));
    node3->val=5;
    node2->next=node3;
    NODE* node4=(NODE*)malloc(sizeof(NODE));
    node4->val=7;
    node3->next=node4;
    node4->next=NULL;

	//NODE* node4=(NODE*)malloc(sizeof(NODE));
    //node4->val=2;
    //NODE* node5=(NODE*)malloc(sizeof(NODE));
    //node5->val=3;
    //node4->next=node5;
    //NODE* node6=(NODE*)malloc(sizeof(NODE));
    //node6->val=4;
    //node5->next=node6;
    //node6->next=NULL;

    //NODE* head=insert_head(node1,4);
    //head=insert_tail(head,8);
	//head=del(head,9);
    
    //if(search(node1,4)==false) printf("111");
	//merge(node1, node4);
    //insert_sorted(node1,3);
    NODE *head=del_repeat(node1);
    trvl(head);
    return 0;
}