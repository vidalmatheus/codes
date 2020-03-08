#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution { 
public:
    bool isAlienSorted_fails(vector<string>& words, string order) { // This solution only works when all first character are diferents
        if (words.size()==1)
            return true;
        unordered_map<char,int> hash_map;
        int pos=0;
        for (string word:words){
            hash_map[word[0]]=pos;
            pos++;
        }
        
        for (int i=0;i<order.size();i++) {
            int counter=0;
            char last_letter = words[counter][0];
            if (hash_map.find(order[i])!=hash_map.end()){
                if (hash_map[last_letter] > hash_map[order[i]])
                    return false;
                counter++;
                last_letter = words[counter][0];
            }
            
            if (counter == hash_map.size())
                break;
        }
        return true;      
    }

    bool isAlienSorted(vector<string> &words, string order) {
        if (words.size()==1)
            return true;
        unordered_map<char,int> order_map(26);

        for (int i=0;i<order.size();i++) {
            order_map[order[i]]=i;
        } 

        for (int i=0;i<words.size()-1;i++){
            for (int j=i+1;j<words.size();j++){
                int min_length = min(words[i].size(),words[j].size());
                for (int k=0;k<min_length;k++){
                    if (order_map[words[i][k]] < order_map[words[j][k]])
                        break;
                    else if (order_map[words[i][k]] > order_map[words[j][k]])
                        return false;
                    else if (k == min_length-1 && words[i].size() > words[j].size())
                        return false;
                }
            }
        }
        return true;
    }
    // Time: O(n²m)
    // Space: O(1)
};

int main() {
    vector<string> words = {"apple","app"};
    string order = "abcdefghijklmnopqrstuvwxyz";

    Solution sol;
    sol.isAlienSorted(words,order) == true ? cout << "true\n" : cout << "false\n";

    return 0;
}