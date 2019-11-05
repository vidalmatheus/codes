#include <bits/stdc++.h>

using namespace std;

/// Dynamic Program Coin Change Algorithm
int DPMakeChange(const std::vector<unsigned int> &denom,unsigned int value, std::vector<unsigned int> &coins, std::vector<unsigned int> &last) {
	// moedas: vetor de moedas disponíveis (menor é de 1 centavo)
	std::vector<unsigned int> quant(value+1);
	quant[0] = 0; // solução ótima para troco de valor 0
	last[0] = 0; // última moeda dessa solução
	for (int cents = 1; cents <= value; cents++) {
		int quantProv = cents; // solução provisória: todas de 1 centavo
		int ultProv = 0; // última moeda dessa solução
		for (int j = 0; j < denom.size(); j++) {    // Será testada cada valor de moeda
			if (denom[j] > cents) continue; // essa moeda não serve
			if (quant[cents - denom[j]] + 1 < quantProv) { // para achar a mínima quantidade de moedas
				quantProv = quant[cents - denom[j]] + 1;
				ultProv = j;
			}
		}
		quant[cents] = quantProv; // solução para troco == cents
		last[cents] = ultProv; // última moeda dessa solução
	}

	return quant[value]; // quantidade ótima de moedas para troco
}

/// Build a correct trace
void TraceChange(const std::vector<unsigned int> &denom, unsigned int value, std::vector<unsigned int> &coins, std::vector<unsigned int> &last){
	
	// Building the array
	for (int i = value; i > 0; i-=denom[last[i]])
		coins[last[i]]++;
}

int main (){
    vector<unsigned int> denom, coins, last;
    int value;
    cout << "Denominations: ";
    int tmp=0;
    while (tmp != -1){
        cin >> tmp;
        denom.push_back(tmp);
    }
    
    coins.resize(denom.size());
    last.resize(value+1);

    cout << "Amount: ";
    cin >> value;

    // Call DPMakeChange
    int ans = DPMakeChange(denom,value,coins,last);
    cout << "Minimum Amount of Coins is: " << ans << endl;

    // Call Print coins (Solution)
    TraceChange(denom, value, coins, last);
    for (auto c:coins)
        cout << c << " ";


    return 0;
}