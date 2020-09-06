#include <bits/stdc++.h>

using namespace std;

namespace helper {
    #include "BinaryTreeFromLevelOrder.cpp"
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
    vector<int> getAllElements(helper::TreeNode* root1, helper::TreeNode* root2) {
        if (!root1 && !root2)
            return {};
        
        vector<int> inorder1, inorder2;
        inorder(root1,inorder1);
        inorder(root2,inorder2);
        
        return merge(inorder1,inorder2);
    }
    
    void inorder(helper::TreeNode* root1, vector<int>& dfs){
        if (!root1)
            return;
        
        inorder(root1->left, dfs);
        dfs.push_back(root1->val);
        inorder(root1->right, dfs);    
    }
    
    vector<int> merge(vector<int>& a, vector<int>& b){
        if (a.size() == 0)
            return b;
        
        if (b.size() == 0)
            return a;
        
        int i = 0;
        int j = 0;
        vector<int> ans;
        while (i < a.size() && j < b.size()){
            if (a[i] <= b[j])
                ans.push_back(a[i++]);
            else ans.push_back(b[j++]);
        }
        
        
        while (i < a.size())
            ans.push_back(a[i++]);
        
        while (j < b.size())
            ans.push_back(b[j++]);
        
        
        return ans;
    }    
};
// Time: O(n)
// Space: O(n)

int main(int argc, const char** argv) {
    vector<string> tree1 = {"2","1","4"};
    vector<string> tree2 = {"1","0","3"};

    helper::TreeNode * root1 = (new helper::Solution)->binaryTreeFromLevelOrder(tree1);
    helper::TreeNode * root2 = (new helper::Solution)->binaryTreeFromLevelOrder(tree2);

    vector<int> ans = {0,1,1,2,3,4};
    assert(ans == (new Solution)->getAllElements(root1,root2));
    cout << "Passed!" << endl;
    return 0;
}