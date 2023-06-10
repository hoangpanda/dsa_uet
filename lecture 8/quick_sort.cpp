#include <bits/stdc++.h>
using namespace std;


void quick_sort(int a[], int start, int end) {
  int left = start;
  int right = end;
  int mid = a[(left+right)/2];

  while(left < right) {
    while(a[left] < mid) left++;
    while(a[right] > mid) right--;
    if(left <= right) {
      swap(a[left],a[right]);
      left++;
      right--;
    }
  }
  

  if(right > start) quick_sort(a,start,right);
  if(left < end) quick_sort(a,left,end);
}

int main() {
  int n; cin >> n;
  int a[n];
  for(int i = 0; i < n; ++i) 
    cin >> a[i];

  quick_sort(a,0,n-1);

  for(int i = 0; i < n; ++i)
    cout << a[i] << ' ';

  return 0;
}