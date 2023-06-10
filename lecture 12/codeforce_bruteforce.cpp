#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define all(x) begin(x),end(x)
#define pb push_back
#define pii pair<int,int>


const ll INF = 1e18;


void solve() {

}

signed main() {
  freopen("input.txt","r",stdin);
  
  int n,a,b; cin >> n >> a >> b;
  bool ok = false;
  for(int i = 1; i <= 1e7; ++i) 
  {
    // x = i
    // a*x + b*y = n

    int v = n - a*i;
    if(v % b == 0 && v/b >= 0) {
      cout << "YES" << endl;
      cout << i << ' ' << v/b;
      ok = 1;
      break;
    }

  }

  if(!ok) cout << "NO";

  
}