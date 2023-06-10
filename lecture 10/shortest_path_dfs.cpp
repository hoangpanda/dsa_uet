#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 100;
vector<int> a[N];
vector<bool> vis(N,false);
vector<int> dis(N,1e9);
int n,m; 

void dfs(int start, int end) {
  queue<int> q;
  q.push(start);
  vis[start] = 1;
  dis[start] = 0;

  while(!q.empty()) {
    int k = q.front();
    q.pop();

    for(auto v:a[k]) 
      if(!vis[v]) {
        dis[v] = dis[k] + 1;
        vis[v] = true;
        q.push(v);
        if(v == end) {
          return;
        }
      }
  }
}

int shortest_path(int x, int y) {
  dfs(x,y);

  return dis[y];
}

 
int main() {
  freopen("input.txt","r",stdin);

  cin >> n >> m;
  int x,y; cin >> x >> y;
  for(int i = 1; i <= m; ++i) {
    int u,v; 
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }

  cout << shortest_path(x,y);

}