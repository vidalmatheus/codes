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
    ListNode* reverseList(ListNode* head) { // As the function type is ListNode*, we don't need to pass by reference!!! Important to know!
        if (head==nullptr) return head;
        if (head->next==nullptr) return head;
        ListNode *p,*c,*n;
        p=head;
        c=head->next;
        n=c->next;
        p->next=nullptr;
        while(n!=nullptr){
            c->next=p;
            p=c;
            c=n;
            n=n->next;
        }
        c->next=p;
        head=c;
        return head;
    }
};

/* class Solution {
public:
    void reverseList(ListNode*&head) { // passing by reference (void type function)
        //if (head==nullptr) return head;
        //if (head->next==nullptr) return head;
        ListNode *p,*c,*n;
        p=head;
        c=head->next;
        n=c->next;
        p->next=nullptr;
        while(n!=nullptr){
            c->next=p;
            p=c;
            c=n;
            n=n->next;
        }
        c->next=p;
        head=c;
    }
};
// Time: O(n)
// Space: O(1) */

/* class Solution{ // recursively 
public:
    ListNode* reverseList(ListNode* head){
        if (head==nullptr) return head;
        if (head->next==nullptr) return head;
        ListNode* p=reverseList(head->next); // see the linked list as first node and the rest of nodes
        head->next->next=head;
        head->next=nullptr;
        return p;
    }
};
// Time: O(n)
// Space: O(n) -> the extra space comes from the implicit stack due to recursion. The recursion goes up to n frames or layers deep. */
 

int main(){
    ListNode*L,*p;
    L=new ListNode(0);
    p=L;
    for (int i=1;i<10;i++){
        p->next=new ListNode(i);
        p=p->next;
    }
    for (p=L;p!=nullptr;p=p->next)
        cout << p->val << "->";
    cout << "null" << endl;
    
    Solution sol;
    sol.reverseList(L);
    for (p=L;p!=nullptr;p=p->next)
        cout << p->val << "->";
    cout << "null" << endl;
    return 0;
}