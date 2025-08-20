#include <bits/stdc++.h>

using namespace std;

//Brute Force - TC: O(NlogN + 2N), SC: O(N)
vector<vector<int>> mergeIntervals(vector<vector<int>> &arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());  
    vector<vector<int>> ans;
    for(int i = 0; i < n; i++) {
        int start = arr[i][0];
        int end = arr[i][1];

        //If current interval is inside the last merged interval, skip it
        if(!ans.empty() && end <= ans.back()[1]) {
           continue;
        }

        //Merge with overlapping intervals
        for(int j = i + 1; j < n; j++) {
            if(arr[j][0] <= end) {
               end = max(end, arr[j][1]); 
            }
            else {
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}

//Brute Force - TC: O(NlogN), SC: O(N)
vector<vector<int>> mergeIntervals(vector<vector<int>> &arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());  
    vector<vector<int>> ans;
    for(int i = 0; i < n; i++) {
        if(ans.empty() || arr[i][0] > ans.back()[1]) {
           ans.push_back(arr[i]);
        }
        else {
           ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> arr = {{1,3}, {2,6}, {8,10}, {15,18}};

    vector<vector<int>> ans = mergeIntervals(arr);
    for(auto it : ans) {
        cout << "[";
        cout << it[0] << "," << it[1]; 
        cout << "] ";
    }
    
    cout << endl;

    vector<vector<int>> ans = mergeIntervals(arr);
    for(auto it : ans) {
        cout << "[";
        cout << it[0] << "," << it[1]; 
        cout << "] ";
    }

  return 0;
}