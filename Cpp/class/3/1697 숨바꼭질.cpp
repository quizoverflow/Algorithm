#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int main(){
    TIMME
    int n, k, i,front,cnt = 0;
    cin >> n >>k;
    queue<int> qu;
    qu.push(n);
    int next[3];
    bool visited[100001] ={false};
    int distance[100001] ={0,};
    while(!qu.empty()){
        front = qu.front();
        if(front == k){
            cout<<distance[front];
            return 0;
        }
        qu.pop();
        next[0] = front -1;
        next[1] = front + 1;
        next[2] = 2 * front;
        cnt++;
        for(i = 0; i < 3; ++i){
            if(!visited[next[i]] && next[i] >=0 && next[i] < 100001){
                qu.push(next[i]);
                visited[next[i]] = true;
                distance[next[i]] = distance[front] + 1;
            }
        }
    }
    
    return 0;
}