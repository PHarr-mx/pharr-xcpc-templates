#include<bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using pii = pair<int, int>;
using seg = array<int, 5>;

#define lowbit(x) ( x & -x )

const int N = 1e7 + 5;

struct BinaryIndexedTree {...}; // 树状数组板子


int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<pii> a(n);
    for (auto &[x, y]: a)
        cin >> x >> y, x++, y++;
    vector<seg> p;
    for (int i = 0, xa, xb, ya, yb; i < m; i++) {
        cin >> xa >> ya >> xb >> yb;
        xa++, ya++, xb++, yb++;
        p.push_back(seg{xb, ya, yb, i, 1});
        p.push_back(seg{xa - 1, ya, yb, i, -1});
    }

    sort(p.begin(), p.end());
    sort(a.begin(), a.end());
    vi res(m);
    BinaryIndexedTree bit(N);
    for (int j = 0; const auto &it: p) {
        while (j < a.size() and a[j].first <= it[0])
            bit.update(a[j].second, 1), j++;
        res[it[3]] += it[4] * bit.calc(it[1], it[2]);
    }

    for (auto i: res)
        cout << i << "\n";
    return 0;
}