#include <bits/stdc++.h>

using namespace std;

int fib(int n) { 
  if(n <= 1) return n;

  return fib(n - 1) + fib(n - 2);
}

int main() {
  int res = fib(1);
  cout << res;

  return 0;
}