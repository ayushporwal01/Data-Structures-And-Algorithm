#include <bits/stdc++.h>

using namespace std;

//Brute Force - TC: O(N^3), SC: O(No. of unique triplets * 2)
vector<vector<int>> threeSum(vector<int> arr) {
    int n = arr.size();
    set<vector<int>> st;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                if(arr[i] + arr[j] + arr[k] == 0) {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end()); 
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

//Better - TC: O(N^2), SC: O(No. of unique triplets + N)
vector<vector<int>> threeSum2(vector<int> arr) {
    int n = arr.size();
    set<vector<int>> st;

    for(int i = 0; i < n; i++) {
        set<int> hashset;
        for(int j = i + 1; j < n; j++) {
            int third = -(arr[i] + arr[j]);
            if(hashset.find(third) != hashset.end()) {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end()); 
                st.insert(temp);
            }
            hashset.insert(arr[i]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

//Optimal - TC: O(NlogN + N^2), SC: O(No. of unique triplets)
vector<vector<int>> threeSum3(vector<int> arr) {
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i++) {
        if(i > 0 && arr[i] == arr[i - 1]) continue;
        int j = i + 1;
        int k = n - 1;
        while(j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if(sum < 0) {
               j++;
            }
            else if(sum > 0) {
              k--;
            }
            else {
               vector<int> temp = {arr[i], arr[j], arr[k]};
               ans.push_back(temp);
               j++;
               k--;
               while(j < k && arr[j] == arr[j - 1]) j++;
               while(j < k && arr[k] == arr[k + 1]) k--;
            }
        }
    }
    return ans;
}

int main() {
  vector<int> arr = {-1, 0, 1, 2, -1, 4};

  vector<vector<int>> ans = threeSum(arr);
  for(auto it : ans) {
    for(auto ele : it) {
        cout << ele << " ";
    }
    cout << endl;
  }

  cout << endl;
  
  vector<vector<int>> ans2 = threeSum(arr);
  for(auto it : ans2) {
    for(auto ele : it) {
        cout << ele << " ";
    }
    cout << endl;
  }
  
  cout << endl;

  vector<vector<int>> ans3 = threeSum(arr);
  for(auto it : ans3) {
    for(auto ele : it) {
        cout << ele << " ";
    }
    cout << endl;
  }  

  return 0;
}