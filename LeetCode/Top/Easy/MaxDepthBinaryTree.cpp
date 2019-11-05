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
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* class Solution {
public:
    int maxDepth(TreeNode* root) {
        int max_depth=0;
        post_order(root,max_depth);
        return max_depth;
    }
    void post_order(TreeNode* root,int& max_depth,int depth=0){
        if (root==nullptr){
            if (depth>max_depth)
                max_depth=depth;
        }
        else {
            depth++;
            post_order (root->left,max_depth,depth);
            post_order (root->right,max_depth,depth);
        } 
    }
}; */

class Solution { // clean and beauty solution (recursion itself) --> Think all in one recursion!!!
public:
    int maxDepth(TreeNode* root) {
        int max_depth = 0;
        if(root!=nullptr){
            max_depth = (max(maxDepth(root->left)+1,maxDepth(root->right)+1));
        }
        return max_depth;
    }
};

int main(){

    //[3,9,20,null,null,15,7]
    /*   
        3
       / \
       9  20
         /  \
        15   7 
    */
    
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7); 

/*     TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2); */

    Solution sol;
    int max_depth=0;
    cout << " Max_Depth: " << sol.maxDepth(root) << endl;

    return 0;
}