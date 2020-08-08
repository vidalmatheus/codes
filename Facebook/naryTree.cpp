#include <bits/stdc++.h>

using namespace std;

/*

node1(node2,node3(node4,node5,node6),node7,node8(node9(node10)))

*/

struct Node {
    string val;
    vector<Node*> children;
    Node (string x) : val(x) {}
};

Node* build(string& s){
    if (s.size() == 0)
        return nullptr;
    
    stack<Node*> st;
    string word = "";
    Node* root;
    for(char c : s){
        if (c != ',' && c != '(' && c != ')'){
            word.push_back(c);
        }
        else if (c == '('){
            Node * node = new Node(word);
            if (!st.empty())
                st.top()->children.push_back(node);
            
            st.push(node);
            word = "";
        }
        else if (c == ',' || c == ')'){
            if (word.size() != 0){
                Node * node = new Node(word);
                st.top()->children.push_back(node);
                word = "";
            }

            if (c == ')' && !st.empty()){
                root = st.top();
                st.pop();
            }
        }
    }

    return root;
}
// Time: O(n)
// Space: O(n)

void levelOrder(Node* root) {
    if (root == nullptr)
        return;

    queue<Node*> q;
    q.push(root);
    while (!q.empty()){
        int size = q.size();
        for (int i=0;i<size;i++){
            Node* node = q.front();
            q.pop();
            cout << node->val << " ";
            
            for (Node* neighbor : node->children)
                if (neighbor != nullptr)
                    q.push(neighbor);
        }
        cout << endl;
    }
}
// Time: O(n)
// Space: O(n)

string preOrder(Node* root){
    if (root == nullptr)
        return "";
    
    stack<Node*> s;
    stack<int> children;
    s.push(root);
    children.push(root->children.size()); // to track the closing parentheses
    string ans = "";
    int open = 0;
    while (!s.empty()){
        Node* node = s.top();
        s.pop();
        ans.append(node->val);
        children.top()--;

        int amount_of_children = node->children.size();
        // if we've used all children and the current node doesn't have any children
        if (children.top() == 0 && amount_of_children == 0){ 
            ans.push_back(')');
            open--;
            children.pop();
        }

        if (amount_of_children > 0){ // we need to update the new amount of children just once
            children.push(amount_of_children);
            ans.push_back('(');
            open++;
            for (int i=amount_of_children-1;i>=0;--i){
                Node* child = node->children[i];
                s.push(child);       
            }
        }

        if (ans.back() != '(')  // if it's not a parent, add comma
            ans.push_back(',');
    }
    ans.pop_back();

    for (int i=0;i<open;i++)
        ans.push_back(')');

   return ans;
}
// Time: O(n)
// Space: O(n)

int main(){
    string s = "node1(node2,node3(node4,node5,node6),node7,node8(node9(node10)))";
    Node* root = build(s);
    
    cout << "Level Order: " << endl;
    levelOrder(root);
    
    cout << "Original : " << s << endl;
    cout << "Pre Order: ";
    string ans = preOrder(root);
    cout << ans << endl;

    assert(s == ans);
    cout << "Passed!";
    return 0;
}
