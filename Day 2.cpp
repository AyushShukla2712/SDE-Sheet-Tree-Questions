#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode* create(int val){
    struct TreeNode* n=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    n->val=val;
    n->left=NULL;
    n->right=NULL;
    return(n);
}
void levelorder(struct TreeNode* root){
    if(root==NULL)
        return;
    queue<struct TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        struct TreeNode* n=q.front();
        q.pop();
        cout<<n->val<<" ";
        if(n->left!=NULL)
            q.push(n->left);
        if(n->right!=NULL)
            q.push(n->right);
    }
}
void spericaltraversal(struct TreeNode* root){
    if(root==NULL)
        return;
    stack<struct TreeNode*> st1,st2;
    st1.push(root);
    while(!st1.empty() || !st2.empty()){
        if(!st1.empty()){
            while(!st1.empty()){
                struct TreeNode* temp=st1.top();
                st1.pop();
                cout<<temp->val<<" ";
                if(temp->left!=NULL)
                    st2.push(temp->left);
                if(temp->right!=NULL)
                    st2.push(temp->right);
            }
        }
        else{
            while(!st2.empty()){
                struct TreeNode* temp=st2.top();
                st2.pop();
                cout<<temp->val<<" ";
                if(temp->right!=NULL)
                    st1.push(temp->right);
                if(temp->left!=NULL)
                    st1.push(temp->left);
            }
        }
    }
}

int heightOfTree(struct TreeNode*root){
    if(root==NULL){
        return 0;
    }
    int left=heightOfTree(root->left);
    int right=heightOfTree(root->right);
    
    return max(left,right)+1;
}
int maxm=INT_MIN;
int diameterOfBinaryTree(TreeNode*root){
    if(root==NULL){
        return 0;
    }
    int lh=heightOfTree(root->left);
    int rh=heightOfTree(root->right);
    
    int ldiameter=diameterOfBinaryTree(root->left);
    int rdiameter=diameterOfBinaryTree(root->right);
    
    return max((lh+rh+1),maxm);
}

bool isBalanced(TreeNode*root){
    if(root==NULL){
        return true;
    }
    if(abs(heightOfTree(root->left)-heightOfTree(root->right))>1){
        return false;
    }
    return heightOfTree(root->left)&&heightOfTree(root->right);
}

TreeNode*LCA(TreeNode*root,int p,int q){
    if(root==NULL||root->val==p||root->val==q){
        return root;
    }
    TreeNode*left_lca=LCA(root->left,p,q);
    TreeNode*right_lca=LCA(root->right,p,q);
    
    if(!left_lca){
        return right_lca;
    }
    else if(!right_lca){
        return left_lca;
    }
    else{
        return root;
    }
}

bool isIdentical(TreeNode*root1,TreeNode*root2){
    if(root1==NULL&&root2==NULL){
        return true;
    }
    if(root1==NULL||root2==NULL){
        return false;
    }
    if(root1->val!=root2->val){
        return false;
    }
    return isIdentical(root1->left,root2->left)&&isIdentical(root1->right,root2->right);
}

int main(){
    struct TreeNode* root=create(1);
    root->left=create(2);
    root->right=create(3);
    root->left->left=create(4);
    root->left->right=create(5);
    root->right->left=create(6);
    root->right->right=create(7);
    root->right->right->left=create(8);
    root->right->right->left->right=create(9);
    
    struct TreeNode*root2=create(1);
    root2->left=create(2);
    root2->right=create(3);
    root2->left->left=create(4);
    root2->left->right=create(5);
    root2->right->left=create(6);
    root2->right->right=create(7);
    root2->right->right->left=create(8);
    
    //levelorder(root);
    //spericaltraversal(root);
    //cout<<heightOfTree(root);
    //cout<<diameterOfBinaryTree(root);
    //cout<<isBalanced(root);
    //cout<<LCA(root,6,9)->val;
    cout<<isIdentical(root,root2);
    return(0);
}