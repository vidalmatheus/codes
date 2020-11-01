#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

static int speedUp=[](){
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        if (head == nullptr)
            return 0;

        head = reverseList(head);
        return getDec(head);
    }

    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = head->next;
        while (curr != nullptr){
            curr->next = prev;
            prev = curr;
            curr = next;
            if (next != nullptr) next = next->next;
        }

        return prev;
    }

    int getDec(ListNode* head){
        int ans = 0;
        int exp = 0;
        for (ListNode* p=head; p!=nullptr; p=p->next)
            ans += p->val*(1 << exp++);
        return ans;
    }
};
// Time: O(n)
// Space: O(1)

int main(){
    Solution sol;

    vector<int> bin{1,0,0,1,0,0,1,1,1,0,0,0,0,0,0};
    ListNode* head = new  ListNode();
    for (const int & i : bin)
        head->next = new ListNode(i);

    assert(sol.getDecimalValue(head->next) == 18880);
    cout << "Passed!" << endl;
    return 0;
}

