#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int main(){
    TIMME
    int arr[9];
    int i, m = 0,a = 0;
    for(i = 0; i < 9; ++i){
        cin >> arr[i];
        if(arr[i] > m){
            m = arr[i];
            a = i+1;
        }
    }
    cout<<m<<"\n"<<a;
    return 0;
}