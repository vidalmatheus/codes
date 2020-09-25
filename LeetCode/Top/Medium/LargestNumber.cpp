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

class BetterSolution {
private:
    struct myComparator {
        bool operator() (string& a, string& b){

            if (a != b){
                int i = 0;
                int j = 0;
                while (a[i] == b[j]){
                    if (i+1 == (int)a.size() && j+1 == (int)b.size())
                        return i < j;
                    
                    if (i+1 < (int)a.size())
                        i++;
                    if (j+1 < (int)b.size())
                        j++;
                }

                return a[i] > b[j];
            }

            return true;
        }
    };
public:
    string largestNumber(vector<int>& nums) {
        if (nums.size() == 0)
            return "";    
        
        vector<string> all;
        for (int num : nums){
            all.push_back(to_string(num));
        }
        
        struct myComparator comp;
        sort(all.begin(), all.end(), comp);
        
        string ans = "";
        for (string elem : all)
            ans.append(elem);
        
        return ans[0] == '0' ? "0" : ans;
    }
};
// Time: O(N*log n), N characters and n numbers
// Space: O(N)

int main(){
    BetterSolution sol;
    
    vector<int> nums1{3,30,34,5,9};
    assert(sol.largestNumber(nums1) == "9534330");

    vector<int> nums2{10,2};
    assert(sol.largestNumber(nums2) == "210");

    vector<int> nums3{9,99};
    assert(sol.largestNumber(nums3) == "999");

    vector<int> nums4{9,98};
    assert(sol.largestNumber(nums4) == "998");

    vector<int> nums5{0,0,0,0};
    assert(sol.largestNumber(nums5) == "0");

    vector<int> nums6{10,100,1000};
    assert(sol.largestNumber(nums6) == "101001000");
    cout << "Passed!" << endl;
    return 0;
}
