#include <bits/stdc++.h>
using namespace std;

#define int long long

int find_min(vector<int> a) {
  int v = 1e9;
  for(auto vv:a) v = min(v,vv);
  return v;
}

signed main() {
  freopen("input.txt","r",stdin);
  
  int n; cin >> n;
  vector<int> a(n);

  for(int i = 1; i <= n; ++i) {
    int type; cin >> type;
    if(type == 1) {
      int v; cin >> v;
      a.push_back(v);
    }
    else if(type == 2) {
      int n = a.size();
      if(n >= 1) a.pop_back();
    }
    else cout << find_min(a) << endl;
  }

}