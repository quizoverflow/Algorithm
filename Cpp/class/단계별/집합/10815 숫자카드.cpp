#include <bits/stdc++.h>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, n, m;
    set<int> nset;
    vector<int> vec;

    cin >> n;
    for(i = 0; i < n; i++){
        int tem;
        cin >> tem;
        nset.insert(tem);
    }

    cin >> m;
    for(i = 0; i < m; i++){
        int tem;
        cin >> tem;
        vec.push_back(nset.count(tem));
    }
    for(i=0; i< m; i++){
        cout << vec[i];
        if(i != m-1){
            cout <<" ";
        }
    }


    return 0;
}