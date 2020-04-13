#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root==nullptr)
            return "X,";
        
        string leftSerialize = serialize(root->left);
        string rightSerialize = serialize(root->right);

        string curr = to_string(root->val);
        return curr+','+leftSerialize+rightSerialize;
    }
    // Time: O(n)
    // Space: O(n)


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) { // Time: O(n) & Space: O(n)
        queue<string> q;
        string str = "";
        for (int i=0;i<data.size();i++){
            if (data[i]!=','){
                str+=data[i];
            }
            else {
                q.push(str);
                str = "";
            }

        }

        return rec(q);
    }

    TreeNode* rec(queue<string>& q){
        string s = q.front();
        q.pop();
        if (s=="X")
            return nullptr;
    
        TreeNode* node = new TreeNode(stoi(s));
        
        node->left = rec(q);
        node->right = rec(q);

        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(9);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(10);

    Codec codec;
    string str = codec.serialize(root);
    cout << str << endl;
    TreeNode* ans = codec.deserialize(str);
    cout << codec.serialize(ans) << endl;

    return 0;
}
