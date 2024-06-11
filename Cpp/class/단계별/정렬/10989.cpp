#include <iostream>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, i;
    cin >> n;

    int arr[10001] = {};
    
    for(i=0; i < n; i++){
        int index;
        cin >> index;
        arr[index] ++;
    }
    for(i=0; i < 10001; i++){
        for(int j=0; j < arr[i]; j++){
            cout << i<<"\n";
        }
    }
    return 0;
}

// 카운팅 정렬... 수의 범위가 작고 메모리 제한이 있다면 활용하기