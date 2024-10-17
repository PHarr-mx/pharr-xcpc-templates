long long power(long long x, long long y, long long p) {
    long long ans = 1;
    while (y) {
        if (y & 1) ans = (__int128) ans * x % p;
        x = (__int128) x * x % p, y /= 2;
    }
    return ans;
}

bool isPrime(long long x) {
    if (x < 2) return x == 2;
    if (x % 2 == 0) return false;
    vector<long long> A = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    long long d = x - 1, r = 0;
    while (d % 2 == 0) d /= 2, r++;
    for (auto a: A) {
        long long v = power(a, d, x);
        if (v <= 1 or v == x - 1) continue;
        for (int i = 0; i < r; i++) {
            v = (__int128) v * v % x;
            if (v == x - 1 and i != r - 1) {
                v = 1;
                break;
            }
            if (v == 1) return false;
        }
        if (v != 1) return false;
    }
    return true;
}