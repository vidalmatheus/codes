# include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr) {}
};

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        ListNode *odd, *even; 
        
        odd = head;
        even = head->next;

        ListNode *evenHead = even;

        while (odd->next!=nullptr && even->next!=nullptr) {
            odd->next=even->next;
            odd=odd->next;
            even->next=odd->next;
            even=even->next;
        }

        odd->next=evenHead;
        
        return head;
    }
};

int main() {

    ListNode *head = new ListNode(1);
    ListNode *p;
    
    p = head;
    for (int i=2;i<=5;i++){
        p->next = new ListNode(i);
        p=p->next;
    }

    for (p=head->next;p!=nullptr;p=p->next){
        cout << p->val << "->";
    }
    cout << "null\n";


    Solution sol;

    ListNode *ans = sol.oddEvenList(head);

    for (p=ans;p!=nullptr;p=p->next){
        cout << p->val << "->";
    }
    cout << "null\n";

    return 0;
}