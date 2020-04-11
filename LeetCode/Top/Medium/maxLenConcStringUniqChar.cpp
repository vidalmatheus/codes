#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class SlowSolution {
public:
    int maxLength(vector<string>& arr) {
        if (arr.size()==0)
            return 1;
        
        int ans=0;
        maxUnique(arr,0,"",ans);

        return ans;    
    }

    void maxUnique(const vector<string> &arr, int pos, string curr, int &max){
        if (pos == arr.size() && uniqueCharCounter(curr)>max){
            max = uniqueCharCounter(curr);
            return;
        }

        if (pos == arr.size())
            return;

        maxUnique(arr,pos+1,curr,max); // without concatenating string at pos index
        maxUnique(arr,pos+1,curr+arr[pos],max); // with concatenating string at pos index
    }

    int uniqueCharCounter(string curr){
        //         unordered_set<char> s;
        //         for (int i=0;i<curr.size();i++){
        //             if (s.find(curr[i])!=s.end()) // found
        //                 return -1;
        //             else s.insert(curr[i]);
        //         }

        //         return curr.size();

        // Same solution without hash_set
        vector<int> counts(26);
        for(char c:curr)
            if (counts[c-'a']>0)
                return -1;
            else counts[c-'a']++;
        return curr.size();
    }
};
// Time: O(2^n)
// Space: O(1)

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

// A hash function used to hash a pair of any kind 
struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
};

class Solution {
  public:
    int maxLength(vector<string>& arr){
        return rec(0, 0, arr);
    }
    
  private:
    unordered_map<pair<int,int>,int,hash_pair> results;
    
    int rec(int index, int bitmask, vector<string>&arr){
        if(results.find({index, bitmask}) != results.end())
          return results[{index, bitmask}];

        if(index >= (int)arr.size())  
          return 0;
        
        int nextBitmask = addToBitMask(arr[index], bitmask);
        if(nextBitmask == -1)
            return results[{index, bitmask}] = rec(index+1, bitmask, arr);
        else return results[{index, bitmask}] = max(rec(index+1, bitmask, arr), (int)arr[index].size() + rec(index+1, nextBitmask, arr));
    }
     
    int addToBitMask(string& str, int bitmask){
      int bitPosition;
      for(int c:str){
        bitPosition = c - 'a'; // it will return 0...25
        if(bitmask & (1<<bitPosition)) // if (x): true if x!=0
          return -1;
         
        bitmask |= (1<<bitPosition);
      }
      
      return bitmask;
    }
};
/*
Time: O(#states=all of index*all of bitmasks) --> think about the states: (pos,bitmask)
                pos, bitmask
                 n*(2^26)
Space: O(n*26)
*/

int main() {
    vector<string> arr = {"un","iq","ue"};

    Solution sol;    
    cout << sol.maxLength(arr) << endl;

    return 0;
}
