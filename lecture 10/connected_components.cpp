#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 100;
vector<int> a[N];
vector<bool> vis(N,false);
int n,m; 

void dfs(int start) {
  queue<int> q;
  q.push(start);
  vis[start] = 1;

  while(!q.empty()) {
    int k = q.front();
    q.pop();

    for(auto v:a[k]) 
      if(!vis[v]) {
        vis[v] = true;
        q.push(v);
      }
  }
}

void connected_components_dfs() {
  int cnt = 0;
  for(int i = 1; i <= n; ++i) 
    if(!vis[i]) {
      dfs(i);
      cnt++;
    }

  cout << cnt << '\n';
}

void bfs(int start) {
  vis[start] = true;
  for(auto v: a[start]) 
    if(!vis[v]) {
      bfs(v);
    }
}

void connected_components_bfs() {
  fill(begin(vis),end(vis), 0);
  int cnt = 0;

  for(int i = 1; i <= n; ++i) {
    if(!vis[i]) {
      bfs(i);
      cnt++;
    }
  }

  cout << cnt << endl;
}
 
int main() {
  freopen("input.txt","r",stdin);

  cin >> n >> m;
  for(int i = 1; i <= m; ++i) {
    int u,v; 
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }

  connected_components_dfs();
  connected_components_bfs();

}