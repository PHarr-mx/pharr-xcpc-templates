#include <bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = int64_t;

#define int i64

using vi = vector<i64>;
using pii = pair<i64, i64>;

const i64 mod = 1e9 + 7;
const i64 inf = 1e18;

struct matrix {
    static constexpr int mod = 1e9 + 7;
    int x, y;
    vector<vector<int>> v;

    matrix() {}

    matrix(int x, int y) : x(x), y(y) {
        v = vector<vector<int>>(x + 1, vector<int>(y + 1, 0));
    }

    void I() {// 单位化
        y = x;
        v = vector<vector<int>>(x + 1, vector<int>(x + 1, 0));
        for (int i = 1; i <= x; i++) v[i][i] = 1;
        return;
    }

    void display() { // 打印
        for (int i = 1; i <= x; i++)
            for (int j = 1; j <= y; j++)
                cout << v[i][j] << " \n"[j == y];
        return;
    }

    friend matrix operator*(const matrix &a, const matrix &b) { //乘法
        assert(a.y == b.x);
        matrix ans(a.x, b.y);
        for (int i = 1; i <= a.x; i++)
            for (int j = 1; j <= b.y; j++)
                for (int k = 1; k <= a.y; k++)
                    ans.v[i][j] = (ans.v[i][j] + a.v[i][k] * b.v[k][j]) % mod;
        return ans;
    }

    friend matrix operator^(matrix x, int y) { // 快速幂
        assert(x.x == x.y);
        matrix ans(x.x, x.y);
        ans.I();//注意一定要先单位化
        while (y) {
            if (y & 1) ans = ans * x;
            x = x * x, y >>= 1;
        }
        return ans;
    }
};

i32 main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    matrix f(n, n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> f.v[i][j];
    f = f ^ k;
    int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            res = (res + f.v[i][j]) % mod;
    cout << res << "\n";
    return 0;
}