#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <stack>

using namespace std;

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

void trvl_pre_r(BST *r){
    if(r==NULL) return;
    printf("%d\n",r->val);
    trvl_pre_r(r->left);
    trvl_pre_r(r->right);
}

void trvl_pre(BST *r){
    if(!r) return;
    stack<BST*> s;
    s.push(r);
    while(!s.empty()){
        BST* temp=s.top();
        s.pop();
        printf("%d\n",temp->val);
        if(temp->right) s.push(temp->right);
        if(temp->left) s.push(temp->left);
    }
}

void trvl_in(BST *r){
    if(!r) return;
    stack<BST*> s;
    s.push(r);
    while(!s.empty()){
        BST* temp=s.top();
        if(temp->right) s.push(temp->left);
        printf("%d\n",temp->val);

    }
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
    if(t==NULL) return;
    queue<BST*> q;
    q.push(t);
    while(!q.empty()){
        BST* temp=q.front();
        q.pop();
        printf("%d\n",temp->val);
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}

int main(){
    BST* root=(BST*)malloc(sizeof(BST));
    root->val=8;
    root->left=NULL;
    root->right=NULL;
    root = insert(root,4);
    root = insert(root,15);
    root = insert(root,9);
    root = insert(root,21);
    root = insert(root,2);
    root = insert(root,1);
    //printf("%d\n",root->left->val);
    //trvl_pre_r(root);
    //printf("%d",height(root));
    //trvl_level(root);
    trvl_pre(root);
    return 0;
}