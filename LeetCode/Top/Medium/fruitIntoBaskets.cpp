#include<bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int totalFruit(vector<int>& tree) { // tree[i]: fruit from tree i
        if (tree.size()==0)
            return 0; // error
        int max = 1; // at least one fruit
        unordered_map<int,int> baskets;
        int i = 0; // starting tree
        int j = 0;
        while (j < tree.size()){
            if (baskets.size()<=2){ 
                baskets[tree[j]]=j++; // baskets[fruit_from_tree_i] = index_from_tree
            }
            cout << "oi" << endl;
            if (baskets.size()>=3){
                int min = tree.size()-1; // we need to find the minimum index from a tree that we've stored into our baskets
                for (pair<int,int> value: baskets){
                    min = std::min(min,value.second);
                }
                baskets.erase(tree[min]); // remove the "first fruit"
                i = min+1; // new starting tree
            }
            max = std::max(max,j-i); // update the maximum value
        } 
        return max;
    }
};

int main(){
    vector<int> tree = {1,2,1};
    Solution sol;
    cout << sol.totalFruit(tree) << endl;
    return 0;
}