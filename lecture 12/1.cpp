#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) begin(x),end(x)
#define pb push_back
#define pii pair<int,int>

const ll INF = 1e18;
const int N = 1e5 + 100;
int n,m;
vector<int> adj[N];
vector<int> in(N,0);


void kahn() {
  queue<int> q;
  for(int i = 1; i <= n; ++i) {
    if(in[i] == 0) 
      q.push(i);
  } 

  vector<int> ans;

  while(!q.empty()) {
    int k = q.front();
    q.pop();
    ans.pb(k);


    for(auto v:adj[k]) {
      in[v]--;
      if(in[v] == 0) {
        q.push(v);
      }
    }
  }


  for(int v:ans)
    cout << v << ' ';
  cout << endl;
}

vector<int> topo;
vector<bool> visit(N,false);

void topo_sort(int start) {
  visit[start] = true;

  for(int v:adj[start])
    if(!visit[v]) 
      topo_sort(v);

  topo.push_back(start);
} 

void dfs() {
  for(int i = 1; i <= n; ++i)
    if(!visit[i]) 
      topo_sort(i);

  reverse(begin(topo), end(topo));
  for(auto v:topo) 
    cout << v << ' ';
  cout << endl;
} 


void solve() {
  cin >> n >> m;
  for(int i = 1; i <= m; ++i) {
    int u,v; cin >> u >> v;
    in[v]++;
    adj[u].push_back(v);
  }

  kahn();
  dfs();
}

int main() {
  freopen("input.txt","r",stdin);
  solve();
  return 0;
}