#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
    Node(int x) : val(x), left(nullptr), right(nullptr) {};
    Node(int x, Node* p) : val(x), left(nullptr), right(nullptr), parent(p) {};
};

static int speedUp=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if (node == nullptr)
            return nullptr;
        
        if (node->right){
            Node* q = node->right;
            while (q->left!=nullptr)
                q = q->left;
            return q;
        }
        else {
            Node* p = node;
            Node* parent = node->parent;
            while (parent && parent->left != p){
                p = parent;
                parent = parent->parent;
            }
            return parent;
        }
    }
};
// Time: O(h)
// Space: O(1)

int main(){
    Node* root = new Node(2);
    root->left = new Node(1,root);
    root->right = new Node(3,root);
    Solution sol;
    
    Node* ans = sol.inorderSuccessor(root->left);
    if (ans)
        cout << ans->val << endl;
    else cout << "null" << endl;

    return 0;
}