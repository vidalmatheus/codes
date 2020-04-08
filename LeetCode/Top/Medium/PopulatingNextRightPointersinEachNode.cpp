#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    Node* connect(Node* root) {
        if (root==nullptr)
            return root;
        
        levelOrderPopulate(root);
        
        return root;
    }
    
    void levelOrderPopulate(Node* root){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            Node* prev = q.front();
            for (int i=0;i<size;i++){
                Node* curr = q.front();
                q.pop();
                if (prev!=curr){
                    prev->next = curr;
                    prev = curr;
                }
                if (curr->left!=nullptr) q.push(curr->left);
                if (curr->right!=nullptr) q.push(curr->right);
            }
        }
    }
};
// Time: O(n)
// Space: O(n)

int main(){
    Node* root = new Node(1,nullptr,nullptr,nullptr);
    root->left = new Node(2,nullptr,nullptr,nullptr);
    root->right = new Node(3,nullptr,nullptr,nullptr);

    root->left->left = new Node(4,nullptr,nullptr,nullptr);
    root->left->right = new Node(5,nullptr,nullptr,nullptr);

    root->right->left = new Node(6,nullptr,nullptr,nullptr);
    root->right->right = new Node(7,nullptr,nullptr,nullptr);

    Solution sol;
    root = sol.connect(root);

    return 0;
}