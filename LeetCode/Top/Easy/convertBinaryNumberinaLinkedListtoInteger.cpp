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
    int getDecimalValue(ListNode* head) {
        if (head == nullptr)
            return {};
        
        string num = "";
        for (ListNode* p=head;p!=nullptr;p=p->next)
            num += to_string(p->val);
        
        return stoi(num,nullptr,2);
    }
};
// Time: O(n)
// Space: O(n)

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(0);
    head->next->next = new ListNode(1);

    Solution sol;
    assert(sol.getDecimalValue(head) == 5);

    cout << "Passed!" << endl;
    return 0;
}