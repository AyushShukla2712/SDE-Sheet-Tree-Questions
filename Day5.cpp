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

int floorV(struct TreeNode*root,int key){
    
    if(!root){
        return INT_MAX;
    }
    if(root->val==key){
        return root->val;
    }
    else if(root->val>key){
        return floorV(root->left,key);
    }
    else{
        int floorVal=floorV(root->right,key);
        return (floorVal<=key)?floorVal:root->val;
    }
}

int ceilV(TreeNode*root,int key){
    if(!root){
        return INT_MIN;
    }
    if(root->val==key){
        return root->val;
    }
    else if(root->val<key){
        return ceilV(root->right,key);
    }
    else{
        int ceilVal=ceilV(root->left,key);
        return (ceilVal>=key)?ceilVal:root->val;
    }
}

void kthSmallest(TreeNode*root,int k,priority_queue<int>&pq){
    if(root==NULL){
        return;
    }
    if(pq.size()<k){
        pq.push(root->val);
    }
    else if(pq.size()==k){
        if(pq.top()>root->val){
            pq.pop();
            pq.push(root->val);
        }
    }
    
    if(root->left){
        kthSmallest(root->left,k,pq);
    }
    if(root->right){
        kthSmallest(root->right,k,pq);
    }
}

int kthSmallest(TreeNode*root,int k){
    priority_queue<int>pq;
    kthSmallest(root,k,pq);
    return pq.top();
}


void kthLargest(TreeNode*root,int k,priority_queue<int,vector<int>,greater<int>>&pq){
    if(root==NULL){
        return;
    }
    if(pq.size()<k){
        pq.push(root->val);
        
    }
    else if(pq.size()==k){
        if(pq.top()<root->val){
            pq.pop();
            pq.push(root->val);
        }
    }
    
    if(root->left){
        kthLargest(root->left,k,pq);
        
    }
    if(root->right){
        kthLargest(root->right,k,pq);
    }
}

int kthLargest(TreeNode*root,int k){
    priority_queue<int,vector<int>,greater<int>>pq;
    kthLargest(root,k,pq);
    return pq.top();
}


int main(){
    struct TreeNode*root=create(50);
    root->left=create(30);
    root->right=create(70);
    root->left->left=create(20);
    root->left->right=create(40);
    root->right->left=create(60);
    root->right->right=create(80);
    
    //cout<<floorV(root,20);
    //cout<<ceilV(root,20);
    //cout<<kthSmallest(root,1);
    cout<<kthLargest(root,3);
    
    
}