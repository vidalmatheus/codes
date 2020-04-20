#include <bits/stdc++.h>
using namespace std;

/*

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

[1,1,2] have the following unique permutations:

[1,1,2]
[1,2,1]
[2,1,1]

Input: array of integers
Output: array of arrays of permutations


// Without duplicates:
      0 1 2
arr: [1,2,3]

* Choose '1' as first element
 [1]
    [2,3]
        [2][3]
    [3,2]
        [3][2]
    

* Choose '2' as first element
 [2][1,3]
 [2][3,

 0 1 2 3
[1,2,3,4]

[2][1,3,4]

rec(arr,pos,ans): recursion
  // if pos == size of array
      ans.push_back(arr)
      return 
  
  // loop index in [pos,size of array]:
    // swap(arr[pos],array[index])
    // rec(arr,pos+1,ans)
    // swap(arr[pos],arr[index])
    
      0 1 2 
arr: [3,2,1]

ans: {[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,2,1], [3,1,2]}

rec(arr,0,ans): 
  pos: 0
  index: 2
  rec(arr,1,ans): ok
    pos:1
    index:2
    rec(arr,2,ans): ok
      pos:2
      index:2
      rec(arr,3,ans): pb
    rec(arr,2,ans):
      pos:2
      index:2
      rec(arr,3,ans): pb
        
*/


void rec(vector<int>& arr, int pos, vector<vector<int>>& ans){
    if (pos == (int)arr.size()){
      ans.push_back(arr);
      return;
    }
  
    for (int i=pos;i<(int)arr.size();i++){
      swap(arr[pos],arr[i]);
      if (!(pos != i && arr[pos]==arr[i]))
        rec(arr,pos+1,ans);
      else {
          ans.push_back(arr);
          return;
      }
      swap(arr[pos],arr[i]);
    }   
}

vector<vector<int>> permute(vector<int>& arr){
    if (arr.size()==0)
      return {};
  
    vector<vector<int>> ans;
    rec(arr,0,ans);
  
    return ans;
}

// Time: O(n*n!)
// Space: O(n*n!)


int main() {
  vector<int> arr = {1,2,1};
  
  vector<vector<int>> ans = permute(arr);
  
  for (vector<int> row:ans){
    for (int e:row){
      cout << e << " "; 
    }
    cout << endl;
  }
  
  return 0;
}

/*
void permuteRecursive(vector<int> &A, vector<vector<int> >& result, vector <int> &current, map<int, int>& available, int index, int elem) {

  current[index] = elem;    
  available[elem]--;
  
  bool calledRecursion = false;  
  for(auto it = available.begin(); it != available.end(); it++)
      if(it->second > 0){
        permuteRecursive(A, result, current, available, index + 1, it->first);
        calledRecursion = true;
      }
      
  available[elem]++;
  
  if(not calledRecursion) 
    result.emplace_back(current);

}


vector<vector<int> > Solution::permute(vector<int> &A) {
  
  int length = A.size();
  
  vector<vector<int> > result;
    
  map<int, int> available;
  
  for(int i = 0; i < length; i++)
    if(available.find(A[i]) == available.end())
      available[ A[i] ] = 1;
    else available[ A[i] ]++;
    
  vector<int> current(length);
  
  for(auto it = available.begin(); it != available.end(); it++)
    permuteRecursive(A, result, current, available, 0, it->first);
        
  return result;
}

*/
