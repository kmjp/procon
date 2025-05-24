#include <bits/stdc++.h>
 
using namespace std;
 
int nimber(int x, int a) {
  int aprime = 0;
  bool goodbit = false;
  for (int bit=30; bit>=0; bit--) {
    if (x & (1 << bit)) {
      aprime *= 2;
      if (goodbit || (a & (1 << bit))) {
        aprime += 1;
      }
    } else if (a & (1 << bit)) {
      goodbit = true;
    }
  }
 cout<<aprime<<endl;
  // g(2^k - 2) = 0, for all k >= 1.
  for (int k=1; k<=30; k++) {
    if (aprime == (1 << k) - 2) {
      return 0;
    }
  }
 
  // g(2^k - 1) = k, for all k >= 1.
  for (int k=1; k<=30; k++) {
    if (aprime == (1 << k) - 1) {
      return k;
    }
  }
 
  // g(2^k) = k + (-1)^k, for all k >= 0.
  for (int k=1; k<=30; k++) {
    if (aprime == (1 << k)) {
      if (k % 2) return k - 1;
      else return k + 1;
    }
  }
 
  // g(2^k+1) = g(2^k+2) = ... = g(2^{k+1} - 3) = k + 1, for all k >= 2.
  for (int k=2; k<=30; k++) {
    if ((1 << k) < aprime && aprime <= (2 << k) - 3) {
      return k + 1;
    }
  }
 
  // should never get to this point
  assert(false);
  return -1;
}
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i=0; i<n; i++) cin >> A[i];
    vector<int> X(n);
    for (int i=0; i<n; i++) cin >> X[i];
    int curr = 0;
    for (int i=0; i<n; i++) curr ^= nimber(X[i], A[i]);
    cout << (curr ? "Alice" : "Bob") << "\n";
  }
  return 0;
}
