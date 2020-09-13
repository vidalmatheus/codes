#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
static int speedUp=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        
        // find the middle
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prevSlow = head;
        while (fast && fast->next){
            prevSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prevSlow->next = nullptr;
    
        return mergeSortedList(sortList(head), sortList(slow));
    }
    
    ListNode* mergeSortedList(ListNode* A, ListNode* B){
        ListNode* dummy = new ListNode(0); // dummy node;
        ListNode* curr = dummy; 
        while (A && B){
            if (A->val < B->val){
                curr->next = new ListNode(A->val);
                A = A->next;
            }
            else {
                curr->next = new ListNode(B->val);
                B = B->next;
            }
            curr = curr->next;
        }
        
        if (A) curr->next = A;
        else if (B) curr->next = B;
        
        return dummy->next;
    }
};
// Time: O(nlog n)
// Space: O(log n)

ListNode* buildList(vector<int>& v){
    if (v.size() == 0)
        return nullptr;
    ListNode* head = new ListNode(v[0]);
    ListNode* p = head;
    for (int i=1;i<v.size();i++){
        p->next = new ListNode(v[i]);
        p = p->next;
    }
    return head;
}

int main(){
    Solution sol;
    
    vector<int> v{4,2,1,3};
    ListNode* head = buildList(v);

    ListNode* ans = sol.sortList(head);

    vector<int> out{1,2,3,4};
    int i = 0;
    for (ListNode* p=head;p!=nullptr;p=p->next)
        assert (out[i] != p->val);
        
    cout << "Passed!" << endl;
    return 0;
}