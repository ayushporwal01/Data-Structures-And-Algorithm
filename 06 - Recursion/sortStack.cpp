#include <bits/stdc++.h>

using namespace std;

// Bruce(TC: O(NlogN), SC: O(N))
stack<int> sortStack(stack<int> st, int n) {
  vector<int> temp;

  while(!st.empty()) {
    int curr = st.top();
    st.pop();
      
    temp.push_back(curr);
  }

  sort(temp.begin(), temp.end());

  for(auto it : temp) {
      st.push(it);
  }

  return st;
}

int main() {
  stack<int> st;
  for(int x: {41, 3, 32, 2, 11}) {
    st.push(x);
  }

  int n = st.size();

  stack<int> ans = sortStack(st, n);
  while(!ans.empty()) {
    cout << ans.top() << " ";
    ans.pop();
  }

  return 0;
}