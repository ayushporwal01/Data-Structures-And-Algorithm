#include <bits/stdc++.h>

using namespace std;

//Brute - TC: O(logN), SC: O(logN) - Recursive(Binary Expo)
const int M = 1e9 + 7;
int findPower(long long a, long long b) {
   if(b == 0) return 1;

   long long half = findPower(a, b/2);
   long long res = (half * half) % M;

   if(b % 2 == 1) {
      res = (res * a) % M;
   }
   
   return res;
}

int countGoodNumbers(long long n) {
   return (long long)findPower(5, (n+1)/2) * findPower(4, n/2) % M;
}

//Optimal(TC: O(logN), SC:O(1)) - Iterative
int findPower2(long long x, long long n) {
   long long res = 1;

   while(n > 0) {
      if(n % 2 == 1) {
         res = (res * x) % M;
      }

      x = (x * x) % M;
      n /= 2;
   }

   return res;
}

int countGoodNumbers2(long long n) {
   long long odd = (n + 1) / 2;
   long long even = n / 2;

   return (findPower2(5, odd) * findPower2(4, even)) % M;
}

int main() {
   int n = 50;
   
   cout << countGoodNumbers(n) << endl;
   cout << countGoodNumbers2(n);
  return 0;
}