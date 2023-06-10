#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct Edge {
  int v; 
  ll w;
};

struct cmp {
  bool operator() (Edge a, Edge b) {
    return a.w > b.w;
  }
};

const int N = 1e5 + 10;
int n,m;  
vector<Edge> adj[N];


int main() {
  freopen("input.txt","r",stdin);

  cin >> n >> m;
  for(int i = 0; i < m; ++i) {
    int u,v; cin >> u >> v;
    ll w; cin >> w;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }

  ll ans = 0;

  priority_queue<Edge, vector<Edge>, cmp> pq;

  pq.push({1,0});

  while(!pq.empty()) {
    
  }

}