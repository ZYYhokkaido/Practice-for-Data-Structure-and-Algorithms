#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

int findTail(struct TreeNode** head){
    int i=0;
    while(head[i]){
        i++;
    }
    return i;
}

void findAllLeaf(struct TreeNode* root,struct TreeNode** store_leaf){
    if(!root){
        return;
    }
    if(!root->left && !root->right){
        store_leaf[findTail(store_leaf)]=root;
        return;
    }
    findAllLeaf(root->left,store_leaf);
    findAllLeaf(root->right,store_leaf);
}

struct TreeNode* copy(struct TreeNode* root){
    struct TreeNode* newnode=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    newnode->val=root->val;
    newnode->left=copy(root->left);
    newnode->right=copy(root->right);

    return newnode;
}

void Insert(struct TreeNode* root, int N,struct TreeNode** store_root){
    if(!root){
        struct TreeNode* temp=(struct TreeNode*)malloc(sizeof(struct TreeNode));
        temp->val=0;
        Insert(temp,N-1,store_root);
    }
    int i=0;

    struct TreeNode** store_leaf=(struct TreeNode**)malloc(sizeof(struct TreeNode*)*2*N);
    for(int i=0;i<2*N;i++){
        store_leaf[i]=NULL;
    }
    findAllLeaf(root,store_leaf);

    while(store_leaf[i]){
        struct TreeNode* L=(struct TreeNode*)malloc(sizeof(struct TreeNode));
        L->val=0;
        L->left=NULL;
        L->right=NULL;
        struct TreeNode* R=(struct TreeNode*)malloc(sizeof(struct TreeNode));
        R->val=0;
        R->left=NULL;
        R->right=NULL;
        store_leaf[i]->left=L;
        store_leaf[i]->right=R;
        
        N-=2;
        if(N==0){
            store_root[findTail(store_root)]=copy(root);
        }
        else{
            Insert(root,N,store_root);
        }
        store_leaf[i]->left=NULL;
        store_leaf[i]->right=NULL;
        i++;
    }
}

struct TreeNode** allPossibleFBT(int N, int* returnSize){
    if(N%2==0){
        return NULL;
    }

    struct TreeNode** store_root=(struct TreeNode**)malloc(sizeof(struct TreeNode*)*2*N);
    struct TreeNode* root=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val=0;
    root->left=NULL;
    root->right=NULL;
    Insert(root,N,store_root);

    *returnSize=2*N;
    return store_root;
}

int main(){
    int returnSize;
    allPossibleFBT(7,&returnSize);
    printf("%d",returnSize);

    return 0;
}