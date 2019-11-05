#include <bits/stdc++.h>

using namespace std;

static int speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode * right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution { // Time: O(log(n)) - Space: O(log(n))
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;
        return constructBST(nums,0,nums.size()-1);
    }
private:
    TreeNode* constructBST(vector<int> &nums,int left,int right){
        if (left > right) return nullptr;
        int mid = left + (right-left)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = constructBST(nums,left,mid-1);
        root->right = constructBST(nums,mid+1,right);
        return root;
    }
};

void inOrder (TreeNode *root){
    if (root==nullptr) return;
    cout << root->val << " ";
    inOrder(root->left);
    inOrder(root->right);
}

void levelOrder (TreeNode *root){
    if (root==nullptr) return;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for (int i=0;i<size;i++){
            TreeNode *node = q.front();
            cout << node->val << " ";
            q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << endl;
    }
}

int main (){
    vector<int> nums={-10,-3,0,5,9};
    Solution sol;
    TreeNode *root = sol.sortedArrayToBST(nums);
    inOrder(root);
    cout << endl;
    levelOrder(root);
    return 0;
}