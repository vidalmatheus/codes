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
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        // let's use the fact that all values are unique
        node->val=node->next->val;
        ListNode *p=node->next;
        node->next=p->next;
        delete p;
    }
};
// Time: O(1)
// Space: O(1)