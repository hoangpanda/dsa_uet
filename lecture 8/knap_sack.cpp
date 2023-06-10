#include <bits/stdc++.h>
using namespace std;



int main() {
  freopen("input.txt","r",stdin);
  int n; cin >> n;
  int x; cin >> x;

  vector<int> weight(n+1);
  vector<int> value(n+1);

  for(int i = 1; i <= n; ++i) {
    cin >> weight[i] >> value[i];
  }

  int f[n+1][x+1];

  // f[i][j]
  // if(j >= a[i]) f[i][j] = max(f[i-1][j],f[i-1][j-a[i]] + value[i])
  // else f[i][j] = f[i-1][j]
  f[0][0] = 0;
  for(int i = 1; i <= n; ++i) f[i][0] = 0;
  for(int i = 1; i <= x; ++i) f[0][i] = 0;

  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= x; ++j) {
      if(j >= weight[i]) {
        f[i][j] = max(f[i-1][j], f[i-1][j-weight[i]] + value[i]);
      }
      else f[i][j] = f[i-1][j];
    }
  }


  cout << f[n][x];
}