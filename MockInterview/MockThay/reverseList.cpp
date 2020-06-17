#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/* Given a singly linked list and an integer K, reverses the nodes of the

list K at a time and returns modified linked list.
  
Given linked list 1 -> 2 -> 3 -> 4 -> 5 -> 6 and K=3,
You should return 3 -> 2 -> 1 -> 6 -> 5 -> 4  
  
NOTE : The length of the list is divisible by K
  


    s1        e1   s2        e2
 h->1 -> 2 -> 3 -> 4 -> 5 -> 6
    
    q     p
 h->3->2->1
  
                               b
         h              a      c           t
 .... -> 1    4 <- 5 <- 6 -> null 
               beginning: b->t
               move a and b
                end: h->a
  
*/
void reverseList(ListNode* h, ListNode* t){ // Time: O(k) & O(1)
  ListNode* a, *b, *c, *f;
  a = h;
  b = h->next;
  f = b;
  
  // beginning: b->t
  a = b;
  b = b->next;
  
  // move a and b
  while (b != t){
    c = b->next;
    b->next = a;
    a = b;
    b = c;
  }
  
  h->next = a;
  f->next = t;
}

ListNode* reverseList(ListNode* A, int B) {
    ListNode* prev = nullptr;
    ListNode* curr = A;
    ListNode* next = nullptr;
    int count = 0;
    
    while(curr != nullptr and count < B){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        ++count;
    }
    
    if(curr != nullptr){
        A->next = reverseList(curr, B);
    }
    
    return prev;
}

/*
    i
1 2 3
    j


[1,2,3]3,3]
       i 
           j

1. traversal
i -> build my answer
j -> look for elements

2. cut off the last part

[1]
 


[1,2,3]
       i
       j
     
[1,2,3,3,3]
       i
           j
*/

int removeDuplicates(vector<int> &A) {
   int size = A.size();
   if(size == 0){
       return 0;
   }
   
   int writeIndex = 1;
   
   for(int i = 1; i < size; ++i){
       if(A[writeIndex - 1] != A[i]){
           A[writeIndex++] = A[i];
       }
   }
   
   return writeIndex;
}

int removeDuplicates(vector<int>& nums){ 
  int n = nums.size();
  if (n == 0)
    return 0;

  int i = 1;
  
  for (int j=1;j<n;j++){
    if (nums[j] != nums[j-1])
      nums[i++] = nums[j];
  }

  return i;
}
