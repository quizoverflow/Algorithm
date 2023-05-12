#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int main(){
    TIMME
    cout<<"hi";   
    vector<int> a;
    for(int i = 0; i < 10 ; ++i) a.push_back(i);
    for(int i = 9; i>= 0; --i){
        a.erase(a.begin()+i);
        cout<<a.size()<<endl;
    }
    return 0;
}