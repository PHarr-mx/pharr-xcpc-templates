// dp 时
// c[i] 是价格 ， w[i] 是价值
for(int i = 0 ; i < N ; i++) {
    for(int j = V ; j >= c[i] ; j++)
        if(f[j-c[i]]+w[i] > f[j]) {
            f[j] = f[j-c[i]]+w[i];
            path[i][j] = 1;
        }
}

// 输出方案

int i = N, j = V;
while(i > 0 && j > 0) {
    if(Path[i][j] == 1) {
        cout << c[i-1] << " ";
        j -= c[i-1];
    }
    i--;
}