#include<bits/stdc++.h>

using namespace std;

static int speedUp=[](){
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

class RecursiveBSTIterator {
private:
    stack<TreeNode*> st; // Space: O(h)
public:
    RecursiveBSTIterator(TreeNode* root) {
        inOrder(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* next = st.top();
        st.pop();
        
        inOrder(next->right);
        
        return (next->val);
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() { // O(1)
        return st.size()>0;
    }
    
    void inOrder(TreeNode* root){ // Time: O(n), when the tree is not balanced and O(h) when it is
        while (root!=nullptr){
            st.push(root);
            root = root->left;
        }
    }
};

class BSTIterator {
private:
    vector<TreeNode*> sortedElements; 
    int index;
public:
    BSTIterator(TreeNode* root) {
        index = 0;
        inOrder(root);
    }
    
    /** @return the next smallest number */
    int next() { // O(1)
        return sortedElements[index++]->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() { // O(1)
        return index<sortedElements.size();
    }
    
    void inOrder(TreeNode* root){ // Time: O(n) & Space: O(h)
        if (root==nullptr)
            return;
        inOrder(root->left);
        sortedElements.push_back(root);
        inOrder(root->right);
    }
};


int main(){
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator* obj = new BSTIterator(root);
    cout << obj->next() << endl;
    cout << obj->next() << endl;
    obj->hasNext() ? cout << "true\n" : cout << "false\n";
    cout << obj->next() << endl;
    obj->hasNext() ? cout << "true\n" : cout << "false\n";
    cout << obj->next() << endl;
    obj->hasNext() ? cout << "true\n" : cout << "false\n";
    cout << obj->next() << endl;
    obj->hasNext() ? cout << "true\n" : cout << "false\n";
    
    return 0;
}
