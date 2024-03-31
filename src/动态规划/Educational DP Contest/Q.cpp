#include <bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = int64_t;

#define int i64

using vi = vector<i64>;
using pii = pair<i64, i64>;

const i64 mod = 1e9 + 7;
const i64 inf = 1e18;

struct BinaryIndexedTree {
#define lowbit(x) ( x & -x )
    int n;
    vector<int> b;

    BinaryIndexedTree(int n) : n(n), b(n + 1, 0) {};

    void update(int i, int y) {
        for (; i <= n; i += lowbit(i)) b[i] = max(b[i], y);
        return;
    }

    int calc(int i) {
        int ans = 0;
        for (; i; i -= lowbit(i)) ans = max(ans, b[i]);
        return ans;
    }
};

i32 main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vi h(n), a(n);
    for (int &i: h) cin >> i;
    for (int &i: a) cin >> i;
    int ans = 0;
    BinaryIndexedTree bit(n);
    for (int i = 0, tmp; i < n; i++) {
        tmp = bit.calc(h[i] - 1) + a[i];
        ans = max(ans, tmp);
        bit.update(h[i], tmp);
    }
    cout << ans << "\n";
    return 0;
}