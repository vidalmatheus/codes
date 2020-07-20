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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr)
            return nullptr;
        
        // case it starts with the value to be erased
        while (head && head->val == val){
            ListNode* to_erase = head;
            head = to_erase->next;
            delete(to_erase);  
        }
         
        // erase the values in the middle 
        for (ListNode* p=head;p!=nullptr;p=p->next){
            while (p->next != nullptr && p->next->val == val){
                ListNode* to_erase = p->next;
                p->next = to_erase->next;
                delete(to_erase);
            }
        }
        
        return head;
    }
};
// Time: O(n)
// Space: O(1)

class AnotherSolution { // this solution uses the same idea of the following problems: remove element and remove duplicates (vector)
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr)
            return nullptr;
        
        ListNode* prev = nullptr;
        ListNode* q = head;
        for (ListNode*p = head;p!=nullptr;p=p->next){
            if (p->val != val){
                q->val = p->val;
                prev = q;
                q = q->next;
            }
        }
        
        if (prev) prev->next = nullptr;
            
        bool null_ans = false;
        if (q == head)
            null_ans = true; 
        
        while (q){
            ListNode* to_erase = q;
            q = q->next;
            delete(to_erase);
        }
        
        return null_ans ? nullptr : head;
    }
};
// Time: O(n)
// Space: O(1)


int main(){
    vector<int> nums{1,2,6,3,4,5,6};
    int val = 6;

    ListNode* head = new ListNode(1);
    ListNode* p = head;
    for (int i=1;i<nums.size();i++){ 
        p->next = new ListNode(nums[i]);
        p = p->next;
    }

    Solution sol;
    ListNode* ans = sol.removeElements(head,val);

    for (p=head;p!=nullptr;p=p->next)
        cout << p->val << " ";
    cout << endl;

    return 0;
}
