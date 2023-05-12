#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifdef ONLINE_JUDGE
#define dbg(x,y) ((void)0)
#else
#define dbg(x,y) std::cout << "[Debug] " << x << " : "<< y <<"\n"
#endif 
using namespace std;
#define ull unsigned long long
int main(){
#ifndef ONLINE_JUDGE
    cout<<"[DEBUG] debug enabled!\n";
#endif
    TIMME
    int n;
    ull x;
    priority_queue<ull, vector<ull>,greater<ull>> pq;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> x;
        if(x == 0){
            if(pq.empty()){
                cout<<0<<"\n";
            }
            else{
                cout<<pq.top()<<"\n";
                pq.pop();
            }
        }
        else{
            pq.push(x);
        }
    }
    return 0;
}