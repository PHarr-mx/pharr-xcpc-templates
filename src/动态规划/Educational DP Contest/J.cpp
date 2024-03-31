#include <bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = long long;
using ldb = long double;

#define int long long

using vi = vector<int>;
using pii = pair<int, int>;

const int inf = 1e9;
const int N = 301;
const ldb eps = 1e-6;

ldb f[N][N][N];
int n;

ldb calc(int a, int b, int c) {
    if (a == 0 and b == 0 and c == 0) return 0;
    if (f[a][b][c] >= eps) return f[a][b][c];
    ldb q = a + b + c;
    f[a][b][c] = (ldb) n / q;
    if (a > 0) f[a][b][c] += (ldb) a / q * calc(a - 1, b, c);
    if (b > 0) f[a][b][c] += (ldb) b / q * calc(a + 1, b - 1, c);
    if (c > 0) f[a][b][c] += (ldb) c / q * calc(a, b + 1, c - 1);
    return f[a][b][c];
}

i32 main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    int a = 0, b = 0, c = 0;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        if (x == 1) a++;
        else if (x == 2) b++;
        else c++;
    }
    cout << fixed << setprecision(20)<< calc(a,b,c) << "\n";
    return 0;
}