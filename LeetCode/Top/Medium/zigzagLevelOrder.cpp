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
    struct TreeNode *left,*right;
    TreeNode(int x): val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root==nullptr)
                return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        while (!q.empty()){
            int size = q.size();
            vector<int> level;
            for (int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (!leftToRight)
               reverse(level.begin(),level.end());
            ans.push_back(level);
            leftToRight = !leftToRight;
        }
        return ans;
    }
};

class Solution2 { // 2 stacks
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root==nullptr)
            return {};
        vector<vector<int>> ans; 

        stack<TreeNode*> currentLevel;
        stack<TreeNode*> nextLevel;

        currentLevel.push(root);
        bool lefttoright = true;
        vector<int> level;
        while (!currentLevel.empty()){

            TreeNode* node = currentLevel.top();
            currentLevel.pop();
            
            if (node!=nullptr){
                level.push_back(node->val);
                
                if (lefttoright){
                    if (node->left!=nullptr) nextLevel.push(node->left);
                    if (node->right!=nullptr) nextLevel.push(node->right);
                }
                else{
                    if (node->right!=nullptr) nextLevel.push(node->right);
                    if (node->left!=nullptr) nextLevel.push(node->left);                    
                }
            }

            if (currentLevel.empty()){
                lefttoright = !lefttoright;
                swap(currentLevel,nextLevel);
                ans.push_back(level);
                level.clear();
            }

        }
        return ans;
    }
};


int main(){
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<vector<int>> ans = sol.zigzagLevelOrder(root);

    for (auto i:ans){
        for (auto j:i){
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}