#include <bits/stdc++.h>

using namespace std;

//Time Complexity - O(N^2)
void selectionSort(int arr[], int n) {
    for(int i = 0; i <= n - 2; i++) {
        int mini = i;
        for(int j = i + 1; j <= n - 1; j++) {
            if(arr[j] < arr[mini]) {
               mini = j;
            }
        }
        if(mini != i) {
           int temp = arr[mini];
           arr[mini] = arr[i];
           arr[i] = temp;
        }
    }
}

int main() {
   int arr[6] = {13, 46, 24, 52, 20, 9};
   int n = sizeof(arr) / sizeof(arr[0]);

  selectionSort(arr, n);
  
  for(auto it : arr) {
    cout << it << " ";
  }
  return 0;
}