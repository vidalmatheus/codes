#include <bits/stdc++.h>

using namespace std;

/*

node1(node2,node3(node4,node5,node6))

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
        else if (c == ','){
            Node * node = new Node(word);
            st.top()->children.push_back(node);
            word = "";
        }
        else if (c == ')'){
            if (word.size () != 0){
                Node * node = new Node(word);
                st.top()->children.push_back(node);
                word = "";
            }

            if (!st.empty()){
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


int main(){
    string s = "node1(node2,node3(node4,node5,node6))";

    Node* root = build(s);
    
    cout << "Level Order: " << endl;
    levelOrder(root);

    return 0;
}
