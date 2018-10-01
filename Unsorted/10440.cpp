#include <cstdio>
#include <algorithm>
using namespace std;
 
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, t, m;
    scanf("%d%d%d", &n, &t, &m);
    int times[1999];
    for (int i = 0; i < m; i++) {
      scanf("%d", &times[i]);
    }
    sort(times, times + m);
    bool first = m % n;
    int carry = 0, time = 0, trip = 0;
    for (int i = 0; i < m; i++) {
      if (time <= times[i]) {
        time = times[i];
      }
      carry++;
      if (!first) {
        if (carry == n) {
          carry = 0;
          time += t + t;
          trip++;
        }
      } else if (carry == (m % n)) {
        first = false;
        carry = 0;
        time += t + t;
        trip++;
      }
    }
    printf("%d %d\n", time - t, trip);
  }
  return 0;
}