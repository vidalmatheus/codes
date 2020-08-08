#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* binaryTreeFromLevelOrder(vector<string>& s) {
        if (s.size()==0 || s[0] == "null")
            return nullptr;

        TreeNode* root = new TreeNode(stoi(s[0]));
        queue<TreeNode*> q;
        q.push(root);
        for (int i=0;i<(int)s.size()-2;i++){
            if (s[i] != "null"){
                TreeNode* node = q.front();
                node->left = 2*i+1 < s.size() && s[2*i+1]!="null" ? new TreeNode(stoi(s[2*i+1])) : nullptr;
                node->right = 2*i+2 < s.size() && s[2*i+2]!="null" ? new TreeNode(stoi(s[2*i+2])) : nullptr;
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return root;
    }

    void levelOrder(TreeNode* root) {
        if (root==nullptr) return;
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        q.push(root);
        cout << "[\n";
        while (!q.empty()){
            int size = q.size(); /*That was my difficulty! Whatch your back!*/
            cout << "[ ";
            for (int i=0;i<size;i++){
                TreeNode *node = q.front();
                q.pop();
                cout << node->val << " ";
                if (node->left!=nullptr) q.push(node->left);
                if (node->right!=nullptr) q.push(node->right);
            }
            cout << "]\n";
        }
        cout << "]\n";
    }

    void preOrder(TreeNode* root){
        if (root == nullptr)
            return;
        
        cout << root->val << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

};

int main(){
    vector<string> s = {"3","9","20","null","null","15","7"};

    Solution sol;
    TreeNode* root = sol.binaryTreeFromLevelOrder(s);

    cout << "Level Order: " << endl;
    sol.levelOrder(root);

    cout << "Pre Orer: " << endl;
    sol.preOrder(root);
    
    return 0;
}
