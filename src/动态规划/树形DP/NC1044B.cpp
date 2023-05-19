// NC1044B
void dp(int x) {
    f[x][0] = 0;
    for (auto y: e[x]) {
        dp(y);
        for (int i = m; i >= 0; i--)// 枚举当前节点最大可用背包容积
            for (int j = i; j >= 0; j--)//枚举当子节点最大可用背包容积
                f[x][i] = max(f[x][i], f[x][i - j] + f[y][j]);
    }
    // 这里要给每种容积都加上他本身的权值。
    for (int i = m; x != 0 && i > 0; i--) f[x][i] = f[x][i-1]+val[x];
    return;
}