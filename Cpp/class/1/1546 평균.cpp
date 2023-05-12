#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int main(){
    TIMME
    int i, n;
    cin >> n;
    int *grade = new int[n];
    int max_grade = 0;
    float ans;
    for(i = 0; i < n; ++i){
        cin >>grade[i];
        if(grade[i] > max_grade) max_grade = grade[i];
    }
    for(i = 0; i <n; ++i){
        ans += grade[i];
    }
    ans = (ans * 100) / (max_grade * n);
    cout<<ans;
    return 0;
}