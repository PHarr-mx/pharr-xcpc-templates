int BSGS(int a, int b, int p) {
    map<int, int> hash;
    b %= p;
    int t = sqrt(p) + 1;
    for (int j = 0, val; j < t; j++) {
        val = b * power(a, j, p) % p;
        hash[val] = j;
    }
    a = power(a, t, p);
    if (a == 0) return b == 0 ? 1 : -1;
    for (int i = 0, val, j; i <= t; i++) {
        val = power(a, i, p);
        j = hash.find(val) == hash.end() ? -1 : hash[val];
        if (j >= 0 && i * t - j >= 0) return i * t - j;
    }
    return -1;
}