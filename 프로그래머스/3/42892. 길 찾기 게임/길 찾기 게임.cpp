#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
struct Node{
    int num;
    Node* left=NULL;
    Node* right=NULL;
    int x;
};
Node *root;
bool cmp(vector<int> v1, vector<int> v2){
    if(v1[1]==v2[1])
        return v1[0] > v2[0];
    return v1[1]>v2[1];
}
void insert(Node *r, Node* n){
    if(r->x > n->x){
        if(r->left==NULL)
            r->left=n;
        else
            insert(r->left,n);
    }
    else{
        if(r->right==NULL)
            r->right=n;
        else
            insert(r->right,n);
    }
}
void create_tree(vector<vector<int>> nodeinfo){
    for(int i=0;i<nodeinfo.size();i++){
        Node *node=new Node;
        
        node->num=nodeinfo[i][2];
        node->x=nodeinfo[i][0];
        
        if(i==0){
            root=node;
        }
        else{
            insert(root,node);
        }
    }
}
void preorder(Node *n,vector<int>&result){
    if(n!=NULL){
        result.push_back(n->num);
        preorder(n->left,result);
        preorder(n->right,result);
    }
}
void postorder(Node *n,vector<int>&result){
    if(n!=NULL){
        postorder(n->left,result);
        postorder(n->right,result);
        result.push_back(n->num);
    }
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    for(int i=0;i<nodeinfo.size();i++){
        nodeinfo[i].push_back(i+1);
    }
    sort(nodeinfo.begin(),nodeinfo.end(),cmp);
    create_tree(nodeinfo);
    
    vector<int> result;
    preorder(root,result);
    answer.push_back(result);
    result.clear();
    postorder(root,result);
    answer.push_back(result);
    
    return answer;
}