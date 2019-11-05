#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'largestMatrix' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

 int maxIdentity(const int &i, const int &j,const vector<vector<int>> &arr){ // return the maximun dimension of possible identity
    if (arr[i][j]==0) return 0;
    int k_max = 1;
    for (int k=2;k<=min(i,j)+1;k++){
        for (int L=i;L>=i+1-k && L>=0;L--){
            for (int C=j;C>=j+1-k && C>=0;C--){
                if (arr[L][C]==0)
                    return 1;
            }
        }
        if (k>k_max)
            k_max = k;
    }
    return k_max;
 }

int largestMatrix(vector<vector<int>> arr) {
    int n = arr.size();
    int ans = 0;
    bool hasOne = false;
    for (int i=0;i<n;i++){      // checks if the arr is a null matrix
        for (int j=0;j<n;j++){
            if (arr[i][j]==1)
                hasOne = true;
        }
    }
    if (!hasOne) 
        return 0;
    ans = 1;
    for (int i=1;i<n;i++){     
        for (int j=1;j<n;j++){
            if ( maxIdentity(i,j,arr) > ans)
                ans = maxIdentity(i,j,arr);
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_rows_temp;
    getline(cin, arr_rows_temp);

    int arr_rows = stoi(ltrim(rtrim(arr_rows_temp)));

    string arr_columns_temp;
    getline(cin, arr_columns_temp);

    int arr_columns = stoi(ltrim(rtrim(arr_columns_temp)));

    vector<vector<int>> arr(arr_rows);

    for (int i = 0; i < arr_rows; i++) {
        arr[i].resize(arr_columns);

        string arr_row_temp_temp;
        getline(cin, arr_row_temp_temp);

        vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

        for (int j = 0; j < arr_columns; j++) {
            int arr_row_item = stoi(arr_row_temp[j]);

            arr[i][j] = arr_row_item;
        }
    }

    int result = largestMatrix(arr);

    cout << result << endl;
    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
