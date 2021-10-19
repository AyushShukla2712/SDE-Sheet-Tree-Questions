#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node*left;
    Node*right;
    
};

Node* create(int val){
    struct Node*n=(struct Node*)malloc(sizeof(struct Node));
    n->data=val;
    n->left=NULL;
    n->right=NULL;
    return n;
}

void preorderRecursive(Node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    if(root->left){
        preorderRecursive(root->left);
    }
    if(root->right){
        preorderRecursive(root->right);
    }
    
    
}

void preorder(Node*root){
    stack<Node*>s;
    s.push(root);
    while(!s.empty()){
        Node* n=s.top();
        s.pop();
        cout<<n->data<<" ";
        if(n->right){
           s.push(n->right); 
        }
        if(n->left){
            s.push(n->left);
        }
    }
    
}

void inorderRecursive(Node*root){
    if(root==NULL){
        return;
    }
    if(root->left){
        inorderRecursive(root->left);
    }
    cout<<root->data<<" ";
    if(root->right){
        inorderRecursive(root->right);
    }
}

void inorder(Node*root){
    stack<Node*>s;
    Node *curr=root;
    while(!s.empty()||curr!=NULL){
        while(curr!=NULL){
            s.push(curr);
            curr=curr->left;
        }
        
        curr=s.top();
        s.pop();
        cout<<curr->data<<" ";
        
        curr=curr->right;
        
    }
}

void postorderRecursive(Node*root){
    if(root==NULL){
        return;
    }
    if(root->left){
        postorderRecursive(root->left);
    }
    if(root->right){
        postorderRecursive(root->right);
    }
    cout<<root->data<<" ";
    
}

void postorder(Node*root){
    stack<Node*>s1;
    stack<Node*>s2;
    s1.push(root);
    while(!s1.empty()){
        Node*n=s1.top();
        s2.push(n);
        s1.pop();
        if(n->left){
            s1.push(root->left);
        }
        if(n->right){
            s1.push(root->right);
        }
    
    }
    while(!s2.empty()){
        Node*n1=s2.top();
        cout<<n1->data<<" ";
        s2.pop();
    }
}
void leftViewOfTree(Node*root,int level,int *max_level){
    if(root==NULL){
        return;
    }
    if(*max_level<level){
        cout<<root->data<<" ";
        *max_level=level;
    }
    leftViewOfTree(root->left,level+1,max_level);
    leftViewOfTree(root->right,level+1,max_level);
}


void leftView(Node*root){
    int max_level=0;
    leftViewOfTree(root,1,&max_level);
    
}

void rightViewOfTree(Node*root,int level,int *max_level){
    if(root==NULL){
        return;
    }
    if(*max_level<level){
        cout<<root->data<<" ";
        *max_level=level;
    }
    rightViewOfTree(root->right,level+1,max_level);
    rightViewOfTree(root->left,level+1,max_level);
}

void rightView(Node*root){
    int max_level=0;
    rightViewOfTree(root,1,&max_level);
}

void topViewOfTree(Node*root,int level,int shift,map<int,pair<int,int>>&m){
    if(root==NULL){
        return;
    }
    
    if(m.count(shift)==0){
        m[shift]=make_pair(root->data,level);
        
    }
    else if(m[shift].second>level){
        m[shift]=make_pair(root->data,level);
    }
    
    topViewOfTree(root->left,level+1,shift-1,m);
    topViewOfTree(root->right,level+1,shift+1,m);
        
    
    
}


void topView(Node*root){
    int level=0;
    int shift=0;
    map<int,pair<int,int>>m;
    
    topViewOfTree(root,level,shift,m);
    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->second.first << " ";
    }
}

void bottomViewOfTree(Node*root,int level,int shift,map<int,pair<int,int>>&m){
    if(root==NULL){
        return;
    }
    if(m.find(shift)==m.end()){
        m[shift]=make_pair(root->data,level);
    }
    else{
        pair<int,int>p=m[shift];
        if(p.second<=level){
            m[shift].second=level;
            m[shift].first=root->data;
        }
    }
    bottomViewOfTree(root->left,level+1,shift-1,m);
    bottomViewOfTree(root->right,level+1,shift+1,m);
    
}

void bottomView(Node*root){
    int level=0;
    int shift=0;
    map<int,pair<int,int>>m;
    bottomViewOfTree(root,level,shift,m);
    map < int, pair < int, int > > ::iterator it;
    for (it = m.begin(); it != m.end(); ++it)
    {
        pair < int, int > p = it -> second;
        cout << p.first << " ";
    }
}

void prePostInorder(Node*root){
    vector<int>pre,post,in;
    stack<pair<Node*,int>>s;
    s.push({root,1});
    while(!s.empty()){
        auto it=s.top();
        s.pop();
        if(it.second==1){
            pre.push_back(it.first->data);
            it.second++;
            s.push(it);
            if(it.first->left!=NULL){
                s.push({it.first->left,1});
            }
            
        }
        else if(it.second==2){
            in.push_back(it.first->data);
            it.second++;
            s.push(it);
            if(it.first->right!=NULL){
                s.push({it.first->right,1});
            }
            
        }
        else{
            post.push_back(it.first->data);
        }
    }
    
    for(int i=0;i<pre.size();i++){
        cout<<pre[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<in.size();i++){
        cout<<in[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<post.size();i++){
        cout<<post[i]<<" ";
    }
}





int main(){
   
   

    Node*root=create(10);
    root->left=create(20);
    root->right=create(30);
    root->right->left=create(40);
    root->right->right=create(50);
    root->right->right->right=create(60);
    root->right->right->right->left=create(70);
    //preorderRecursive(root);
    //preorder(root);
    //inorderRecursive(root);
    //inorder(root);
    //postorderRecursive(root);
    //postorder(root);
    //leftView(root);
    //rightView(root);
    //topView(root);
    //bottomView(root);
    prePostInorder(root);
    
}