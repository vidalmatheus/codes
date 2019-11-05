#include <bits/stdc++.h>

using namespace std;

auto speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

/*
 * Complete the 'numOfIds' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING pool as parameter.
 */

int numOfIds(string pool) {
    cout << pool.size() << endl;
    size_t found = pool.find('8');
    if (found==string::npos) // if doesn't have an '8'
        return 0;
    if (pool.size()<11) // if length < 11 (invalid size)
        return 0;
    int k=0;
    for (auto e:pool)
        if (e=='8') k++;    // counts the number of '8'
    if (pool.size()/11 <= k)    // if its possible to divide in 11-length strings with one '8' at the beginning each
        return pool.size()/11;
    return 0;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string pool;
    getline(cin, pool);

    int result = numOfIds(pool);

    cout << result << endl;
    fout << result << "\n";

    fout.close();

    return 0;
}


