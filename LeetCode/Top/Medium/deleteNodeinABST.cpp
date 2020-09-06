#include <bits/stdc++.h>

using namespace std;

namespace helper {
    #include "BinaryTreeFromLevelOrder.cpp"
}

static int speedUp=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
        
class Solution {
public:
    helper::TreeNode* deleteNode(helper::TreeNode* root, int key) {
        if (root == nullptr)
            return nullptr;
        
        if (root->val == key){
            if (root->left && !root->right){
                helper::TreeNode* p = root;
                root = root->left;
                delete(p);
            }
            else if (!root->left && root->right){
                helper::TreeNode* p = root;
                root = root->right;
                delete(p);
            }
            else if (!root->left && !root->right){
                delete(root);
                root = nullptr;
            }
            else {
                helper::TreeNode* p = root->right;
                while (p->left != nullptr)
                    p = p->left;
                p->left = root->left;
                root = root->right;
            }
            
            return root;        
        }
        
        pair<helper::TreeNode*,helper::TreeNode*> result = searchNode(root, root, key);
        helper::TreeNode* curr = result.first;
        helper::TreeNode* parent = result.second;
        if (curr != nullptr)
            delNode(parent, curr);
        
        return root;
    }
    
    pair<helper::TreeNode*,helper::TreeNode*> searchNode(helper::TreeNode* parent, helper::TreeNode* curr, int key){ // O)log n)
        if (curr == nullptr)
            return {nullptr,nullptr};
        
        if (key > curr->val)
            return searchNode(curr, curr->right, key);
        else if (key < curr->val)
            return searchNode(curr, curr->left, key);
        else return {curr,parent};
    }
    
    pair<helper::TreeNode*, helper::TreeNode*> getInorderSuccessor(helper::TreeNode* parent, helper::TreeNode* curr){ // O(log n)
        if (curr == nullptr)
            return {nullptr,nullptr};
        
        if (curr->left == nullptr)
            return {curr,parent};
        return getInorderSuccessor(curr,curr->left);
    }
    
    /*
    pair<TreeNode*, TreeNode*> getInorderSuccessor(TreeNode* parent, TreeNode* curr){ // O(log n) - Iteratively
        if (curr == nullptr)
            return {nullptr,nullptr};
        
        while (curr->left != nullptr){
            parent = curr;
            curr = curr->left;
        }
        
        return {curr, parent};
    }
    */
    
    void delNode(helper::TreeNode* parent, helper::TreeNode* curr){ // O(log n)
        if (curr->left && curr->right){
            pair<helper::TreeNode*,helper::TreeNode*> resp = getInorderSuccessor(curr, curr->right);
            curr->val = resp.first->val;
            delNodeMostOneChild(resp.second,resp.first);            
        }
        else delNodeMostOneChild(parent, curr);
    }
    
    void delNodeMostOneChild(helper::TreeNode* parent, helper::TreeNode* curr){ // O(1)
        if (curr->left && !curr->right){
            if (parent->left == curr)
                parent->left = curr->left;
            else parent->right = curr->left;
            
        }
        else if (!curr->left && curr->right){
            if (parent->left == curr)
                parent->left = curr->right;
            else parent->right = curr->right;
        }
        else {
            if (parent->left == curr)
                parent->left = nullptr;
            else parent->right = nullptr;
        }
        delete(curr);
    }
};
// Time: O(h)
// Space: O(h)

vector<string> levelOrder(helper::TreeNode* root){
    if (!root)
        return {};
    
    vector<string> ans;
    queue<helper::TreeNode*> q;
    q.push(root);
    while (!q.empty()){
        helper::TreeNode* node = q.front();
        q.pop();
        if (node == nullptr)
            ans.push_back("null");
        else ans.push_back(to_string(node->val));
        if (node) q.push(node->left);
        if (node) q.push(node->right);
    }

    return ans;
}


int main(){
    Solution sol;
    vector<string> tree = {"5","3","6","2","4","null","7"};
    int key = 3;

    helper::Solution build;
    helper::TreeNode* root = build.binaryTreeFromLevelOrder(tree);

    vector<string> expected = {"5","4","6","2","null","null","7","null","null","null","null"};
    helper::TreeNode* newRoot = sol.deleteNode(root, key);
    vector<string> response = levelOrder(newRoot);

    assert(expected == response);
    cout << "Passed!" << endl;
    return 0;
}