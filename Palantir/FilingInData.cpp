#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'calcMissing' function below.
 *
 * The function accepts STRING_ARRAY readings as parameter.
 */

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

float getVal(vector<string>& readings, int pos){
    if (pos < 0 || pos >= readings.size())
        return -1;
    if (readings[pos].find("_") != string::npos) return -1;
    int n = readings[pos].size();
    string val = "";
    int i = n-1;
    while (isdigit(readings[pos][i]) || readings[pos][i] == '.')
        val = readings[pos][i--] + val;
    return stof(val); 
}

void calcMissing(vector<string> readings) {
    // approach: linear interpolation    

    int n = readings.size();
    vector<double> nums(n,0);
    for (int i=0;i<n;i++)
        nums[i] = getVal(readings,i);

    for (int i=0;i<n;i++){
        if (nums[i] == -1){
            if (i == 0){
                nums[i] = nums[i+1]*2 - nums[i+2];
                cout << nums[i] << endl;
            }
            else {
                int j = i;
                while (nums[++j] == -1);
                float delta = (nums[j]-nums[i-1])/(j-(i-1));
                while (nums[i] == -1){
                    nums[i] = nums[i-1] + delta;
                    cout << nums[i] << endl;
                    i++;
                }
                i--;
            }
        }
    }
}

float getX(vector<string>& readings, int pos){
    if (pos < 0 || pos >= readings.size())
        return -1;

    // 6/1/2012 16:00:00	29.15
    int indexM = readings[pos].find("/");
    float m = stof(readings[pos].substr(0,indexM));

    int indexD = readings[pos].substr(indexM+1).find("/");
    float d = stof(readings[pos].substr(indexM+1,indexD)); 
    return m*31+d;
}

struct Data {
    int X;
    float Y;
    Data(int x, float y) : X(x), Y(y) {};
};

float getY(vector<string>& readings, int pos){
    if (pos < 0 || pos >= readings.size())
        return -1;
    if (readings[pos].find("_") != string::npos) return -1;
    int n = readings[pos].size();
    string val = "";
    int i = n-1;
    while (isdigit(readings[pos][i]) || readings[pos][i] == '.')
        val = readings[pos][i--] + val;
    return stof(val); 
}

float interpol(vector<Data>& f, int x, int n){
    float val = 0;
    for (int i=0;i<n;i++){
        float prod = f[i].Y;
        for (int j=0;j<n;j++){
            if (i!=j)
                prod = prod*(x-f[j].X)/(float(f[i].X - f[j].X));
        }

        val += prod;
    }

    return val;
}

void calcMissing(vector<string> readings) {
    // approach: Lagrange's interpolation  

    int n = readings.size();
    
    // build points
    int missing = 0;
    vector<Data> f;
    for (int i=0;i<n;i++){
        float y = getY(readings,i);
        if (y != -1){
            int x = getX(readings,i);
            f.push_back(Data(x,y));
        }
        else missing++;
    }

    // interpolate
    for (int i=0;i<n;i++){
        float y = getY(readings,i);
        if (y == -1){
            int x = getX(readings,i);
            cout << interpol(f,x,n-missing) << endl;
        }
    }
}

int main(){
    int n;
    cin >> n;
    string aux;
    std::getline (std::cin,aux);
    vector<string> readinsgs(n,"");
    for (int i=0;i<n;i++){
        std::getline (std::cin,readinsgs[i]);
    }

    calcMissingLinearApproach(readinsgs);
    return 0;
}