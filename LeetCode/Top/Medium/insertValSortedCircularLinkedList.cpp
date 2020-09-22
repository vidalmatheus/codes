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
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (head == nullptr){
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        
        if (head->next == head){
            head->next = new Node(insertVal);
            head->next->next = head;
            return head;
        }

            
        // find the beginning of the sorted list
        Node* cur = head;
        Node* next = head->next;
        while (cur->val <= next->val && next != head){
            cur = next;
            next = next->next;
        }
        
        Node* begin = next;
        
        // find the location where to put the insertVal
        cur = begin;
        next = cur->next;
        while ( !(insertVal <= next->val && cur->val <= insertVal) && next != begin){
            cur = next;
            next = next->next;
        }
        
        cur->next = new Node(insertVal);
        cur = cur->next;
        cur->next = next;
        
        return head;        
    }
};
// Time: O(n)
// Space: O(1)

class BestSolution {
public:
    Node* insert(Node* head, int insertVal) {
        if (head == nullptr){
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        
        if (head->next == head){
            head->next = new Node(insertVal);
            head->next->next = head;
            return head;
        }

        Node* curr = head;
        while (true){
            // easy-to-see case
            if (curr->val <= insertVal && insertVal <= curr->next->val)
                break;
            
            // tail element
            if (curr->val > curr->next->val){
                if (curr->val <= insertVal && curr->next->val <= insertVal)
                    break;
                if (insertVal <= curr->val && insertVal <= curr->next->val)
                    break;
            }
            
            curr = curr->next; // move foward
            if (curr == head)
                break;
        }
        
        Node* next = curr->next;
        curr->next = new Node(insertVal);
        curr = curr->next;
        curr->next = next;
        return head;
    }
};
// Time: O(n)
// Space: O(1)

int main(){
    Solution sol;
    
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node1 = new Node(1);

    node3->next = node4;
    node4->next = node1;
    node1->next = node3;

    int val = 2;
    vector<int> expected{3,4,1,2};
    Node* head = sol.insert(node3, val);
    int i = 1;
    assert (head->val == expected[0]);
    for (Node* p=head->next; p!=head; p=p->next)
        assert(p->val == expected[i++]);

    cout << "Passed!" << endl;
    return 0;
}