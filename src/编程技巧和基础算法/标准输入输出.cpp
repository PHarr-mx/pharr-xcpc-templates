// 设置输出宽度为 x
cout << setw(x) << val;

// 设置保留小数位数 x , 并四舍五入
cout << fixd<< setprecision(x) << val;

//按进制输出
cout << bitset<10>(i); // 二进制
cout << oct << i; // 八进制
cout << dec << i; // 十进制
cout << hex << i; // 十六进制

// 设置填充符
cout << setw(10) << 1234; // 默认是空格
cout << setw(10) << setfill('0') << 1234; // 设置填充符
//左侧填充
cout<<setw(10)<<setfill('0')<<setiosflags(ios::left)<<123;
//右侧填充
cout<<setw(10)<<setfill('0')<<setiosflags(ios::right)<<123;

// 单个字符
ch = cin.get();
cout.put(ch);

// 指定长度字符串读入
cout.get(str,80,'a');// 字符串 字符个数 终止字符

// 整行读入
getlin( cin , s );
