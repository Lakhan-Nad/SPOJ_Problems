#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    int x;
    bool flag;
    for (int i = a; i <= b; i++) {
      if (i == 1) {
        continue;
      }
      x = sqrt(i);
      flag = true;
      for (int j = 2; j <= x; j++) {
        if (i % j == 0) {
          flag = false;
          break;
        }
      }
      if (flag) {
        cout << i << endl;
      }
    }
    cout << endl;
  }
  return 0;
}