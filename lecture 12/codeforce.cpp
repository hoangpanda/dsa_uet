#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define all(x) begin(x),end(x)
#define pb push_back
#define pii pair<int,int>

const ll INF = 1e18;


void solve() {
  // for int i = 1 to n do 
}

int cal_cost(vector<int> a, int mid) {
  int cost = 0;

  // 1 2 3 4 5

  int n = a.size();
  for(int i = n / 2; i < n; ++i) {
    if(a[i] < mid) 
      cost += (mid - a[i]);
  }
  return cost;
}

int find(vector<int> diff, int k) {
  // find element >= k

  int start = 0;
  int end = diff.size() - 1;
  int mid;
  int n = diff.size() - 1;
  while(start <= end) {
    mid = (end + start) / 2;
    if(diff[mid] == k) return mid;
    else if(diff[mid] > k) end = mid - 1;
    else start = mid + 1;
  }
  while(mid - 1 > 0 && diff[mid-1] >= k) mid--;
  while(mid + 1 < n && diff[mid+1] < k) mid++;

  return mid;
}


signed main() {
  freopen("input.txt","r",stdin);
  //solve();

  int n; cin >> n;
  vector<int> a(n);
  vector<int> b(n);

  for(int i = 0; i < n; ++i) cin >> a[i];
  for(int i = 0; i < n; ++i) cin >> b[i];

  vector<int> diff(n);
  for(int i = 0; i < n; ++i) diff[i] = a[i] - b[i];

  sort(begin(diff), end(diff));

//  for(int v:diff) cout << v << ' '; cout << endl;

  int cnt = 0;

  for(int i = 0; i < n; ++i) {
    int k = a[i] - b[i];
    // find >= -k+1
    int index = find(diff, -k+1);
    cnt += (n - index);
    // if(diff[index] < k || (diff[index] == k && (diff[index-1] == k ||diff[index+1]==k))) 
    //   cout << k << ' ' << diff[index] << ' ' << n-index -1 << endl;
    // else 
      // cout << k << ' ' << diff[index] << ' ' << n-index << endl; 
    if(diff[index] < k || (diff[index] == k && (diff[index-1] == k ||diff[index+1]==k))) cnt--;
  }
 
  cout << cnt/2;

  return 0;
}