#include <iostream>
using namespace std;
#define MOD 10000

int dp[101][4][3];
int fix[101];

void SetDP(int day) {
  for (int i = 1; i <= 3; i++) {
    if (fix[day] && i != fix[day])
      continue;
    for (int j = 1; j <= 3; j++) {
      if (i == j)
        dp[day][i][2] = dp[day - 1][j][1];
      else {
        dp[day][i][1] += dp[day - 1][j][1] + dp[day - 1][j][2];
        dp[day][i][1] %= MOD;
      }
    }
  }
}

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    int day, kind;
    cin >> day >> kind;
    fix[day] = kind;
  }

  if (fix[1])
    dp[1][fix[1]][1] = 1;
  else {
    dp[1][1][1] = 1;
    dp[1][2][1] = 1;
    dp[1][3][1] = 1;
  }

  for (int day = 2; day <= n; day++)
    SetDP(day);

  cout << (dp[n][1][1] + dp[n][1][2] + dp[n][2][1] + dp[n][2][2] + dp[n][3][1] + dp[n][3][2]) % MOD;
  return 0;
}