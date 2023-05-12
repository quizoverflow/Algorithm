#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main(){
    TIMME
    int n, i, tmp;
    cin >> n;
    vector<int> num(n);
    map<int,int> m;
    int *order = new int[n];
    for(i =0 ; i < n; ++i){
        cin >> tmp;
        num[i] = tmp;
        order[i] = tmp;
        m[tmp] = 0; 
    }
    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    for(i= 0; i <num.size(); ++i){
        m[num[i]]= i;
    }
    for(i=0; i <n; ++i){
        cout<<m[order[i]]<<" ";
    }
        
    return 0;
}