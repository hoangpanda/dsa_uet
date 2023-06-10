#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> a, int x) {
  int n = a.size();
  for(int i = 0; i < (1 << n); ++i) {
    int ans = 0;
    for(int j = 0; j < n; ++j) 
      if((1 << j) & i) ans += a[j];
    if(ans == x) return true; 
  }
  return false;
}

int main() {

  // Given an integer number X and a list A of n natural numbers that are the ages of n students, your task is to find a group students such that the sum of their ages is equal to X.

  // Input: The input consists of n and X in the first line, and n natural numbers in the second line separated by spaces.
  // Output:  Write ‘YES’ if existed, otherwise ‘NO’
  // Input       Output
  // 6 10
  // 2 5 6 2 1 7 YES
  // 1 2 2 7 5 6

  int n; cin >> n;
  int x; cin >> x;
  vector<int> a(n+1);
  for(int i = 1; i <= n; ++i) 
    cin >> a[i];

  cout << check(a,x);

  return 0;
}