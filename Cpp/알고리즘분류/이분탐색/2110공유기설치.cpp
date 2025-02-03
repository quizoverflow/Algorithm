/*
#BOJ 2110 공유기설치
#이분탐색
*/

#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifdef PSJINU
#include "debug.h"
#else
#define debug(x...)
#endif 
using namespace std;

int main(){
    FASTIO
    int n,c;
    cin >> n >> c;
    vector<int> house(n);
    for(int i= 0; i < n; ++i){
        cin >> house[i];
    }
    sort(house.begin(),house.end());

    int s = 1;
    int e = house.back() - house.front();
    int mid;
    int ans = 0;
    while(s <= e){
        //mid == distance 
        mid = (s + e) / 2;
        
        //check
        int cnt = 1;
        int prev = house.front();
        for(int i = 1; i < n; ++i){
            if(house[i] - prev >= mid){
                prev = house[i];
                cnt++;
            }
        }
        if(cnt >= c){
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid - 1;
        }
    }
    cout << ans;

    return 0;
}
