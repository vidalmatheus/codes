#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        if (root==nullptr)
            return false;
        
        return isValidPath(root,arr,0);
    }
    
    bool isValidPath(TreeNode* root, vector<int>& arr, int pos){
        if (root==nullptr || pos==arr.size())
            return false;
        
        if (root->left==nullptr && root->right==nullptr && root->val==arr[pos] && pos==arr.size()-1)
            return true;
        
        if (arr[pos]!=root->val)
            return false;
        
        return isValidPath(root->left,arr,pos+1) || isValidPath(root->right,arr,pos+1);
    }
};
// Time: O(m)
// Space: O(m)

int main(){
    TreeNode* root = new TreeNode(0);
    TreeNode* left = new TreeNode(1,new TreeNode(0),new TreeNode(1));
    left->left->right = new TreeNode(1);
    left->right->left = new TreeNode(0);
    left->right->right = new TreeNode(0);

    TreeNode* right = new TreeNode(0);
    right->left = new TreeNode(0);

    root->left = left;
    root->right = right;

    // vector<int> arr{0,1,0,1};
    // vector<int> arr{0,0,1};
    vector<int> arr{0,1,1};

    Solution sol;
    sol.isValidSequence(root,arr) ? cout << "true\n" : cout << "false\n";
    
    return 0;
}
