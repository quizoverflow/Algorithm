#include <iostream>
#include <vector>

using namespace std;

void primeFactors(int n) {
    // n을 2로 나누어 떨어지는 만큼 나누고 2를 출력
    while (n % 2 == 0) {
        cout << 2 << " ";
        n = n / 2;
    }

    // n을 2 이상의 홀수로 나누어 떨어지는 만큼 나누고 해당 소수를 출력
    for (int i = 3; i * i <= n; i = i + 2) {
        while (n % i == 0) {
            cout << i << " ";
            n = n / i;
        }
    }

    // 남은 소수가 1이 아니면 출력
    if (n > 1)
        cout << n << " ";
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Prime factors of " << n << " are: ";
    primeFactors(n);
    return 0;
}
