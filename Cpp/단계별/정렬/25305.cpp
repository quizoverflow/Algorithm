#include <bits/stdc++.h>

using namespace std;

int main(void){

    int n,k;
    cin >> n >> k;
    int *grades = new int[n];
    
    for (int i=0; i < n; i++){
        cin >> grades[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1; j++){
            if (grades[j] < grades[j+1]){
                int tem = grades[j];
                grades[j] = grades[j+1];
                grades[j+1] = tem;
            }
        }
    }
    cout << grades[k-1];

    return 0;
}