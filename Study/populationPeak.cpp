#include<bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

int getPopulationPeak(vector<vector<int>>& people){
    if (people.size()==0)
        return -1;
    
    map<int,int> year2delta;
    for (int i=0;i<people.size();i++){
        year2delta[people[i][0]]++;
        year2delta[people[i][1]+1]--;
    }

    int maxPopulation = INT_MIN;
    int counter = 0;
    int maxPopulationYear = 0;
    for (auto elem:year2delta){
        cout << "[" << elem.first << "]: " << elem.second << endl;
        counter += elem.second;
        if (counter > maxPopulation)
            maxPopulationYear = elem.first;
        maxPopulation = max(maxPopulation,counter);
    }
    
    return maxPopulationYear;
}
// Time: O(n)
// Spce: O(n)

int main(){

    vector<vector<int>> people{
        {2000,2010},
        {1975,2005},
        {1975,2003},
        {1803,1809},
        {1750,1869},
        {1840,1935},
        {1803,1921},
        {1894,1921}
    };

    cout << getPopulationPeak(people) << endl;

    return 0;
}