int inv(int a, int m) {
    int x, y, d;
    d = exgcd(a, m, x, y);
    if (d != 1) return -1;
    return (x % m + m) % m;
}