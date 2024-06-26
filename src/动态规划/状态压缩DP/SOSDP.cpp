// 设维度为 n 维

// 子集
for(int j = 0; j < n; j ++)
    for(int i = 0; i < (1<<n); i ++)
        if(i & (1<<j)) f[i] += f[i ^ (1<<j)];

// 超集
for(int j = 0; j < n; j ++)
    for(int i = 0; i < (1<<n); i ++)
        if(not (i & (1<<j))) f[i] += f[i ^ (1<<j)];
