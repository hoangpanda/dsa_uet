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
  map<int,int> mp;
  int last_v = 1e9;

  for(int i = 0; i < n; ++i) {
    int type; cin >> type;
    if(type == 1) {
      int k; cin >> k;
      mp[k]++;
      last_v = k;
    }
    else if(type == 2) {
      mp[last_v]--;
    }
    else {
      int min_v = 1e9;
      for(auto vv:mp) {
        min_v = min(vv.second,min_v);
      }
      cout << min_v << endl;
    }
  }

}