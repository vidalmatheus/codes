/*
Const vector<string> & words;
Size_t L
L = 7
vector<strings> justifiedLine;
[Hi||How], []
[Hi,How,matheus,abc,defg]

                i
Words = [the, quick, brown, fox, jumped, over, the, lazy, dogs]
L = 11
Ans = [the|||quick], [brown|||fox], [jumped|over], [the||||lazy], [dogs|||||||]
vector<string> justifyText(const vector<string> & words, size_t L)

//11 -3 -1 = 7
Int counter = 7-5=2
Int letters = 8

1 2 3 4 5
3 3 2 2 2
[lazy|dogs||||||||||||||] -> spaces: [1,remaining]
3 <= 11 -> [the]
5+1 <= 8 ->  aux: [the,quick]
5+1 <= 8-6=2 -> NO!
 aux: [the,quick] -> k:(11-8)/(2-1) = 3  remainder:0
		   Spaces: [3,0]
            	Line: [the|||quick]


vector<string> justifyText(const vector<string> & words, size_t L)	vector<string> aux;
	vector<int> spaces;
	string line = “”;

	Int counter = L;
	Int letters = 0;
	Int r = 0;
	For (int i=0;i<(int)words.size();i++){
		If (i+1<words.size() && words[i+1].size()+1 < counter - word[i].size()){
        aux.push_back(word[i]);
        Letters += word[i].size();
    }
    Else if (i+1<word.size()) {
        K = (L-letters)/((int)aux.size()-1);
        R = (L-letters)%((int)aux.size()-1);
        
        spaces.resize(aux.size(),0);
        For (int j=0;j<(int)spaces.size()-1;j++){
            Spaces[i] += k; 
        }
        For (int j=0;j<R;j++){
            Spaces[i]++;
        }
    }
    Else {

    }

}
*/