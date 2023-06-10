#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) begin(x),end(x)
#define pb push_back
#define pii pair<int,int>

const ll INF = 1e18;

int sum(int n) {
  return n*(n+1)/2;
}

int cnt_divisor(int n) {
  int cnt = 0;
  for(int i = 1; i <= sqrt(n); ++i) {
    if(n % i == 0) {
      if(i != n/i) cnt += 2;
      else cnt++;
    }
  }
  return cnt;
}

int term_cal(int n) {
  int cnt = 0;
  while(n != 1) {
    if(n % 2 == 0) n/=2;
    else n = 3*n+1;
    cnt++;
  }
  return cnt;
}

int isprime(int n) {
  if(n < 2) return false;

  for(int i = 2; i <= sqrt(n); ++i) {
    if(n % i == 0) return false;
  }
  return true;
} 



int run(int i, int j) {
  int cnt = 0;
  for(int k = 0; k <= 1e5; ++k) {
    int v = k*k + i*k + j;
    if(isprime(v)) cnt++;
    else return cnt;
  }
}


int sq5(int n) {
  return n*n*n*n*n;
}

int check(int n) {
  int num = n;
  int sum = 0;
  while(num != 0) {
    sum += sq5(num % 10);
    num /= 10;
  }
  return n == sum;
}

vector<int> f(20);

bool ok(int n) {
  if(!isprime(n)) return false;
  vector<int> v;

  while(n != 0) {
    v.push_back(n % 10);
    n/= 10;
  }

  do {
    int sum = 0;
    for(auto num:v) 
      sum = sum * 10 + num;
   // cout << sum << endl;
    //if(!isprime(sum)) return false;
  } while(next_permutation(v.begin(), v.end()));

  return true;
}

int main() {
 // freopen("input.txt","r",stdin);
  
  int cnt = 0;
  for(int i = 2; i <= 1e6 - 1; ++i) 
    if(ok(i)) {
      cout << i << endl;
      cnt++;
    }

 
  cout << cnt;

  return 0;
}