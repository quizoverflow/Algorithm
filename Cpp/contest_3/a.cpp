#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifdef ONLINE_JUDGE
#define dbg(x,y) ((void)0)
#else
#define dbg(x,y) std::cout << "[Debug] " << x << " : "<< y <<"\n"
#endif 
using namespace std;


int main(){
#ifndef ONLINE_JUDGE
    cout<<"[DEBUG] debug enabled!\n";
#endif
    TIMME
    int t, n;
    string s;
    cin >> t;
    for(int i = 0; i< t; ++i){
        cin >> n;
        cin >> s;
        int flag = 0;
        bool fo = true;
        char meow[4][2] = {{'m','M'},{'e','E'},{'o','O'},{'w','W'}};
        int j = 0;
        while(s[j] != 'w' || s[j] != 'W'){
            if(j == n-1) break;
            if(s[j] == meow[flag][0] || s[j] == meow[flag][1]){
                while(s[j] != meow[flag][0] || s[j] != meow[flag][1]){
                    j++;
                }
                flag ++;
                if(s[j] != meow[flag][0] || s[j] != meow[flag][1]){
                    flag = 0;
                }
            }
            else j++;
        }
        for(int k = j; k < n; ++k){
            if(s[k] == 'w' || s[k] == 'W') continue;
            else{
                cout<<"No\n";
                fo = false;
                break;
            }
        }
        if(flag == 3 && fo) cout <<"Yes\n";
    }
    
    return 0;
}