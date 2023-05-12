#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main(){
    TIMME
    int n,m,i,j,p;
    cin >>n>>m;
    int *arr = new int[n+1];
    arr[0] = 0;
    for(p = 1; p<=n; ++p){
        int tem;
        cin >> tem;
        arr[p] = arr[p-1] + tem;
    }
    for(p=0; p <m; ++p){
        cin>>i>>j;
        cout<<arr[j] - arr[i-1]<<"\n";
    }
    return 0;
}