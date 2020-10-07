#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

auto speedup=[](){
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr)
            return nullptr;
        
        int n = 1;
        ListNode* last = head;
        while (last->next != nullptr){
            last = last->next;
            n++;
        }
        
        int m = n-k;
        // push back n-k first elements
        while (m % n != 0){
            last->next = head;
            head = head->next;
            last->next->next = nullptr;
            last = last->next;
            m--;
        }
    
        return head;
    }
};
// Time: O(n)
// Space: O(1)

int main(){
    Solution sol;

    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    int k = 2;
    ListNode* ans = sol.rotateRight(node1,k);
    vector<int> expected{4,5,1,2,3};
    int i = 0;
    for (ListNode* p=ans;p;p=p->next)
        assert(p->val = expected[i++]);

    cout << "Passed!" << endl;
    return 0;
}