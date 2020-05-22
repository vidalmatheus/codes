#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
private:
    struct myComparator {
      bool operator() (string& e1, string& e2){
          if (e1[0]!=e2[0]) // first digit is different
              return e1[0]<e2[0]; // who has the bigger first digit is popped out first
          else if (e1==e2) // in this case doesn't matter
              return true;
          else return getOrder(e1,e2);
      }  
    };
    
    static bool getOrder(string& e1, string &e2) {
        int first = 0;
        int second = 0;
        
        while(e1[first]==e2[second]){
            if (first+1<e1.size())
                first++;
            else first = 0;
            if (second+1<e2.size())
                second++;
            else second = 0;
            
            if (first == 0 && second == 0)
                break;
        }

        return e1[first]<e2[second];
    }
    
public:
    string largestNumber(vector<int>& nums) {
        if (nums.size()==0)
            return "";
        
        priority_queue<string, vector<string>, myComparator> pq;
        for (int i=0;i<nums.size();i++)
            pq.push(to_string(nums[i]));
        
        string ans = "";
        while (!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        
        return ans[0]=='0' ? "0" : ans;
    }
};
// Time: O(n log n)
// Space: O(n)

int main(){
    vector<int> nums{3,30,34,5,9};

    Solution sol;
    cout << sol.largestNumber(nums) << endl;

    return 0;
}
