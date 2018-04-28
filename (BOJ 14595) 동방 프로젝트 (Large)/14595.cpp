#include <iostream>
using namespace std;

int state[1000001];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    state[x]++;
    state[y]--;
  }

  int sum = 0, ans = n;
  for (int i = 1; i < n; i++) {
    sum += state[i];
    if (sum) ans--;
  }

  cout << ans;
  return 0;
}