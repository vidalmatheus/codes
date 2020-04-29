/*
20:35 - 20:40
20:40 - 21:25

House broker

vector<vector<int>> listings;
Column : house
0: price
1: area

vector<vector<int>> clients;
Column: client
0: maximum price. Clients can buy house <= price
1: minimum area. Clients looking for house > area

Maximum number of houses you can sell
-> 500, 300=> 300

Hint 1: 
Client(0) - not buying(1,2)   → 
Client(1) - not buying (client(0)Houses)  → X  
Client(2) - not buying (client(1)Houses) → {3}
Client(3) - not buying (client(2) houses)  → X

Hin 2: Merge both matrices

Clients: 
 minA maxPrice 
0: 5 800  -> 3 , 0
1: 8 200 ->0
2: 9 500 -> 0, 3
3: 7 400 -> 0

Burgler
Burglary

heist

Nlog n

(5, 800, C), (7, 400, C), (8, 200, C), (8, 200, H), (8, 100, H), (9, 500, C),(10, 100, H),(30, 700, H) 

800,400,100


BST - set<int> --lower_bound(price)
500, 800

1+1+1
Listings:
     A   p
0: 10  100 -> client 0,1,2 can buy this
1:  8   200 -> no one  
2:  8   200 -> no one
3:  30 700 -> client 2,3 can buy

ANS: 2

///
Clients: 
[0]: 3,0
[1]: 0
[2]: 0
[3]: 0,3,

rec(house i, client j):
	// base case

	return max(rec(i+1, clients != j))


*/

#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

struct myComparator {
    bool operator() (pair<vector<int>,char>& e1, pair<vector<int>,char>& e2){
        if (e1.first[0]==e2.first[0])
            if (e1.first[1]==e2.first[1])
                    return e1.second < e2.second;
            else return e1.first[1] < e2.first[1];
        else return e1.first[0] < e2.first[0];
    }
};

class Solution {
public:
    int maxNumberHouses(vector<vector<int>>& houses, vector<vector<int>>& clients){
        if (houses.size()==0 || clients.size()==0)
            return 0;
        
        vector<pair<vector<int>,char>> merged;
        merged.reserve(houses.size()+clients.size());
        for (int i=0;i<houses.size();i++)
                merged.push_back({{houses[i][0],houses[i][1]},'H'});
        
        for (int i=0;i<clients.size();i++)
                merged.push_back({{clients[i][0],clients[i][1]},'C'});
    
        sort(merged.begin(),merged.end());

        for (auto e:merged)
            cout << "[" << e.first[0] << "," << e.first[1] << "," << e.second << "]" << " ";
        cout << endl;

        int counter = 0;
        set<int> prices;
        for (int i=0;i<merged.size();i++)
            if (merged[i].second=='C')
                prices.insert(merged[i].first[1]);
            else { // it's a house
                if (!prices.empty()){
                    int housePrice = merged[i].first[1];
                    prices.erase(*prices.lower_bound(housePrice));
                    counter++;
                }
            }

        return counter;
    }
};
// Time: O(n*log(n))
// Space: O(n)

int main(){
    vector<vector<int>> houses{
        {10, 100},
        {2, 200},
        {30, 300},
    };

    vector<vector<int>> clients{
        {5, 110},
        {9, 500},
        {20, 400},
    };

    Solution sol;
    cout << sol.maxNumberHouses(houses,clients) << endl;

    return 0;
}
