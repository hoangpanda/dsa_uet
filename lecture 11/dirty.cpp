#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) begin(x),end(x)
#define pb push_back
#define pii pair<int,int>

struct Edge {
  int u,v;
  ll w;
};

const ll INF = 1e18;
const int N = 1e3 + 100;
int n,m,start,endd;
vector<Edge> e;
vector<ll> d(N,INF);
vector<int> trace(N,-1);
vector<vector<ll>> dist(N, vector<ll>(N,INF));


void bellman_ford() {
  d[start] = 0;

  for(int i = 1; i < n; ++i) {
    for(auto k:e) {
      int u = k.u;
      int v = k.v;
      ll w = k.w;

      if(d[u] != INF && d[v] > d[u] + w) {
        d[v] = d[u] + w;
        trace[v] = u;
      }
    }
  }

  cout << d[endd] << endl;

  vector<int> list;
  list.pb(endd);
  int t = endd;
  while(trace[t] != -1) {
    list.pb(trace[t]);
    t = trace[t];
  }

  reverse(begin(list), end(list));

  for(auto v:list) 
    cout << v << ' ';
  cout << endl;
}

void floyd_warshall() {
  for(int i = 1; i <= n; ++i)
    dist[i][i] = 0;

  for(auto k:e) {
    int u = k.u;
    int v = k.v;
    ll w = k.w;

    dist[u][v] = min(dist[u][v], w);
  //  dist[v][u] = min(dist[v][u], w);
  }

  for(int k = 1; k <= n; ++k) {
    for(int i = 1; i <= n; ++i) {
      for(int j = 1; j <= n; ++j) {
        if(dist[i][j] > dist[i][k] + dist[k][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
        //  cout << i << ' ' << k << ' ' << j << ' ' << dist[i][j] << endl;
        }
      }
    }
  }

  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) {
      if(dist[i][j] == INF)
        cout << "INF";
      else 
        cout << dist[i][j];
      cout << ' ';
    }
    cout << endl;
  }
}

void solve() {
  cin >> n >> m >> start >> endd;
  for(int i = 1; i <= m; ++i) {
    int u,v; ll w; cin >> u >> v >> w;
    e.pb({u,v,w});
  }

  bellman_ford();

  floyd_warshall();
} 

int main() {
  freopen("input.txt","r",stdin);
  solve();
  return 0;
}