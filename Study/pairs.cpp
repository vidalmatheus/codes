#include <bits/stdc++.h>

using namespace std;

int twoSumLessThanK(vector<int> &A, int s, int e) // this doesn't catch it all, but it's usefull for max (or min) 2-sum-range
{
    if (A.size() == 0)
        return 0;

    int left = 0;
    int right = A.size() - 1;
    while (left < right)
    {
        if (A[left] + A[right] <= e)
        {
            cout << A[left] << " + " << A[right] << endl;
            left++;
        }
        else
        {
            right--;
        }
    }
}

void twoSumBiggerThanK(vector<int> &A, int s, int e) // this doesn't catch it all, but it's usefull for max (or min) 2-sum-range
{
    if (A.size() == 0)
        return;

    int left = 0;
    int right = A.size() - 1;
    while (left < right)
    {
        if (A[left] + A[right] >= s)
        {
            cout << A[left] << " + " << A[right] << endl;
            right--;
        }
        else
        {
            left++;
        }
    }
}

int bruteForce(vector<int> &A, int s, int e) // Just for debugging
{
    int counter = 0;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = i + 1; j < A.size(); j++)
        {
            if (s <= A[i] + A[j] && A[i] + A[j] <= e){
                counter++;
                cout << A[i] << " + " << A[j] << " = " << A[i] + A[j] << endl;
            }
        }
    }
    
    cout << counter << " pairs" << endl;
    return counter;
}

void binarySearchRange(vector<int>& A, int offset, int min, int max){ // This is wrong, 'cause it works only for the first occurrence
    int left = 0;
    int right = A.size()-1;
    while(left < right) {
        int mid = left + (right-left)/2;
        if (offset + A[mid] < min)
            left = mid + 1;
        else if (offset + A[mid] > max)
            right = mid - 1;
        else {
            cout << offset << " + " << A[mid] << endl;
        }
    }
}

int lowerBound(vector<int>& A, int val) { // usual binary search = lower_bound
    int left = 0;
    int right = A.size()-1;
    while (left < right) {
        int mid = left + (right-left)/2;
        if (A[mid] < val)
            left = mid+1;
        else right = mid;
    }

    return left;
}

int upperBound(vector<int>& A, int val) {
    int left = 0;
    int right = A.size()-1;
    while (left < right) {
        int mid = left + (right-left)/2;
        if (A[mid] <= val)
            left = mid+1;
        else right = mid;
    }

    return left;
}

int myBoundsSolution(vector<int>& A, int min, int max){
    cout << "-----" << endl;
    A.push_back(INT_MAX);
    sort(A.begin(), A.end());
    int counter = 0;
    for (int i=0;i<A.size()-1;i++){
        auto upper = upperBound(A, max-A[i]);
        auto lower = lowerBound(A, min-A[i]);
        if (lower <= i && i < upper && counter > 0)
            counter--;
        counter += upper-lower;
        for (int j=lower;j<upper;++j){
            if (j == i)
                continue;
            cout << A[i] << " + " << A[j] << " = " << A[i] + A[j] << endl;
        }
    }

    cout << counter/2 << " pairs" << endl;
    return counter/2;
}

int stlSolution(vector<int>& A, int min, int max){
    cout << "-----" << endl;
    sort(A.begin(), A.end());
    int counter = 0;
    for (int i=0;i<A.size();++i){
        auto upper = upper_bound(A.begin(), A.end(), max-A[i]);
        auto lower = lower_bound(A.begin(), A.end(), min-A[i]);
        if (lower-A.begin() <= i && i < upper-A.begin() && counter > 0)
            counter--;
        counter += upper-lower;
        for (int j=lower-A.begin();j<upper - A.begin();j++){
            if (j == i)
                continue;
            cout << A[i] << " + " << A[j] << " = " << A[i] + A[j] << endl;
        }
    }
    cout << counter/2 << " pairs" << endl;
    return counter/2;
}

int main()
{
    int n, s, e;
    cin >> n;
    cin >> s;
    cin >> e;

    vector<int> A(n);
    for (int i=0;i<n;++i)
        cin >> A[i];

    for (int a : A)
        cout << a << " ";
    cout << endl;

    int ans = bruteForce(A,s,e);
    assert(myBoundsSolution(A,s,e) == ans);
    assert(stlSolution(A,s,e) == ans);
    cout << "Passed!" << endl;
    return 0;
}