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
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
                   
//       h     p          q
// null<-1<-2<-3 null<-4<-5

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *prev, *curr, *next;
        prev = nullptr;
        curr = head;
        int counter = 0;
        
        int n = 0;
        for (ListNode* p=head;p!=nullptr;p=p->next)
            n++;
        
        if (n<k)
            return head;
        
        while (curr != nullptr && counter < k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            counter++;
        }
        
        if (curr != nullptr)
            head->next = reverseKGroup(curr,k);        
            
        return prev;
    }
};
// Time: O(n)
// Space: O(n)

int main(){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 3;

    Solution sol;
    ListNode *ans = sol.reverseKGroup(head,k);

    for (ListNode* p=ans;p!=nullptr;p=p->next)
        cout << p->val << " ";
    cout << endl;
    
    return 0;
}
