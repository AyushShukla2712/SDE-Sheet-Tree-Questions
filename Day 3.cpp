#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode*left;
    struct TreeNode*right;
};

struct TreeNode*create(int val){
    struct TreeNode*n=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    n->val=val;
    n->left=NULL;
    n->right=NULL;
    return n;
}


int maxPathSum(struct TreeNode*root,int &maxm){
    if(root==NULL){
        return 0;
    }
    int ls=max(0,maxPathSum(root->left,maxm));
    int rs=max(0,maxPathSum(root->right,maxm));
    maxm=max(maxm,root->val+ls+rs);
    
    return max(ls,rs)+root->val;
    
    
}
struct TreeNode*buildTree(vector<int>&preorder,int preStart,int preEnd,vector<int>&inorder,int inStart,int inEnd,map<int,int>&mp){
    if(preStart>preEnd||inStart>inEnd){
        return NULL;
    }
    struct TreeNode*root=create(preorder[preStart]);
    int inRoot=mp[root->val];
    int numLeft=inRoot-inStart;
    
    root->left=buildTree(preorder,preStart+1,preStart+numLeft,inorder,inStart,inRoot-1,mp);
    root->right=buildTree(preorder,preStart+numLeft+1,preEnd,inorder,inRoot+1,inEnd,mp);
    return root;
    
}

struct TreeNode* binaryTreeFromInPreorder(vector<int>&preorder,vector<int>&inorder){
    map<int,int>mp;
    for(int i=0;i<inorder.size();i++){
        mp[inorder[i]]=i;
    }
    
    struct TreeNode*root=buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
    return root;
}


struct TreeNode*buildTreeInPost(vector<int>postorder,int postStart,int postEnd,vector<int>&inorder,int inStart,int inEnd,map<int,int>&mp){
    if(postStart>postEnd||inStart>inEnd){
        return NULL;
    }
    struct TreeNode*root=create(postorder[postEnd]);
    int inRoot=mp[root->val];
    int numLeft=inRoot-inStart;
    
    root->left=buildTreeInPost(postorder,postStart,postStart+numLeft-1,inorder,inStart,inRoot-1,mp);
    root->right=buildTreeInPost(postorder,postStart+numLeft,postEnd-1,inorder,inRoot+1,inEnd,mp);
    return root;
}

struct TreeNode*binaryTreeFromInPostoder(vector<int>&postorder,vector<int>&inorder){
    map<int,int>mp;
    for(int i=0;i<inorder.size();i++){
        mp[inorder[i]]=i;
    }
    struct TreeNode*root=buildTreeInPost(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mp);
    return root;
}



void printPreorder(struct TreeNode*root){
    if(root==NULL){
        return;
    }
    cout<<root->val<<" ";
    if(root->left){
        printPreorder(root->left);
    }
    if(root->right){
        printPreorder(root->right);
    }
    
}

bool isSymmetric(struct TreeNode*root1,struct TreeNode*root2){
    if(root1==NULL&&root2==NULL){
        return true;
    }
    
    if(root1&&root2&&root1->val==root2->val){
        return isSymmetric(root1->left,root2->right)&&isSymmetric(root1->right,root2->left);
    }
    return false;
}

void flatten(struct TreeNode*root){
    if(root==NULL||root->left==NULL&&root->right==NULL){
        return;
    }
    
    if(root->left){
        flatten(root->left);
        
        struct TreeNode*temp=root->right;
        root->right=root->left;
        root->left=NULL;
        
        struct TreeNode*t=root->right;
        while(t->right!=NULL){
            t=t->right;
        }
        
        t->right=temp;
    }
    flatten(root->right);
}




int main(){
    struct TreeNode*root=create(1);
    root->left=create(2);
    root->right=create(3);
    root->left->right=create(-3);
    root->right->left=create(-8);
    int maxm=INT_MIN;
    vector<int>preorder={1,2,-3,3,-8};
    vector<int>inorder={2,-3,1,-8,3};
    vector<int>postorder={-3,2,-8,3,1};
    //maxPathSum(root,maxm);
    //cout<<maxm;
    //struct TreeNode*root1=binaryTreeFromInPreorder(preorder,inorder);
    //printPreorder(root1);
    //struct TreeNode*root2=binaryTreeFromInPostoder(postorder,inorder);
    //printPreorder(root2);
    //cout<<isSymmetric(root,root);
    flatten(root);
    printPreorder(root);
    
    
    return 0;
    
}