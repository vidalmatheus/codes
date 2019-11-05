#include <bits/stdc++.h>

using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};
 

static auto speedUp(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1==nullptr) return l2;
        if (l2==nullptr) return l1;
        ListNode *head;
        if (l1->val<l2->val){
            head=l1;
            l1=l1->next;
        }
        else {
            head=l2;
            l2=l2->next;
        }
        ListNode *p=head;
        while(l1!=nullptr && l2!=nullptr){
            if (l1->val<l2->val){
                p->next=l1;
                p=p->next;
                l1=l1->next;
            }            
            else {
                p->next=l2;
                p=p->next;
                l2=l2->next;
            }
        }
        if (l1==nullptr){
            // go through l2
            p->next=l2;
        }
        else { // l2==nullptr
            p->next=l1;
        }
        return head;
    }
    
};
// Time: O(n1+n2)
// Space: O(1)