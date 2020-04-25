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
    int numberOfSubarrays(vector<int>& nums, int k) {
        if (nums.size()==0) 
            return 0;
        
        vector<int> prefixOddNumber(nums.size()+1,0);
        for (int i=1;i<=nums.size();i++)
            prefixOddNumber[i] = nums[i-1]%2 ? prefixOddNumber[i-1]+1 : prefixOddNumber[i-1];  
        
        int counter = 0;
        int index = prefixOddNumber.size()-1;
        int toSearch = prefixOddNumber[index]-k; 
        while (toSearch>=0){
            counter += binarySearch(prefixOddNumber,0,index-1,toSearch);
            index--;
            toSearch = index>=0 ? prefixOddNumber[index]-k : -1;
        }
        
        return counter;
    }
    
    int binarySearch(vector<int>& prefix, int left, int right, int val){
        if (val<prefix[0] || val>prefix[prefix.size()-1])
            return 0;

        while (left<=right){
            int mid = left + (right-left)/2;
            if (val<prefix[mid])
                right = mid - 1;
            else if (val>prefix[mid])
                left = mid + 1;
            else {
                int counter = 1;
                int pos = mid+1;
                while (pos <= right && prefix[pos++]==val)
                    counter++;
                pos = mid-1;
                while (pos >= left && prefix[pos--]==val)
                    counter++;                
                return counter;
            }
        }
        
        return 0;
    }
};
// Time: O(nlog n)
// Space: O(n)

class BragaiaSolution{
public:
    int numberOfSubarrays(vector<int>& arr, int k) {
    unordered_map<int,int> hashmap;
    hashmap[0] = 1;
    int ans = 0, countOddSoFar = 0; 
    for(int n:arr){ 
        if(n%2) countOddSoFar++;
        
        if(hashmap.find(countOddSoFar-k) != hashmap.end())
            ans += hashmap[countOddSoFar-k];
        
        if(hashmap.find(countOddSoFar) == hashmap.end())
            hashmap[countOddSoFar] = 0;
        hashmap[countOddSoFar]++;
    }
    return ans;
    }
};
// Time: O(n)
// Space: O(n)

class MineSolution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        if (nums.size()==0) 
            return 0;
        
        vector<int> prefixOddNumber(nums.size()+1,0);
        for (int i=1;i<=nums.size();i++)
            prefixOddNumber[i] = nums[i-1]%2 ? prefixOddNumber[i-1]+1 : prefixOddNumber[i-1];  
    

        // You could have done this with just one for loop!
        unordered_map<int,int> freq;
        for (int e:prefixOddNumber)
            if (freq.find(e)!=freq.end()) // found
                freq[e]++;
            else freq[e]=1;
        
        int counter = 0;
        for (int e:prefixOddNumber)
            if (freq.find(e-k)!=freq.end()) // found
                counter += freq[e-k];
        
        return counter;
    }
};
// Time: O(n)
// Space: O(n)

class BestSolution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        if (nums.size()==0) 
            return 0;
        
        vector<int> prefixOddNumber(nums.size()+1,0);
        for (int i=1;i<=nums.size();i++)
            prefixOddNumber[i] = nums[i-1]%2 ? prefixOddNumber[i-1]+1 : prefixOddNumber[i-1];  
    

        // Now with just one for loop
        int counter = 0;
        unordered_map<int,int> freq;
        for (int e:prefixOddNumber){
            if (freq.find(e-k)!=freq.end()) // found
                counter += freq[e-k];
            if (freq.find(e)!=freq.end()) // found
                freq[e]++;
            else freq[e]=1;

        }
        
        return counter;
    }
};
// Time: O(n)
// Space: O(n)


int main(){
    vector<int> nums = {1,1,2,1,1};
    int k = 3;

    BestSolution sol;
    cout << sol.numberOfSubarrays(nums,k) << endl;

    return 0;
}
