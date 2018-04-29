#include <iostream>
using namespace std;

class Fenwick {
private:
  static const int height = 5000, width = 5000;
  static long long arr[height][width];
  
public:
  void add(int h, int w, long long x) {
    for (int i = h; i < height + 2; i += i & -i)
      for (int j = w; j < width + 2; j += j & -j)
        arr[i][j] += x;
  }

  long long sum(int h, int w) {
    long long s = 0;
    for (int i = h; i > 0; i -= i & -i)
      for (int j = w; j > 0; j -= j & -j)
        s += arr[i][j];
    return s;
  }
};

long long Fenwick::arr[height][width] = {};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  Fenwick farm;
  int n, m, q;
  cin >> n >> m >> q;

  for (int i = 0; i < q; i++) {
    int op;
    cin >> op;
    if (op == 1) {
      int x1, y1, x2, y2, d;
      cin >> x1 >> y1 >> x2 >> y2 >> d;
      farm.add(x1, y1, d);
      farm.add(x2 + 1, y1, -d);
      farm.add(x1, y2 + 1, -d);
      farm.add(x2 + 1, y2 + 1, d);
    }
    else {
      int x, y;
      cin >> x >> y;
      cout << farm.sum(x, y) << '\n';
    }
  }

  return 0;
}