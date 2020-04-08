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
    TreeNode* binaryTreeFromLevelOrder(const string& s) {
        if (s.size()==0)
            return nullptr;
        
        

        for (int i=0;i<s.size();i++){

        }


    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root==nullptr) return {};
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()){
            int size = q.size(); /*That was my difficulty! Whatch your back!*/
            vector<int> level;
            for (int i=0;i<size;i++){
                TreeNode *node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left!=nullptr) q.push(node->left);
                if (node->right!=nullptr) q.push(node->right);
            }
            ans.push_back(level);
        }
        return ans;
    }

    void showTree(const vector<vector<int>>& v){
        cout << "[" << endl;
        for (auto i:v){
            cout << "[";
            for (auto j:i){
                cout << j << ",";
            }
            cout << "]" << endl;
        }
        cout << "]" << endl;
    }
};

int main(){
    string s = "3,9,20,null,null,15,7";

    Solution sol;
    TreeNode* root = sol.binaryTreeFromLevelOrder(s);

    sol.showTree(sol.levelOrder(root));
    
    return 0;
}