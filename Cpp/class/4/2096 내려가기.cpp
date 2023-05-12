#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int main(){
    TIMME
    int n;
    cin >> n;
    int a, b, c;
    cin >> a >> b >> c;
    int maax[3] = {a, b, c};
    int miin[3] = {a, b, c};
    for(int i =1 ; i < n; ++i){
        cin >> a>> b>> c;
        int maxf = a + max(maax[0],maax[1]);
        int maxs = b + max(maax[0],max(maax[1],maax[2]));
        int maxt = c + max(maax[1],maax[2]);
        int minf = a + min(miin[0],miin[1]);
        int mins = b + min(miin[0],min(miin[1],miin[2]));
        int mint = c + min(miin[1],miin[2]);
        maax[0] = maxf;
        maax[1] = maxs;
        maax[2] = maxt;
        miin[0] = minf;
        miin[1] = mins;
        miin[2] = mint;
    }
    cout<<*max_element(maax,maax+3)<< " " << *min_element(miin,miin+3);
    return 0;
}