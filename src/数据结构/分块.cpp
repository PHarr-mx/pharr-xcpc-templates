// https://loj.ac/p/6280
#include <bits/stdc++.h>
using namespace std;
#define int long long

int read() {...}
class decompose {
private:
    struct block {
        int l, r, sum, tag;// tag是单点修改时的懒惰标记
        vector<int> val;

        block(int l, int r) : l(l), r(r) {
            sum = tag = 0;
            val = vector<int>();
        }
    };
    int len;
    vector<block> part;
    vector<int> pos;
public:
    decompose(vector<int> &v) {
        len = v.size();
        int t = sqrt(len);
        pos = vector<int>(len + 1);
        for (int i = 1; i <= t; i++) // 预处理区间信息
            part.emplace_back((i - 1) * t + 1, i * t);
        if (part.back().r < len) // 处理结尾零散部分
            part.emplace_back(part.back().r + 1, len);
        for (int i = 1, j = 0; i <= len; i++) {
            if (i > part[j].r) j++;
            part[j].val.emplace_back(v[i - 1]);
            part[j].sum += v[i - 1], pos[i] = j;
        }
    }

    int getSum(int l, int r) {
        int sum = 0;
        for (int i = pos[l]; i <= pos[r]; i++) {
            if (part[i].l >= l && part[i].r <= r) sum += part[i].sum;
            else
                for( auto j = max(l, part[i].l) - part[i].l; j <= min(r, part[i].r) - part[i].l ; j++ )
                    sum += part[i].val[j] + part[i].tag;
        }
        return sum;
    }

    void update(int l, int r, int d) {
        for (int i = pos[l]; i <= pos[r]; i++) {
            if (part[i].l >= l && part[i].r <= r){
                part[i].tag += d;
                part[i].sum += part[i].val.size() * d;
            }
            else
                for (int j = max(l, part[i].l) - part[i].l; j <= min(r, part[i].r) - part[i].l; j++)
                    part[i].val[j] += d, part[i].sum += d;
        }
    }
};


int32_t main() {
    int n = read();
    vector<int> a(n);
    for (auto &i: a) i = read();
    decompose p(a);
    for (int opt, l, r, c, sum; n; n--) {
        opt = read(), l = read(), r = read(), c = read();
        if (opt == 0)
            p.update(l, r, c);
        else {
            c++, sum = p.getSum(l, r), sum = (sum % c + c) % c;
            printf("%lld\n", sum);
        }
    }
    return 0;
}