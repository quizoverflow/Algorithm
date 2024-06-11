#include <bits/stdc++.h>

using namespace std;
unsigned long long t_data[1000001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    t_data[1] = 1;
    t_data[2] = 2;
    for(int i = 3; i <= n; i++){
        t_data[i] = (t_data[i-1] + t_data[i-2]) % 15746;
    }
    cout <<t_data[n];
    return 0;
}