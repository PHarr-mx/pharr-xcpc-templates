# include <fstream>

// 流对象
ifstream  fin; // 读入
ofstream fout; // 输出

// 打开
ifstream fin("a.in");
fin.open("a.in");

// 关闭
fin.open();

// 检测 EOF 到达结尾返回非 0 值
fin.eof();

