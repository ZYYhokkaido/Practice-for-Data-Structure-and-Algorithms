#include <stdio.h>
#include <stdlib.h>

typedef struct _BST{
    int val;
    struct _BST *left,*right;
}BST;

BST *insert(BST *t, int val){
    BST *node = (BST*)malloc(sizeof(BST));
    node->val=val;
    node->left=NULL;
    node->right=NULL;
    BST *temp=t,*parent;
    if(t==NULL) return node;
    while(temp){
        if(temp->val>val){
            parent=temp;
            temp=temp->left;
        }
        else{
            parent=temp;
            temp=temp->right;
        }
    }
    if(val>parent->val) parent->right=node;
    else parent->left=node;
    return t;
}

void trvl_post_r(BST *r){
    if(r==NULL) return;
    printf("%d\n",r->val);
    trvl_post_r(r->left);
    trvl_post_r(r->right);
}

int max(int t1, int t2){
    if(t1>t2) return t1;
    else return t2;
}

int height(BST *t){
    if(t==NULL) return 0;
    int temp = max(height(t->left), height(t->right));
    return 1 + temp;
}

void trvl_level(BST *t){




}

int main(){
    BST* root=(BST*)malloc(sizeof(BST));
    root->val=8;
    root->left=NULL;
    root->right=NULL;
    root = insert(root,4);
    root = insert(root,15);
    root = insert(root,9);
    //printf("%d\n",root->left->val);
    trvl_post_r(root);
    printf("%d",height(root));

    return 0;
}