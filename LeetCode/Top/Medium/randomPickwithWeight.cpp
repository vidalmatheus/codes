#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/*

[ 0 1 ]
  1 3
*/

class LinearSolution {
private:
    vector<pair<int,int>> index2range;
    int size;
public:
    LinearSolution(vector<int>& w) { // O(n)
        int index = 0;
        for (int i=0;i<w.size();i++){
            index2range.push_back({index,index+w[i]-1});
            index += w[i];
        }
        
        size = index;
    }
    
    int pickIndex() { // O(n)
        int index = rand() % size;
        for (int i=0;i<index2range.size();i++){
            if ( index2range[i].first <= index && index <= index2range[i].second)
                return i;
        }
        
        return -1;
    }
};

class Solution {
private:
    vector<pair<int,int>> index2range;
    int size;
public:
    Solution(vector<int>& w) { // O(n)
        int index = 0;
        for (int i=0;i<w.size();i++){
            index2range.push_back({index,index+w[i]-1});
            index += w[i];
        }
        
        size = index;
    }
    
    int pickIndex() { // O(log (n)) -> Binary Search!!!
        int index = rand() % size;
        int left = 0;
        int right = index2range.size()-1;
        while (left <= right){
            int mid = left + (right-left)/2;
            if (index > index2range[mid].second)
                left = mid+1;
            else if (index < index2range[mid].first)
                right = mid-1;
            else return mid;
        }
        
        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

int main(){
    vector<int> w{1,3,2};

    Solution* obj = new Solution(w);
    cout << obj->pickIndex() << " ";
    cout << obj->pickIndex() << " ";
    cout << obj->pickIndex() << " ";
    cout << obj->pickIndex() << " ";
    cout << obj->pickIndex() << endl;

    return 0;
}