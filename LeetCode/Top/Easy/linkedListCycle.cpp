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
 
/* class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head==nullptr) return false;
        if (head->next==nullptr) return false;
        unordered_set<ListNode*> uset;
        ListNode *p=head;
        do{
            if (uset.find(p)==uset.end()){ // if isn't a previous node, then continue
                uset.insert(p);
                p = p->next;
            }
            else return true; // if it's already an prevous node, then return true
        }while (p!=nullptr);
        return false;
    }
};
// Time: O(n)
// Space: O(n) */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head==nullptr) return false;
        if (head->next==nullptr) return false;
        ListNode *s,*f; // slow and fast pointers
        s = head;
        f = head->next;
        while(f->next!=nullptr){
            s=s->next;
            f=f->next->next;
            if (f==nullptr) return false;
            if (f==s || f==s->next) return true;
        }
        return false;
    }
};
// Time: O(n)
// Space: O(1)

int main(){

    return 0;
}