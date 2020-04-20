#include<bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node *right, *left;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
}; 

Node* recursive(Node* root, Node* parent, int x){
    if (root->val>x && !root->left && !root->right){
        if (parent->val<=x)
            return parent;
        else return nullptr;
    }

    if (root->val<x && !root->left && !root->right){
        return root;   
    }
    
    if (root->val==x)
        return root;
    
    if (root->val<x && root->right!=nullptr)
        return recursive(root->right,root,x);
    
    if (root->val>x && root->left!=nullptr)
        return recursive(root->left,root,x); 
}
// Time: O(h)
// Space: O(h)

Node* solution(Node* tree, int x){
    if (tree==nullptr)
        return tree;
    
    return recursive(tree,tree,x);
}

/*
                   10
                 /    \               
                3      13
               / \       \
              2   6       15
              
             Input: 14,  Result: 13
root: 2
parent: 3
x: 1
*/

int main(){
    Node* root = new Node(10);
    root->left = new Node(3);
    root->right = new Node(13);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->right = new Node(15);
    
    int x = 10;

    Node* node = solution(root,x);
    if (!node)
        cout << "nullptr" << endl;
    else cout << node->val << endl;
    
    return 0;
}
