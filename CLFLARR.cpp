#include <stdio.h>

#include <iostream>
using namespace std;

#define MOD 1000000007
#define nl '\n'
#define fio                         \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)
#define ll long long
#define testcase   \
  int t;           \
  scanf("%d", &t); \
  for (int test = 0; test < t; test++)

int main() {
  fio;
  ll n, q;
  cin >> n >> q;
  ll next[n];
  ll value[n];
  ll query[q][3];
  for (ll i = 0; i < n; i++) {
    value[i] = 0;
    next[i] = i + 1;
  }
  for (ll i = 0; i < q; i++) {
    cin >> query[i][0] >> query[i][1] >> query[i][2];
  }
  for (ll i = q - 1; i >= 0; i--) {
    ll left = query[i][0] - 1;
    ll right = query[i][1] - 1;

    while (left <= right) {
      if (value[left] == 0) {
        if (left != 0) {
          next[left - 1] = right + 1;
        }
        value[left] = query[i][2];
      }
      left = next[left];
    }
  }
  for (ll i = 0; i < n; i++) {
    cout << value[i] << nl;
  }
  return 0;
}
