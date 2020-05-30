//						 . . . . 
// Heights:  1 2 3 4 5 6 -> n
// InFronts: 3 2 1 2 0 0
// Result:   5 3 2 1 6 4


// Result: 	 6 3 2 1 5 -> not good
// Result: 	 5 3 2 1 6 4

// Time: O(n²)


/*
	// traversal the Heights -> O(n)
        // find right pos -> O(n)
    
    

*/

/*						        .
Heights:  1 2 3 4 5 6
InFronts: 3 2 1 2 0 0
  
inFrontPeople: 0
counter: 0
i: 4


n:6
result: 5 3 2 1 6 4
  			0 1 2 3 4 5
i: 5

. . . 1 . .  

[0]: 0  
[1]: 1 
[2]: 2 
[3]: 3 
[4]: 3 
[5]: 4

 1 19 42 7 19 9 11 12
  
             4 
            /  \
           /    \
          /      \
         /        \
        /          \
       2            2
      /  \        /  \
     2      0    1     1 
    /  \  /  \  / \   /  \
   1    1 0  0 1  0   0   1
  
   m nós -> (m+1)/2 folhas
   
   rec(k)
   
   1 1 1 0 1 0 0 1
  
   n +  n/2 + n/4 + ... = n*2
  
x -> O(x*log(n))
q l r: q 1 6
u i x: u 1 19
*/

#include <bits/stdc++.h>

using namespace std;

int findRightPos(int index, vector<int>& heights, vector<int>& infronts, vector<int>& result){ // Time: O(n)
  int inFrontPeople = infronts[index];
  int counter = 0;
  for (int i=0;i<result.size();i++){
  	if (result[i] == 0){
      counter++;
    	if (counter == inFrontPeople+1)
        return i;
    }
  }
  
  return -1;
}   

vector<int> solution(vector<int>& heights, vector<int>& infronts){ // Time: O(n²)
  // edge cases
  int n = heights.size();
  vector<int> result(n,0);
  for (int i=0;i<heights.size();i++){
  	int pos = findRightPos(i,heights,infronts,result);
    result[pos] = heights[i];  
  }
  
  return result; 
}

int main(){
    vector<int> heights{1,2,3,4,5,6};
    vector<int> infronts{3,2,1,2,0,0};

    vector<int> result = solution(heights,infronts);

    for (int i:result)
        cout << i << " ";
    cout << endl;

    return 0;
}