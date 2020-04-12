#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head==nullptr)
            return head;
        
        if (head->next==nullptr)
            return nullptr;
        
        ListNode* slow = head;
        ListNode* fast = head;
        do{
            slow=slow->next;
            if (fast->next==nullptr || fast->next->next==nullptr)
                return nullptr;
            fast=fast->next->next;
        }while (slow!=fast);
        
        ListNode* p = head;
        while (p!=slow){
            p=p->next;
            slow=slow->next;
        }
        
        return p;
    }
};
// Time: O(n)
// Space: O(1)

int main(){
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(4);
    
    head->next->next->next->next = head->next;

    Solution sol;
    cout << sol.detectCycle(head)->val << endl;

    return 0;
}

    