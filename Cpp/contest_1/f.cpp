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
    int t, n, m, si, sj, ei, ej;
    string d;
    cin >> t;
    
    pair<string,pair<int,int>> dir[4] = {
        {"DR",{1,1}}, //dr
        {"DL",{1,-1}}, //dl
        {"UR",{-1,1}}, //ur
        {"UL",{-1,-1}} //ul
    };

    while(t--){
        cin >> n >> m >> si >> sj >> ei >> ej >> d;
        pair<int,int> di;
        for(auto &a : dir){
            if(a.first == d) di = a.second;
        }
        int ci = si, cj = sj, delta , bounce = 0;
        while(1){
            dbg(di.first,di.second);
            if(bounce >= 5){
                cout<<-1<<"\n";
                break;
            }
            if((ei - si * di.first)==(ej - sj * di.second)){
                cout<<bounce<<"\n";
                break;
            }
            if(di.first == -1){
                if(di.second == 1){
                    
                }
            }
            ci += di.first * delta;
            cj += di.second * delta;
            bounce++;
            if(ci == n){
                if(cj == 0){
                    di = {-1,1};
                }
                else if(cj == m){
                    di = {-1,-1};
                }
                else di.first = -1;
            }
            else if(ci == 0){
                if(cj == 0){
                    di = {1,1};
                }
                else if(cj == m){
                    di = {1,-1};
                }
                else di.first = 1;
            }
            if(cj == m){
                if(ci == 0){
                    di = {1,-1};
                }
                else if(ci == n){
                    di = {-1,-1};
                }
                else di.second = -1;
            }
            else if(cj == 0){
                if(ci == 0){
                    di = {1,1};
                }
                else if(ci == n){
                    di = {-1,1};
                }
                else di.second = 1;
            }

        }
    }

    return 0;
}