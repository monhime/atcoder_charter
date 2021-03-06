#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
using namespace std;

struct Node{
    int key;
    Node *right,*left,*parent;
};

Node *root,*NIL;

void insert(int k){
    Node *y=NIL;
    Node *x=root;
    Node *z;

    z=(Node *)malloc(sizeof(Node));
    z->key=k;
    z->left=NIL;
    z->right=NIL;

    while(x!=NIL){
        y=x;
        if(z->key<x->key)
            x=x->left;
        else
            x=x->right;
    }
    z->parent=y;
    if(y==NIL)
        root=z;
    else{
        if(z->key<y->key)
            y->left=z;
        else
            y->right=z;
    }    
}
void inorder(Node *u){
    if(u==NIL)return;
    inorder(u->left);
    printf(" %d",u->key);
    inorder(u->right);
}
void preorder(Node *u){
    if(u==NIL)return;
    printf(" %d",u->key);
    preorder(u->left);
    preorder(u->right);
}
int main(){
    int n,x;
    char com[7];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>com;
        if(com[0]=='i'){
            cin>>x;
            insert(x);
        }else if(com[0]=='p'){
            inorder(root);
            putchar('\n');
            preorder(root);
            putchar('\n');


        }

    }
    
    return 0;

}

