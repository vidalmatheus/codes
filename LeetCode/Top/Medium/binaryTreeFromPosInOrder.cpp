#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode (int x) : val(x), left(nullptr), right(nullptr) {};
};
static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) { // O(nlogn)
        if (postorder.size()==0 || inorder.size()==0)
            return nullptr;

        return build(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1);
    }

    TreeNode* build(vector<int> &postorder,int startPostorder,int endPostorder,vector<int> &inorder,int startInorder,int endInorder){ // O(n^2)
        if (startInorder > endInorder)
            return nullptr;

        TreeNode *root = new TreeNode(postorder[endPostorder]); // build root
        int posRoot = -1;

        for (int i=startInorder;i<=endInorder;i++){
            if (inorder[i]==root->val){
                posRoot = i;
                break;
            }
        }
        // posRoot-startInorder: # elements of left subtree
        root->left = build(postorder,startPostorder,startPostorder+(posRoot-startInorder)-1,inorder,startInorder,posRoot-1); // left subtree
        root->right = build(postorder,startPostorder+(posRoot-startInorder),endPostorder-1,inorder,posRoot+1,endInorder); // right subtree
        return root;
    }
};

class SolutionHash { // O(n)
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size()==0 || inorder.size()==0)
            return nullptr;

        unordered_map<int,int> m;
        for (int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }

        return build(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,m);
    }

    TreeNode* build(vector<int> &postorder,int startPostorder,int endPostorder,vector<int> &inorder,int startInorder,int endInorder,unordered_map<int,int>& m){
        if (startInorder > endInorder)
            return nullptr;

        TreeNode *root = new TreeNode(postorder[endPostorder]); // build root
        int posRoot = m[postorder[endPostorder]];
        root->left = build(postorder,startPostorder,startPostorder+(posRoot-startInorder)-1,inorder,startInorder,posRoot-1,m); // left subtree
        root->right = build(postorder,startPostorder+(posRoot-startInorder),endPostorder-1,inorder,posRoot+1,endInorder,m); // right subtree
        return root;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
static int speedUp=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/*
        3
      /   \
     9

           0 1  2  3 4
inorder = [9,3,15,20,7] -> L V R
             i

             0  1 2  3 4
postorder = [9,15,7,20,3] -> L R V
                       j    

rec(0,4,0,4):
    rec(0,0,0,0):
        rec(0,-1,,): null
    
    rec(2,4,1,3): ...

*/

class ReviewSolution { // same as the previous solution, just redoing the problem
private:
    unordered_map<int,int> indexInorder;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0)
            return nullptr;
        
        for (int i=0;i<inorder.size();i++)
            indexInorder[inorder[i]] = i;
        
        return rec(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
    
    TreeNode* rec(vector<int>& inorder, int startInorder, int endInorder, vector<int>& postorder, int startPostorder, int endPostorder){
        if (startInorder > endInorder || startPostorder > endPostorder)
            return nullptr;
        
        TreeNode* node = new TreeNode(postorder[endPostorder]);
        int index = indexInorder[postorder[endPostorder]];
        
        int amount_left = index-startInorder;
        
        node->left = rec(inorder,startInorder,index-1,postorder,startPostorder,startPostorder+amount_left-1);
        node->right = rec(inorder,index+1,endInorder,postorder,startPostorder+amount_left,endPostorder-1);
        
        return node;
    }
};
// Time: O(n)
// Space: O(n)


void postOrder (TreeNode *root){
    if (root==nullptr)
        return ;
    stack<TreeNode*> s;
    stack<int> se;
    s.push(root);
    while(!s.empty()){
        TreeNode *node = s.top();
        se.push(node->val);
        s.pop();
        if (node->left!=nullptr) s.push(node->right);
        if (node->right!=nullptr) s.push(node->left);
    }
    while (!se.empty()){
        cout << se.top() << " ";
        se.pop();
    }
}

int main() {

    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};

    SolutionHash sol;
    TreeNode *root = sol.buildTree(inorder,postorder);

    postOrder(root);

    return 0;
}
