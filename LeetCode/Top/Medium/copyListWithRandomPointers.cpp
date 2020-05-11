#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
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
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head==nullptr)
            return nullptr;
        
        unordered_map<Node*,Node*> nodeMap;
        
        nodeMap[head] = new Node(head->val);
        for (Node* prev=head, *curr=head->next;curr!=nullptr;curr=curr->next,prev=prev->next){
            nodeMap[curr] = new Node(curr->val);
            nodeMap[prev]->next = nodeMap[curr];
        }
        
        for (Node* p=head;p!=nullptr;p=p->next){
            nodeMap[p]->random = nodeMap[p->random];
        }
        
        return nodeMap[head];
    }
};
// Time: O(n)
// Space: O(1), no extra space

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head==nullptr)
            return nullptr;
        
        // first pass: create a copy
        for (Node* curr=head;curr!=nullptr;curr=curr->next->next){
            Node * nextCurr = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = nextCurr;
        }
        
        // set the new head
        Node *copyHead = head->next;
        
        // set the random pointes
        for (Node* curr=head;curr!=nullptr;curr=curr->next->next){
            curr->next->random = curr->random ? curr->random->next : nullptr;
        }
        
        // set the next pointes
        for (Node* p=head,*q=copyHead;p!=nullptr;p=p->next,q=q->next){
            p->next = p->next->next;
            q->next = q->next ? q->next->next : nullptr;
        }
        
        return copyHead;
    }
};
// Time: O(n)
// Space: O(1), in place

int main(){
    Node *head = new Node(1);
    head->next = new Node(2);
    head->random = new Node(2);
    head->next->random = head->next;

    Solution sol;
    Node * ans = sol.copyRandomList(head);

    return 0;
}
