#include <iostream>
#include <stack>
#include <string>

using namespace std;

int pre(char s) {
  switch (s) {
    case '^':
      return 5;
    case '/':
      return 4;
    case '*':
      return 3;
    case '-':
      return 2;
    case '+':
      return 1;
    default:
      return 0;
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    string output;
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] >= 'a' && s[i] <= 'z') {
        output.push_back(s[i]);
      } else if (s[i] == '(') {
        st.push(s[i]);
      } else if (s[i] == ')') {
        while (st.top() != '(') {
          output.push_back(st.top());
          st.pop();
        }
        st.pop();
      } else {
        while (!st.empty() && pre(st.top()) > s[i]) {
          output.push_back(st.top());
          st.pop();
        }
        st.push(s[i]);
      }
    }
    while (!st.empty()) {
      output.push_back(st.top());
      st.pop();
    }
    cout << output << endl;
  }
  return 0;
}