#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

vector<int> largestRangeFirst(vector<int>& array) {
  
	sort(array.begin(),array.end());
	vector<int> largestRangeSoFar{array[0],array[0]};
	vector<int> currentRange{array[0],array[0]};
	for (int i=1;i<array.size();i++){
		if (array[i]==array[i-1]+1)
			currentRange[1] = array[i];
		if (currentRange[1]-currentRange[0] > largestRangeSoFar[1]-largestRangeSoFar[0])
				largestRangeSoFar = currentRange;
		if (array[i]>array[i-1]+1){
			currentRange[0] = array[i];
			currentRange[1] = array[i];
		}
	}
		
  return largestRangeSoFar;
}
// Time: O(nlog n)
// Space: O(log n)

vector<int> largestRange(vector<int>& array) {
    unordered_map<int,bool> visited;
    int minValue = INT_MAX;
    for (int i=0;i<array.size();i++){
        visited[array[i]]=false;
        minValue = min(minValue,array[i]);
    }

    int maxLength = INT_MIN;
    vector<int> largestRange;
    for (int num:array){
        if (!visited[num]){
            visited[num] = true;
            int left = num-1;
            int right = num+1;
            while (visited.find(left)!=visited.end()){
                visited[left]=true;
                left--;
            }
            while (visited.find(right)!=visited.end()){
                visited[right]=true;
                right++;
            }
            int currLength = (right-1) - (left+1) + 1;
            if (currLength > maxLength){
                maxLength = currLength;
                largestRange = {left+1,right-1};
            }

        }
    }

    return largestRange;
}
// Time: O(n)
// Space: O(n)

int main(){
    vector<int> array{19,-1,18,17,2,10,3,12,5,16,4,11,8,7,6,15,12,12,2,1,6,13,14};

    vector<int> ans = largestRange(array);

    cout << "[" << ans[0] << "," << ans[1] << "]" << endl;

    return 0;
}
