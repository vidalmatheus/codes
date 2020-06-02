#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
In C++, delete operator should only be used either for the pointers pointing to the memory allocated using new operator or for a NULL pointer, 
and free() should only be used either for the pointers pointing to the memory allocated using malloc() or for a NULL pointer.
*/

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode* nextNode = node->next->next;
        delete(node->next);
        node->next = nextNode;
    }
};
// Time: O(1)
// Space: O(1)

int main(){
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    for (ListNode* p=head;p!=nullptr;p=p->next)
        cout << p->val << " ";
    cout << endl;

    Solution sol;
    sol.deleteNode(head->next);

    for (ListNode* p=head;p!=nullptr;p=p->next)
        cout << p->val << " ";
    cout << endl;

    return 0;
}