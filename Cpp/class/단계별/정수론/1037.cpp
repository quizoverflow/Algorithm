#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int main(){
    TIMME
    int i,n;
    cin >>n;
    vector<int> num;
    for(i = 0; i <n; ++i){
        int tem;
        cin >>tem;
        num.push_back(tem);
    }
    cout<<*min_element(num.begin(),num.end()) * *max_element(num.begin(),num.end());
    return 0;
}