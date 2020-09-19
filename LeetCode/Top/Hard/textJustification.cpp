#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        vector<string> ans;
        vector<string> aux;
        int counter = maxWidth;
        int letters = 0;
        int K = 0;
        int R = 0;
        
        aux.push_back(words[0]);
        letters += words[0].size();
        counter -= words[0].size();
        for (int i=1;i<(int)words.size();i++){
            if (words[i].size()+1 <= counter){ // in line
                aux.push_back(words[i]);
                letters += words[i].size();
                counter -= words[i].size()+1;
            }
            else { // end line
                
                string line = "";
                if (aux.size() == 1){
                    line = aux[0];
                    int amount = maxWidth - aux[0].size();
                    for (int j=0;j<amount;j++)
                        line.push_back(' ');
                    
                }
                else {              
                    K = (maxWidth-letters)/((int)aux.size()-1);
                    R = (maxWidth-letters)%((int)aux.size()-1);

                    vector<int> spaces(aux.size(),0);

                    for (int j=0;j<(int)spaces.size()-1;j++)
                        spaces[j] += K; 

                    for (int j=0;j<R;j++)
                        spaces[j]++;

                    
                    for (int j=0;j<(int)aux.size();j++){
                        line.append(aux[j]);
                        for (int k=0;k<spaces[j];k++)
                            line.push_back(' ');
                    }
                    spaces.clear();
                }
                
                aux.clear();
                
                letters = 0;
                ans.push_back(line);
                counter = maxWidth;
                
                aux.push_back(words[i]);
                letters += words[i].size();
                counter -= words[i].size();                
            }
           
        }

        int i = (int)words.size()-1;
        string line = "";
        int amount = maxWidth;
        line.append(aux[0]);
        amount -= (int)aux[0].size();
        for (int j=1;j<(int)aux.size();j++){
            line.append(" "+aux[j]);
            amount -= (int)aux[j].size()+1;
        }

        for (int j=0;j<amount;j++)
            line.push_back(' ');
        
        ans.push_back(line);  
        
        return ans;
    }    
};
// Time: O(A), A is the content
// Space: O(A)

int main(){
    Solution sol;
    vector<string> words1{"This", "is", "an", "example", "of", "text", "justification."};
    int L1 = 16;
    vector<string> ans1{{
        "This    is    an",
        "example  of text",
        "justification.  "
    }};
    assert(sol.fullJustify(words1,L1) == ans1);

    vector<string> words2{"What","must","be","acknowledgment","shall","be"};
    int L2 = 16;
    vector<string> ans2{{
        "What   must   be",
        "acknowledgment  ",
        "shall be        "
    }};
    assert(sol.fullJustify(words2,L2) == ans2);

    vector<string> words3{"Science","is","what","we","understand","well","enough","to","explain",
        "to","a","computer.","Art","is","everything","else","we","do"};
    int L3 = 20;
    vector<string> ans3{{
        "Science  is  what we",
        "understand      well",
        "enough to explain to",
        "a  computer.  Art is",
        "everything  else  we",
        "do                  "
    }};
    assert(sol.fullJustify(words3,L3) == ans3);
    cout << "Passed!" << endl;
    return 0;
}