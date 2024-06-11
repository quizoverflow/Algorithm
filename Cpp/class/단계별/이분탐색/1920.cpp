#include <bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int> &arr, int start, int end , int key){

    if (start > end) return false;
    
    int mid = (start + end) / 2 ;

    if (arr[mid] == key) return true;
    
    else if (arr[mid] > key) return binarySearch(arr,start, mid - 1, key);
    
    else return binarySearch(arr, mid + 1, end, key);

}

bool binary(vector<int> &arr, int key){
    int length = arr.size();
    int start = 0, end = length - 1, mid = (start + end) / 2;
    
    while (start <= end){
        if (arr[mid] == key) return true;

        if (arr[mid] > key) end = mid - 1;
        
        else start = mid + 1;

        mid = (start + end) / 2;
    }
    return false;

}

int main(void){

    int i, n, m;
    vector<int> nvec;
    vector<int> mvec;

    cin >> n;
    for(i=0; i < n; i++){
        int tem;
        cin >> tem;
        nvec.push_back(tem);
    }
    cin >> m;
    for(i=0; i < m; i++){
        int tem;
        cin >> tem;
        mvec.push_back(tem);
    }
    sort(nvec.begin(),nvec.end());
    for(i=0; i < m; i++){
        if (binarySearch(nvec,0,n-1,mvec[i])) cout <<"1\n";
        else cout <<"0\n";
    }
    
    return 0;
}