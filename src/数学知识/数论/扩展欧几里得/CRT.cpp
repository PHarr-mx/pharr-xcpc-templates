int CRT(int n, vector<int> a, vector<int> m) {
    int mm = 1, ans = 0;
    for (int i = 1; i <= n; i++) mm = mm * m[i];
    for (int i = 1; i <= n; i++) {
        int M = mm / m[i], t, y;
        exgcd(M, m[i], t, y); // t * M % m[i] = 1;
        ans = (ans + a[i] * M * t % mm) % mm;
    }
    return ans;
}