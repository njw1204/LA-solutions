#include <iostream>
#include <queue>
#include <cstring>
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
using namespace std;


int N, M, K;
int mine[1001][1001];
bool visit[1001][1001];


int BFS(int D) {
  int cnt = 0;
  queue<pair<int, int>> Q;
  memset(visit, 0, sizeof(visit));

  for (int i = 1; i <= N; i++) {
    if (mine[i][1] <= D) {
      Q.push({i,1});
      visit[i][1] = true;
      cnt++;
    }
    if (M > 1 && mine[i][M] <= D) {
      Q.push({i,M});
      visit[i][M] = true;
      cnt++;
    }
  }

  for (int i = 2; i <= M - 1; i++) {
    if (mine[1][i] <= D) {
      Q.push({1,i});
      visit[1][i] = true;
      cnt++;
    }
  }

  while (!Q.empty()) {
    int dx[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    pair<int, int> now = Q.front();
    Q.pop();

    for (int i = 0; i < 4; i++) {
      if (now.first + dx[i][0] < 1 || now.first + dx[i][0] > N) continue;
      if (now.second + dx[i][1] < 1 || now.second + dx[i][1] > M) continue;
      if (visit[now.first + dx[i][0]][now.second + dx[i][1]]) continue;
      if (mine[now.first + dx[i][0]][now.second + dx[i][1]] > D) continue;

      Q.push({now.first + dx[i][0],now.second + dx[i][1]});
      visit[now.first + dx[i][0]][now.second + dx[i][1]] = true;
      cnt++;
    }
  }

  return cnt;
}


int main() {
  cin >> N >> M >> K;
  int max_weight = 0, min_weight = 99999999;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> mine[i][j];
      max_weight = MAX(max_weight, mine[i][j]);
      min_weight = MIN(min_weight, mine[i][j]);
    }
  }

  int left = min_weight, right = max_weight;

  while (left < right) {
    int mid = (left + right) / 2;
    if (BFS(mid) >= K) right = mid;
    else left = mid + 1;
  }

  cout << left;
  return 0;
}