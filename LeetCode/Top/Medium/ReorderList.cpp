#include <bits/stdc++.h>

using namespace std;

/*
19:41-20:21

head: 1->2->3->4->5->6
            p  q
      
               
1->6->2->5->3->4

reorder this list
1->6->2->5->3->4


1->2->3->4
p

Brute Force Solution)
  // getFromPos(int pos) --> O(n)
  // go through linked list

newList: 1->6->2-
T(n) = n + n-1 + n-2 + ... n/2 --> O(n^2)
M: O(1)

Faster Solution)

1) what nodes does q pointer go through?
B: 6->5->4

// count how many elements list has: n   O(n), O(1)  ---> THERE'S A FASTER WAY TO DO THIS!!! SLOW AND FAST POINTERS!!!
// grab the nod at pos (n/2+1) : C:4<-5<-6  O(n/2), O(1)
// reverse C to get B  O(n/2), O(1)

2) what nodes does p pointer go though? O(n), O(1_
A: 1->2->3   
   p  t

// next pos of p will pointer to q:  1->6->
// p->next->next = t : 1->6->2
// p=p->next->next
// t=p->next
// q=q->next

Overall:
Time: O(n)
Space: O(1)

*/
static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

struct ListNode{
  int val;
  ListNode* next;
  ListNode (int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    pair<ListNode*,ListNode*> getListAListB(ListNode*node){  
      if (node->next==nullptr)
        return {node,nullptr};
      
      ListNode* A = node;
      ListNode* B = nullptr;
      
      int counter=0;
      for (ListNode* p=node;p!=nullptr;p=p->next)
        counter++;
      
      int pos = 0;
      for (ListNode* p=node;p!=nullptr;p=p->next){
        pos++;      
        if (pos==counter/2){
          B = p->next;
          p->next=nullptr;
          break;
        }
      }
      
      reverseList(B);  
      return {A,B};
    }
    // Time: O(n)
    // Space: O(1)

    void reverseList(ListNode*&node){
        if (node->next==nullptr)
            return;
      
        ListNode* p=nullptr, *q=node, *t=q->next;
        
        while (q!=nullptr){
          q->next=p;  
          p=q; 
          q=t; 
          if (t!=nullptr) 
            t=t->next;
        }
        
        node = p;
    }
    // Time: O(n)
    // Space: O(1)

    void mergeListAListB(ListNode*&a,ListNode*&b){
      ListNode* p=a,*t=a->next,*q=b;

      while(p->next!=nullptr){
        p->next=q;
        q=q->next;
        p->next->next = t;
        if (p->next->next==nullptr)
          p=p->next;
        else p=p->next->next;
        if (t!=nullptr) 
          t=p->next;
      }

      if (q!=nullptr)
        p->next=q;
    }
    // Time: O(n)
    // Space: O(1)

    // 1  2->null
    //      t
    // |/ |/
    // 5  4   3->null
    //    p    q

    void reorderList(ListNode*head){
      pair<ListNode*,ListNode*> res = getListAListB(head);
      ListNode*A = res.first;
      ListNode*B = res.second;
      
      cout << "\nA: ";
      ListNode*p=A;
      while(p!=NULL){
        cout << p->val << " ";
        p=p->next;
      }

      cout << "\nB: ";
      p=B;
      while(p!=NULL){
        cout << p->val << " ";
        p=p->next;
      }

      mergeListAListB(A,B);  
    }
    // Time: O(n)
    // Space: O(1)
};

int main(){
  ListNode*node1 = new ListNode(1);
  ListNode*node2 = new ListNode(2);
  ListNode*node3 = new ListNode(3);
  ListNode*node4 = new ListNode(4);
  ListNode*node5 = new ListNode(5);
  // ListNode*node6 = new ListNode(6);
  node1->next=node2;
  node2->next=node3;
  node3->next=node4;
  node4->next=node5;
  // node5->next=node6;

  cout << "Original List: ";
  ListNode*p=node1;
  while(p!=NULL){
    cout << p->val << " ";
    p=p->next;
  }

  Solution sol;
  sol.reorderList(node1);

  cout << "\nReorder List: ";
  p=node1;
  while(p!=NULL){
    cout << p->val << " ";
    p=p->next;
  }
  
  return 0;
}

//https://leetcode.com/problems/reorder-list/
