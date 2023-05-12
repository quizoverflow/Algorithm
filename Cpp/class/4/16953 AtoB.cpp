#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
#define ull unsigned long long
int main(){
    TIMME
    ull a, b, ans = 0, cnt, num;
    cin >> a>> b;
    queue<pair<ull,ull>> qu; 
    qu.push({0,a});
    while(!qu.empty()){
        cnt = qu.front().first;
        num = qu.front().second;
        qu.pop();
        if(num == b){
            ans = cnt + 1;
            break;
        }
        else if(num < b){
        qu.push({cnt+1,num*2});
        qu.push({cnt+1,num*10 + 1});
        }
    }
    if(ans==0) cout<<-1;
    else cout<< ans;

    return 0;
}