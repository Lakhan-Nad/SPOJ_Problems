#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int p = 5;
    long long int mul = 1;
    long long int count = 0;
    while (n / p != 0) {
      count += (n / p - n / (p * 5)) * mul;
      mul += 1;
      p *= 5;
    }
    cout << count << endl;
  }
  return 0;
}