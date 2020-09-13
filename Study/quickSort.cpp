#include <bits/stdc++.h>

using namespace std;

int partition(vector<int>& v, int left, int right){
    swap(v[left+(right-left)/2],v[right]);
    int pivot = v[right];
    int i = left;
    for (int j=left;j<right;j++){
        if (v[j] < pivot)
            swap(v[j],v[i++]);
    }

    swap(v[right],v[i]);

    return i;
}

void quicksort(vector<int>& v, int left, int right){
    if (left >= right)
        return;
    int p = partition(v,left,right);
    quicksort(v,left,p-1);
    quicksort(v,p+1,right);
}


int main(){
    vector<int> v = {5,4,3,2,1};
    quicksort(v,0,v.size()-1);
    for (int i:v)
        cout << i << " ";
    cout << endl;

    return 0;
}