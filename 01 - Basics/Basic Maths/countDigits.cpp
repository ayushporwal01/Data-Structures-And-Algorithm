#include <bits/stdc++.h>

using namespace std;

//Time Complexity - O(log₁₀ * N)
int countDigit(int n) {
    int cnt = 0;
    while (n > 0) {
        cnt++;
        n = n / 10;
    }
    return cnt;
}

int main() {
    int res = countDigit(4);
    cout << res; 
    return 0;
}