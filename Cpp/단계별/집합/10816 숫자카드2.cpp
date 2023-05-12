#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int main(){
    TIMME
    int n,m,tmp = 0;
    vector<int> num(n);
    vector<pair<int,int>> nv;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> num[i];
    sort(num.begin(),num.end());
    int curr = num[0];
    for(int i = 0; i < n; ++i){
        if(curr == num[i]) tmp++;
        else{
            nv.push_back({curr,tmp});
            tmp = 1;
            curr = num[i];
        } 
    }
    for(int i = 0; i < nv.size(); ++i){
        cout<<nv[i].first<<" = " <<nv[i].second<<endl;
    }

    /* cin >> m;
    for(int i = 0; i < m; ++i){
        cin >> tmp;
        int index = n / 2;

    } */


    
    return 0;
}