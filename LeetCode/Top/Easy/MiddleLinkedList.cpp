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
    ListNode* middleNode(ListNode* head) {
        if (head==nullptr)
            return head;
        
        int n = 0;
        for (ListNode* p=head;p!=nullptr;p=p->next){
            n++;
        }
        
        ListNode* ans;
        int pos = 0;
        for (ListNode* p=head;p!=nullptr;p=p->next){
            pos++;
            if (pos == n/2+1)
                ans = p;
        }
        
        return ans;
    }
};
// Time: O(n)
// Space: O(1)

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    ListNode* ans = sol.middleNode(head);

    for (ListNode* p=ans;p!=nullptr;p=p->next)
        cout << p->val << " ";

    return 0;
}
