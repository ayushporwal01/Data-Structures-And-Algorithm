#include <bits/stdc++.h>

using namespace std;

void bubbleSort(vector<int> &arr, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - 1; j++) {
            if(arr[j] > arr[j + 1]) {
               swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
  vector<int> arr = {13, 46, 24, 52, 20, 9};
  int n = arr.size();
  bubbleSort(arr, n);
  for(auto it : arr) {
    cout << it << " ";
  }
  return 0;
}