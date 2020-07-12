#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
         1
          #
         / \
     2  #   #  3
       /     \  
   4  #       #  7
     /         \
 8  #           #  14

1. do a BFS tagging nodes just like we do when we want to match positions between a vector and a heap
 1.1 for each level calculate the current width by: rightmost_tag - leftmost_tag + 1
 1.2 update the max_width
2. return max_width

Time: O(n), since we have traversed the nodes only once
Space: O(M), since we have stored at maximum M nodes on the queue, 
where M is the number of nodes on the current level

*/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
            return 0;
                
        queue<pair<TreeNode*,long int>> q;
        q.push({root,1});
        int max_width = 0;
        int leftmost_tag = 1;
        int rightmost_tag = 1;
        while (!q.empty()){
            int size = q.size();
            for (int i=0;i<size;i++){ // level
                if (i == 0)
                    leftmost_tag = q.front().second;
                if (i == size-1)
                    rightmost_tag = q.front().second;
                
                int pos = q.front().second;
                TreeNode* node = q.front().first;
                q.pop();
                if (node->left) q.push({node->left,2*pos});
                if (node->right) q.push({node->right,(long int)2*pos+1});
            }
            max_width = max(max_width,rightmost_tag - leftmost_tag + 1);
        }
        
        return max_width;
    }
};
// Time: O(n)
// Space: O(M)

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);

    root->right = new TreeNode(2);
    root->right->right = new TreeNode(9);

    Solution sol;
    cout << sol.widthOfBinaryTree(root) << endl;

    return 0;
}
