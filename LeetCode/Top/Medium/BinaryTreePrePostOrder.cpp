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
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/*
       i    L+1
    [1,2,4,5,3,6,7]
    
    L = 3
    
    [4,5,2,6,7,3,1]
*/

class Solution {
private:
    unordered_map<int,int> index;
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        if (pre.size() == 0 || post.size() == 0)
            return nullptr;
        
        for (int i=0;i<post.size();i++)
            index[post[i]] = i;
    
        return rec(pre,0,pre.size()-1,post,0,post.size()-1);    
    }
    
    TreeNode* rec(vector<int>& pre, int pre_start, int pre_end, vector<int>& post, int post_start, int post_end){
        if (pre_start > pre_end || post_start > post_end)
            return nullptr;
        
        if (pre_start == pre_end)
            return new TreeNode(pre[pre_start]);
        
        TreeNode* root = new TreeNode(pre[pre_start]);
        int L = index[pre[pre_start+1]] - post_start + 1;
        
        root->left = rec(pre,pre_start+1,pre_start+L,post,post_start,post_start+L-1);
        root->right = rec(pre,pre_start+L+1,pre_end,post,post_start+L,post_end-1);
        
        return root;
    }
};
// Time: O(n)
// Spaece: O(n)

int main(){
    vector<int> pre = {1,2,4,5,3,6,7};
    vector<int> post = {4,5,2,6,7,3,1};

    Solution sol;
    TreeNode *root = sol.constructFromPrePost(pre,post);

    return 0;
}
