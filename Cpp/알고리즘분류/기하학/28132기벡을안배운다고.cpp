/*
#BOJ 28132 기벡을 안배운다고?
#기하 #해쉬집합
*/
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifdef PSJINU
#include "debug.h"
#else
#define debug(x...)
#endif
using namespace std;

struct pair_hash {
    template <class T1, class T2>
    size_t operator () (pair<T1, T2> const &v) const {
        auto h1 = hash<T1>{}(v.first);
        auto h2 = hash<T2>{}(v.second);
        return h1 ^ h2;
    }
};


int main(){
    FASTIO

    unordered_map<pair<int,int>,int,pair_hash> v;
    //map<pair<int,int>,int> v;

    int n,a,b;
    long long zero = 0;
    long long ans = 0;
    cin >> n;

    for(int i = 0; i < n; ++i){
        cin >> a >> b;
        if(a == 0 && b == 0){
            ++zero;
            continue;
        }
        if(a == 0) b = 1;
        else if(b == 0) a = 1; 
        else{
            int gcd = __gcd(abs(a),abs(b));
            a /= gcd; b /= gcd;
        }
        

        if(v.find(make_pair(a,b)) != v.end()){
            ans += v[make_pair(a,b)];
        }

        if(v.find(make_pair(-b,a)) == v.end()){
            v[make_pair(-b,a)] = 1;
        }
        else{
            v[make_pair(-b,a)]++;
        }

        if(v.find(make_pair(b,-a)) == v.end()){
            v[make_pair(b,-a)] = 1;
        }
        else{
            v[make_pair(b,-a)]++;
        }

    }

    ans += zero * (n - zero) + zero * (zero - 1) / 2;
    cout << ans;

    return 0;
}