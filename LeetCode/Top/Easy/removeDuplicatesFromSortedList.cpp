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
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return head;
        
        for (ListNode* p=head;p!=nullptr;p=p->next){
            while (p->next!=nullptr && p->next->val == p->val)
                p->next = p->next->next;
        }
        
        return head;
    }
};
// Time: O(n)
// Space: O(1)

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);

    Solution sol;
    ListNode* ans = sol.deleteDuplicates(head);

    for (ListNode* p=head;p!=nullptr;p=p->next)
        cout << p->val << " ";
    cout << "\n";

    return 0;
}