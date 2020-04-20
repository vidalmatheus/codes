#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
  
static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/*
 p  c  n
 1<-2  3->4
    h
*/

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = head->next->next;
        ListNode* end = prev;
        head = head->next;
        
        while (prev!=nullptr && curr!=nullptr){
            end->next = curr;
            prev->next = next;
            curr->next = prev;
            
            end = prev;
            prev = next;
            if (prev!=nullptr) 
                curr = prev->next;
            if (curr!=nullptr) 
                next = curr->next;
            else next = nullptr;
        }
        
        return head;
    }
};
// Time: O(n)
// Space: O(1)

int main(){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    Solution sol;
    head = sol.swapPairs(head);

    for (ListNode* p=head;p!=nullptr;p=p->next)
        cout << p->val << " ";

    return 0;
}
