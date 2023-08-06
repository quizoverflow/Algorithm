/*PS template*/
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(x...)
#endif 
using namespace std;

void show(int(*arr)[3]){
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    FASTIO

    int arr[3][3];
    int cnt = 1;
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j <3; ++j){
            arr[i][j] = cnt++;
        }
    }
    show(arr);
    int *tmp = arr[0];
    tmp[1] = 100;
    show(arr);

    return 0;
}