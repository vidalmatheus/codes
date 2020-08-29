#include <bits/stdc++.h>

using namespace std;

struct Node {
    string val;
    vector<Node*> children;
    Node (string x) : val(x) {}
};

void rec(string& s, Node* parent, int &i) {
    while(s[i] != ')') {
        if(s[i] == ',') i ++;
        string nodeval = "";
        while(s[i] != ',' && s[i] != '(' && s[i] != ')') { 
            nodeval += s[i ++]; 
        }
        Node* node = new Node(nodeval);
        parent->children.push_back(node);
        if(s[i] == ',') i ++;
        else if(s[i] == '(') rec(s, node, ++i);
    }
    i + 1;
}


Node* constructTree(string s) {
    int i = 0;
    string rootval = "";
    while(i < s.size() && s[i] != '(') rootval += s[i ++];
    Node* root = new Node(rootval);
    if(i == s.size()) return root;
    rec(s, root, ++i);
    return root;
}