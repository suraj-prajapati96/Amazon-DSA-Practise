#include<bits/stdc++.h>
using namespace std;

struct  Node{
    int key;
    Node *left,*right;
};
Node * newNode(int key){
    Node * node = new Node;
    node->key = key;
    node->left=node->right=NULL;
    return (node);
}

void flatten(struct Node * root){
    while(root){
        if(root->left!=NULL){
        Node * curr = root->left;
        while(curr->right!=NULL){
            curr = curr->right;
        }
        curr->right = root->right;
        root->right = root->left;
        root->left=NULL;
        }
        root = root->right;
    }
}

void preorder(struct Node * root){
    if(root==NULL){
        return;
    }
    cout<<root->key<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(5);
    root->left->right = newNode(4);
    root->right->right=newNode(6);
    flatten(root);
    preorder(root);
    return 0;
}