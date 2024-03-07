namespace Hash {// 下标从 1 开始
    using Val = pair<i64, i64>;
    const Val Mod(1e9 + 7, 1e9 + 9);
    const Val base(13331, 23333);
    vector <Val> p;

    Val operator+(Val a, Val b) {
        i64 c1 = a.first + b.first, c2 = a.second + b.second;
        if (c1 >= Mod.first) c1 -= Mod.first;
        if (c2 >= Mod.second) c2 -= Mod.second;
        return pair(c1, c2);
    }

    Val operator-(Val a, Val b) {
        i64 c1 = a.first - b.first, c2 = a.second - b.second;
        if (c1 < 0) c1 += Mod.first;
        if (c2 < 0) c2 += Mod.second;
        return pair(c1, c2);
    }

    Val operator*(Val a, Val b) {
        return pair(a.first * b.first % Mod.first, a.second * b.second % Mod.second);
    }

    void init(int n) {
        p.resize(n + 1), p[0] = pair(1, 1);
        for (int i = 1; i <= n; i++) p[i] = p[i - 1] * base;
        return;
    }

    struct Hash {
        vector <Val> h;

        Hash(const string &s) {
            h.resize(s.size() + 1);
            for (int i = 1; i <= s.size(); i++)
                h[i] = h[i - 1] * base + pair(s[i - 1], s[i - 1]);
            return;
        }

        Val getHash(int l, int r) {
            if (l > r) return pair(0, 0);
            return h[r] - h[l - 1] * p[r - l + 1];
        }

        Val val() {
            return h.back();
        }
    };
}