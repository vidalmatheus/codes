#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
static int speedUp=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == nullptr)
            return nullptr;
        
        ListNode* prev = nullptr;
        ListNode* first = head;
        ListNode* last = head;
        for (int i=1;i<=n;i++){
            if (i < m){
                prev = first;
                first = first ? first->next : nullptr;
            }
            if (i < n){
                last = last->next;
            }
        }
        
        first = reverseList(first,last->next);
        
        if (prev) {
            prev->next = first;
            return head;
        }
        else return first;
    }
        
//      a  l     f 
//      5<-2<-3<-4 
//               ^
//               |
//               1 <- head
//              prev
        
    ListNode* reverseList(ListNode* first, ListNode* afterLast) {
        ListNode *prev,*curr,*next;
        prev=afterLast;
        curr=first;
        while(curr!=afterLast){
            next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
};
// Time: O(n)
// Space: O(1)

ListNode* buildList(vector<int> v){
    if (v.size() == 0)
        return nullptr;
    ListNode* head = new ListNode(v[0]);
    ListNode* p = head;
    for (int i=1;i<v.size();i++){
        p->next = new ListNode(v[i]);
        p=p->next;
    }
    return head;
}


int main(){
    Solution sol;
    
    ListNode* head =  buildList({1,2,3,4,5});
    head = sol.reverseBetween(head,2,4);
    vector<int> ans = {1,4,3,2,5};
    vector<int> exp;
    for (ListNode*p=head;p!=nullptr;p=p->next)
        exp.push_back(p->val);
    assert(exp == ans);


    head =  buildList({1,2});
    head = sol.reverseBetween(head,1,2);
    ans = {2,1};
    exp.clear();
    for (ListNode*p=head;p!=nullptr;p=p->next)
        exp.push_back(p->val);
    assert(exp == ans);

    cout << "Passed!" << endl;
    return 0;
}