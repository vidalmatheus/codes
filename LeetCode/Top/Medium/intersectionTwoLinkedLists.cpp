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
    ListNode *next;
    ListNode (int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;
        ListNode *pA = headA;
        ListNode *pB = headB;
        if (pA == pB) return pA;
        unordered_map<ListNode *, int> hash_map;
        while (pA != nullptr || pB != nullptr) {
            if (pA != nullptr && hash_map.find(pA) == hash_map.end()) hash_map[pA] = 0;
            if (pA != nullptr) hash_map[pA]++;

            if (pB != nullptr && hash_map.find(pB) == hash_map.end()) hash_map[pB] = 0;
            if (pB != nullptr) hash_map[pB]++;

            if (hash_map[pA] == 2) return pA;
            if (hash_map[pB] == 2) return pB;

            if (pA != nullptr) pA = pA->next;
            if (pB != nullptr) pB = pB->next;
        }

        return nullptr;      
    }
};
// Time: O(n)
// Space: O(n)

int main() {
    ListNode *headA = new ListNode(4);
    ListNode *headB = new ListNode(5);
    ListNode *pA = headA;
    ListNode *pB = headB;

    pA->next = new ListNode(1);
    pB->next = new ListNode(0);
    pA = pA->next;
    pB = pB->next;

    pA->next = new ListNode(8);
    pB->next = new ListNode(1);
    pA = pA->next;
    pB = pB->next;

    pB->next = pA;
    pA->next = new ListNode(4);
    pA = pA->next;
    pB = pB->next;

    pB->next = new ListNode(4);
    pA->next = new ListNode(5);
    pA = pA->next;
    pB = pB->next;

    pB->next = new ListNode(5);
    pB = pB->next;

    pA=headA;
    pB=headB;
    while (pA!=nullptr) {
        if (pA!=nullptr) cout << pA->val << " ";

        pA = pA->next;
    }
    cout << endl;
    while (pB!=nullptr) {
        if (pB!=nullptr) cout << pB->val << " ";

        pB = pB->next;
    }
    cout << "\n\n";

    Solution sol;
    ListNode *ans = sol.getIntersectionNode(headA, headB);

    string text = (ans == nullptr) ? "NULL\n" : to_string(ans->val); 
    cout << text << endl;

    return 0;
}