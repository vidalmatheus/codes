#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
    Node(int x) : val(x), prev(nullptr), next(nullptr), child(nullptr) {}
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr)
            return nullptr;
        
        for (Node* p=head;p!=nullptr;p=p->next){
            if (p->child != nullptr){
                Node* next = p->next;
                Node* below = flatten(p->child);
                p->next = below;
                below->prev = p;
                p->child = nullptr;
                
                while (below->next != nullptr)
                    below = below->next;
                
                if (next != nullptr) next->prev = below;
                below->next = next;
            }
        }
        
        return head;
    }
};
// Time: O(n)
// Space: O(n)

int main(){
    /*
    1---2---NULL
    |
    3---NULL
    */

    Node* head = new Node(1);
    head->next = new Node(2);
    head->child = new Node(3);
    
    Solution sol;
    Node* ans = sol.flatten(head);

    for (Node* p=ans;p!=nullptr;p=p->next)
        cout << p->val << " ";
    cout << endl;

    return 0;
}
