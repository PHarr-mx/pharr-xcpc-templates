int calc(int a, int b, int m) {
    int x, y, d;
    d = exgcd(a, m, x, y);
    if (b % d) return -1;
    return x * b / d;
}