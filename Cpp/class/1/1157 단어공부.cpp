#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int main(){
    TIMME
    int i;
    string word;
    int dp[26] = {0};
    cin >> word;
    for(i=0; i < word.size(); ++i){
        if(word[i] >= 'a' && word[i] <= 'z') word[i] -= 32;
        dp[word[i] - 'A']++;
    }
    int max_data = 0;
    vector<int> ans;
    for(i = 0; i < 26; ++i){
        if(dp[i] > max_data){
            max_data = dp[i];
            ans.clear();
            ans.push_back(i);
        }
        else if(dp[i] == max_data) ans.push_back(i);
    }
    char alphabet = ans[0] + 'A';
    if(ans.size() > 1) cout<<"?";
    else cout<<alphabet;
    return 0;
}