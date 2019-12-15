#include <bits/stdc++.h>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1==nullptr)
            return l2;
        if (l2==nullptr)
            return l1;
        ListNode *p = l1;
        ListNode *q = l2;
        ListNode *l3 = new ListNode(0);
        ListNode *r = l3;
        int carry = 0;
        while(p!=nullptr && q!=nullptr){ 
            int sum = p->val + q->val + carry;
            if (carry == 1)
                carry = 0;
            if (sum >= 10){
                sum = sum - 10 + carry;
                carry = 1;
            }
            r->val = sum;
            p = p->next;
            q = q->next;
            if (p!=nullptr && q!=nullptr){
                r->next = new ListNode(carry);
                r = r->next;
            }
        }
        if (p==nullptr && q==nullptr && carry==1)
            r->next = new ListNode(carry);
        if (p!=nullptr && q==nullptr){
            p->val = p->val + carry;
            r->next = p;
        }
        if (p==nullptr && q!=nullptr){
            q->val = q->val + carry;
            r->next = q;
        }
        return l3;
    }
};
// Time: O(n+m)
// Space: O(n+m)

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummyHead = new ListNode(0);
        ListNode *p = l1;
        ListNode *q = l2;
        ListNode *curr = dummyHead;
        int carry = 0;
        while (p!=nullptr || q!=nullptr){
            int x = (p!=nullptr) ? p->val : 0;
            int y = (q!=nullptr) ? q->val : 0;
            int sum = carry + x + y;
            carry = sum/10;
            curr->next = new ListNode(sum%10);
            curr = curr->next;
            if (p!=nullptr) p = p->next;
            if (q!=nullptr) q = q->next;
        }
        if (carry>0)
            curr->next = new ListNode(carry);
        return dummyHead->next;
    }
};
// Time: O(n+m)
// Space: O(n+m)

int main(){
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    
    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode *l3 = new ListNode(5);
    ListNode *l4 = new ListNode(5); 

    ListNode *l5 = new ListNode(9);
    l5->next = new ListNode(8); 
    ListNode *l6 = new ListNode(1);

    ListNode *l7 = new ListNode(1);
    l7->next = new ListNode(8); 
    ListNode *l8 = new ListNode(0);

    Solution sol;
    ListNode *lr = sol.addTwoNumbers(l7,l8);

    cout << lr->val;
    for (ListNode *p=lr->next;p!=nullptr;p=p->next){
        cout << " -> " << p->val;
    }

    return 0;
}