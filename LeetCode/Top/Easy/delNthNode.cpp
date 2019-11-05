#include <bits/stdc++.h>

using namespace std;

static auto speedUp(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next==nullptr){
            delete head;
            head=nullptr;
            return head;
        }
        ListNode *p=head;
        if (isNode(head,p,n)){
            head=head->next;
            delete p;
            return head;
        }
        while(!isNode(head,p->next,n)){
            p=p->next;
        }
        ListNode *q=p->next;
        p->next=q->next;
        delete q;
        return head;
    }
    
    bool isNode(ListNode *head,ListNode *node, int n){
        int counter=0;
        while(node!=nullptr){
            node=node->next;
            counter++;
            if (counter>n) return false;
        }
        if (counter==n) return true;
        else return false;
    }
};
// Time: O(n*(N-n))
// Space: O(1)