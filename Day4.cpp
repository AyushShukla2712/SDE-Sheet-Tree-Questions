#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode*left;
    struct TreeNode*right;
};

struct TreeNode*create(int val){
    struct TreeNode*n=new TreeNode();
    n->val=val;
    n->left=NULL;
    n->right=NULL;
    return n;
    
}

void findPreSuc(TreeNode*root,int key,TreeNode*&pre,TreeNode*&suc){
    if(root==NULL){
        return;
    }
    if(root->val==key){
        if(root->left){
            TreeNode*temp=root->left;
            while(temp->right){
                temp=temp->right;
            }
            pre=temp;
        }
        
        if(root->right){
            TreeNode*temp=root->right;
            while(root->left){
                temp=temp->left;
            }
            suc=temp;
        }
    }
    
    if(root->val>key){
        suc=root;
        findPreSuc(root->left,key,pre,suc);
    }
    
    if(root->val<key){
        pre=root;
        findPreSuc(root->right,key,pre,suc);
    }
}

int main(){
    struct TreeNode*root=create(50);
    root->left=create(30);
    root->right=create(70);
    root->left->left=create(20);
    root->left->right=create(40);
    root->right->left=create(60);
    root->right->right=create(80);
    
    TreeNode*pre=NULL,*suc=NULL;
    
    findPreSuc(root,65,pre,suc);
    cout<<"Predecessor: " <<pre->val<<endl;
    cout<<"Successor: " <<suc->val<<endl;
}