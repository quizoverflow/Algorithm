#include <bits/stdc++.h>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    string snum;
    string snum_r;
    cin >> num;
    snum = to_string(num);
    for(int i=snum.length(); i >=0; i-- ){
        snum_r.append(snum[i]);
        
    }
    cout << snum_r;
    cout << atoi(snum_r);
    return 0;
}