struct mint {
    int x;

    mint(int x = 0) : x(x) {}

    mint &operator=(int o) { return x = o, *this; }

    mint &operator+=(mint o) { return (x += o.x) >= mod && (x -= mod), *this; }

    mint &operator-=(mint o) { return (x -= o.x) < 0 && (x += mod), *this; }

    mint &operator*=(mint o) { return x = (i64) x * o.x % mod, *this; }

    mint &operator^=(int b) {
        mint w = *this;
        mint ret(1);
        for (; b; b >>= 1, w *= w) if (b & 1) ret *= w;
        return x = ret.x, *this;
    }

    mint &operator/=(mint o) { return *this *= (o ^= (mod - 2)); }

    friend mint operator+(mint a, mint b) { return a += b; }

    friend mint operator-(mint a, mint b) { return a -= b; }

    friend mint operator*(mint a, mint b) { return a *= b; }

    friend mint operator/(mint a, mint b) { return a /= b; }

    friend mint operator^(mint a, int b) { return a ^= b; }
};
