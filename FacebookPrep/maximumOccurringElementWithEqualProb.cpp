#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/*

Find an index of maximum occurring element with equal probability
Given an array of integers, find the most occurring element of the array and return any one of its indexes randomly with equal probability.

*/

int maxOcurringElement (vector<int>& nums){
    if (nums.size() == 0)
        return -1;

    unordered_map<int,int> freq;
    vector<int> mostFrequent;

    int maxFreqElem = 0;
    int maxFreq = 0;
    for (int i=0;i<nums.size();i++){
        freq[nums[i]]++;
        maxFreq = max(maxFreq,freq[nums[i]]);
    }

    for (int i=0;i<nums.size();i++)
        if (freq[nums[i]] == maxFreq)
            mostFrequent.push_back(i);

    return mostFrequent[rand() % mostFrequent.size()];
}
// Time: O(n)
// Space: O(n)

int main(){
    vector<int> nums{-1, 4, 9, 7, 7, 2, 7, 3, 0, 9, 6, 5, 7, 8, 9};

    cout << maxOcurringElement(nums) << endl;

    return 0;
}
