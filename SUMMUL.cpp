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

void matrixMul(ll a[][2], ll b[][2]) {
  ll temp[2][2];
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      temp[i][j] = 0;
      for (int k = 0; k < 2; k++) {
        temp[i][j] = (temp[i][j] + ((a[i][k] * b[k][j]) % MOD)) % MOD;
      }
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      a[i][j] = temp[i][j];
    }
  }
}

ll temp[2][2];
ll mat[2][2];

void binMul(ll pow) {
  temp[0][0] = 1;
  temp[0][1] = 0;
  temp[1][0] = 0;
  temp[1][1] = 1;
  mat[0][0] = 1;
  mat[0][1] = 1;
  mat[1][0] = 1;
  mat[1][1] = 2;
  while (pow > 0) {
    if (pow & 1) {
      matrixMul(temp, mat);
    }
    matrixMul(mat, mat);
    pow /= 2;
  }
}

int main() {
  testcase {
    ll n;
    cin >> n;
    binMul(n - 1);
    ll a = temp[0][0] + 2 * temp[1][0];
    a = a % MOD;
    a -= n;
    if (a < 0) {
      a += MOD;
    }
    cout << a << nl;
  }
  return 0;
}
