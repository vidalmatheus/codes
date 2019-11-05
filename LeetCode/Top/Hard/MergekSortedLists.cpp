#include <bits/stdc++.h>

using namespace std;

static auto speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {} // like a constructor with member initialization list
};
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* Head = nullptr;
        if (lists.size()==0) return nullptr;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> minHeap;      // to store min current values from k sorted lists, also stores from its lists each element was added
        for (int k=0;k<lists.size();k++){           // putting first values in minHeap    
            if (lists[k]!=nullptr) minHeap.push(make_pair(lists[k]->val,k));
        }
        if (minHeap.empty()) return nullptr;
        Head = lists[minHeap.top().second];         // set the head to the first min value
        while (!minHeap.empty()){
            // sort pointers
            int i = minHeap.top().second;           // store each list is gonna be advanced
            minHeap.pop();
            ListNode *p = lists[i];
            lists[i]=lists[i]->next;
            if (lists[i]!=nullptr)
                minHeap.push(make_pair(lists[i]->val,i));
            if (!minHeap.empty()){
                int j = minHeap.top().second;
                p->next = lists[j];
            }

        }
        return Head;
    }
};
// TIME: O(n*log(k))
// SPACE: O(log(k))


int main(){
    vector<ListNode*> lists;
/*     lists[0] = new ListNode(1);
    lists[0]->next = new ListNode(4);
    lists[0]->next->next = new ListNode(5);
    
    lists[1] = new ListNode(1);
    lists[1]->next = new ListNode(3);
    lists[1]->next->next = new ListNode(4);

    lists[2] = new ListNode(2);
    lists[2]->next = new ListNode(6); */

    Solution sol;
    ListNode* H = sol.mergeKLists(lists);

    ListNode * p = H;
    while (p!=nullptr){
        cout << p->val << " ";
        p=p->next;
    }
/*     delete lists[0];
    delete lists[1];
    delete lists[2]; */
    return 0;
}