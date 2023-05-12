#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
#define ull unsigned long long

int main(){
    TIMME
    ull n,i,tem;
    ull ans = 0;
    ull price_goal;
    cin >> n;
    vector<int> distance;
    vector<int> price;
    for(i = 0; i <n-1; ++i){
        cin >> tem; 
        distance.push_back(tem);
    }
    cin >> price_goal;
    ans = price_goal * distance[0];
    for(i = 1; i <n-1; ++i){
        cin >>tem;
        if(tem < price_goal) price_goal = tem;
        ans += price_goal * distance[i];
    }
    cout<< ans;
    return 0;
}