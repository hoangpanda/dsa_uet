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

  struct cmp {
    bool operator() (Edge a, Edge b) {
      return a.w > b.w;
    }
  };


  const ll INF = 1e18;
  const int N = 1e5 + 100;
  int n,m;
  vector<Edge> e[N];
  vector<int> parent(N);

  int find(int u) {
    if(parent[u] == u) 
      return u;

    return find(parent[u]);
  }

  void solve() {

    // kruskal
    cin >> n >> m;

    priority_queue<Edge, vector<Edge>, cmp> pq;
    for(int i = 1; i <= m; ++i) {
      int u,v;
      ll w;
      cin >> u >> v >> w;
      pq.push({u,v,w});
    }

    for(int i = 1; i <= n; ++i) 
      parent[i] = i;

    int ans = 0;
    vector<Edge> list;

    while(!pq.empty()) {
      auto k = pq.top();
      pq.pop();

      int u = k.u;
      int v = k.v;
      int w = k.w;

      int a = find(u);
      int b = find(v);
      if(a != b) {
        ans += w;
        parent[b] = a;
        list.pb(k);
      }
      
    }

    cout << ans << endl;
    for(auto v:list) 
      cout << v.u << ' ' << v.v << ' ' << v.w << endl;
  }

  int main() {
    freopen("input.txt","r",stdin);
    solve();
    return 0;
  }