#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main(){
    TIMME
    set<int>uni, a, b;
    set<int>::iterator it;
    int size_a,size_b,tmp,ans = 0;
    cin >> size_a >> size_b;
    for(int i = 0; i < size_a; ++i){
        cin >> tmp;
        a.insert(tmp);
        uni.insert(tmp);
    }
    for(int i = 0; i < size_b; ++i){
        cin >> tmp;
        uni.insert(tmp);
        b.insert(tmp);
    }
    for(it = uni.begin(); it != uni.end(); ++it){
        if(a.find(*it) == a.end()) ans++;
        if(b.find(*it) == b.end()) ans++;
    }
    cout<<ans;
    return 0;
}
//set은 입력이 들어올때마다 계속 sort 되므로 vector에 입력을 다 받은뒤
//sort하여 집합연산을 하는 것이 더 빠르다