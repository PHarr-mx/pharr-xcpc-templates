/* 板子来自 Pecco 采取以下原则
 * 写全局函数，而非类方法，结构体只存储数据
 * 每个函数标注以来那些函数，且尽量减少依赖
 * 用较为简略的名字，同时传值而非 const 引用
 * */

#define mp make_pair
using db = double; //精度不够时可换 long double
// 几何对象
struct Point {// 点
    db x, y;

    Point(db x = 0, db y = 0) : x(x), y(y) {};
};

using Vec = Point;// 向量
struct Line { // 直线 (点向式)
    Point P;
    Vec v;

    Line(Point P, Vec v) : P(P), v(v) {};
};

struct Seg { // 线段(存两个端点)
    Point A, B;

    Seg(Point A, Point B) : A(A), B(B) {};
};

struct Circle { // 圆(存圆心和半径)
    Point O;
    db r;

    Circle(Point O, db r) : O(O), r(r) {};
};

// 常用常量
const Point O(0, 0); // 原点
const Line Ox(O, Vec(1, 0)), Oy(O, Vec(0, 1));// 坐标轴
const double pi = M_PI, eps = 1e-9;// pi 精度最高的是acosl(-1)

// 浮点比较
bool eq(db a, db b) { return abs(a - b) < eps; }// ==
bool gt(db a, db b) { return a - b > eps; }     // >
bool lt(db a, db b) { return a - b < -eps; }    // <
bool ge(db a, db b) { return a - b > -eps; }    // >=
bool le(db a, db b) { return a - b < eps; }     // <=

// 基础操作
Vec r90a(Vec v) { return Vec(-v.y, v.x); }// 顺时针旋转 90 度
Vec r90c(Vec v) { return Vec(v.y, -v.x); }// 逆时针旋转 90 度
// 向量加法
Vec operator+(Vec u, Vec v) { return Vec(u.x + v.x, u.y + v.y); }

// 向量减法
Vec operator-(Vec u, Vec v) { return Vec(u.x - v.x, u.y - v.y); }

// 数乘
Vec operator*(db k, Vec v) { return Vec(k * v.x, k * v.y); }

// 点乘
db operator*(Vec u, Vec v) { return u.x * v.x + u.y * v.y; }

// 叉乘
db operator^(Vec u, Vec v) { return u.x * v.y - u.y * v.x; }

db len(Vec v) { return sqrt(v.x * v.x + v.y * v.y); }// 向量长度
db slope(Vec v) { return v.y / v.x; }// 斜率

// 向量相关
// 两向量夹角余弦 u->v depends len,V*V
double cos_t(Vec u, Vec v) { return u * v / len(u) / len(v); }

//单位化 depends len
Vec norm(Vec v) { return Vec(v.x / len(v), v.y / len(v)); }

// 与原向量平行且横坐标大于等于 0 的单位向量 depends k*V , len , norm;
Vec pnorm(Vec v) {
    return (v.x < 0 ? -1 : 1) * norm(v);
    return (v.x < 0 ? -1 : 1) / len(v) * v;// 不依赖 norm
}

// 线段的方向向量 depends V-V // 直线的方向向量直接访问 v
Vec dvec(Seg l) { return l.B - l.A; }

// 直线相关
// 两点式求直线 depends V-V
Line line(Point A, Point B) { return Line(A, B - A); }

// 斜截式求直线
Line line(db k, db b) { return Line(Point(0, b), Vec(1, k)); }

// 点斜式求直线
Line line(Point P, db k) { return Line(P, Vec(1, k)); }

// 线段所在直线 depends V-V
Line line(Seg l) { return Line(l.A, l.B - l.A); }

db at_x(Line l, db x) {// 给定直线的横坐标求纵坐标
    assert(l.v.x != 0);
    return l.P.y + (x - l.P.x) * l.v.y / l.v.x;
}
db at_y(Line l, db y) {// 给定直线的纵坐标求横坐标
    assert(l.v.y != 0);
    return l.P.x + (y - l.P.y) * l.v.x / l.v.y;
}

Point pedal(Point P, Line l) {// 点到直线的垂足 depends V-V, V*V, d*V
    return l.P - (l.P - P) * l.v / (l.v * l.v) * l.v;
}

// 过某点作直线的垂线 depends r90c
Line perp(Line l, Point P) { return Line(P, r90c(l.v)); }

Line bisec(Point P, Vec u, Vec v) {// 角平分线 depends V+V, len, norm
    return Line(P, norm(u) + norm(v));
}

// 线段相关
Point midp(Seg l) { // 线段中点
    return Point((l.A.x + l.B.x) / 2, (l.A.y + l.B.y) / 2);
}
Line perp(Seg l) { // 线段中垂线 depends r90c, V-V, midp
    return Line(midp(l), r90c(l.B - l.A));
}

// 几何对象之间的关系
// 向量是否垂直 depends eq, V*V
bool verti(Vec u, Vec v) { return eq(u * v, 0); }

// 向量是否平行 depends eq, V^V
bool paral(Vec u, Vec v) { return eq(u ^ v, 0); }

// 向量是否与x轴平行 depends eq
bool paral_x(Vec v) { return eq(v.y, 0); }

// 向量是否与y轴平行 depends eq
bool paral_y(Vec v) { return eq(v.x, 0); }

bool on(Point P, Line l) {// 点是否在直线上 depends eq
    return eq((P.x - l.P.x) * l.v.y, (P.y - l.P.y) * l.v.x);
}

bool on(Point P, Seg l) { // 点是否在线段上 depends eq, len, V-V
    return eq(len(P - l.A) + len(P - l.B), len(l.A - l.B));
}

bool operator==(Point A, Point B) { // 两点是否重合 depends eq
    return eq(A.x, B.x) and eq(A.y, B.y);
}

bool operator==(Line a, Line b) { // 两条直线是否重合 depends eq,on(L)
    return on(a.P, b) and on(a.P + a.v, b);
}

bool operator==(Seg a, Seg b) { // 两条线段是否重合 depends eq, P==P
    return (a.A == b.A and a.B == b.B) or (a.A == b.B and a.B == b.A);
}

// 以横坐标为第一关键字、纵坐标为第二关键字比较两个点 depends eq, lt
bool operator<(Point A, Point B) {
    return lt(A.x, B.x) or (eq(A.x, B.x) and lt(A.y, B.y));
}

// 直线与圆是否相切 depends eq, V^V, len
bool tangency(Line l, Circle c) {
    return eq(abs((c.O ^ l.v) - (l.P ^ l.v)), c.r * len(l.v));
}

// 圆与圆是否相切 depends eq, V-V, len
bool tangency(Circle C1, Circle C2) {
    return eq(len(C1.O - C2.O), C1.r + C2.r);
}

// 距离
// 两点之间的距离 depends len, V-V
db dis(Point A, Point B) { return len(A - B); }

// 点到直线的距离 depends V^V, len
db dis(Point P, Line l) {
    return abs((P ^ l.v) - (l.P ^ l.v)) / len(l.v);
}

// 平行直线间的距离 depends d*V, V^V, len, pnrom
db dis(Line a, Line b) {
    assert(paral(a.v, b.v));
    return abs((a.P ^ pnorm(a.v)) - (b.P ^ pnorm(b.v)));
}

// 平移和旋转
// 平移 depends V+V
Line operator+(Line l, Vec v) { return Line(l.P + v, l.v); }
Seg operator+(Seg l, Vec v) { return Seg(l.A + v, l.B + v); }

// 旋转 depends V+V, V-V
Point rotate(Point P, db rad) {
    return Point(cos(rad)*P.x-sin(rad)*P.y,sin(rad)*P.x+cos(rad)*P.y);
}
Point rotate(Point P, db rad, Point C) {
    return C + rotate(P - C, rad);
}

Line rotate(Line l, db rad, Point C = O) {
    return Line(rotate(l.P, rad, C), rotate(l.v, rad));
}

Seg rotate(Seg l, db rad, Point C = O) {
    return Seg(rotate(l.A, rad, C), rotate(l.B, rad, C));
}

// 对称
// 关于点的对称
Point reflect(Point A, Point P) {
    return Point(P.x * 2 - A.x, P.y * 2 - A.y);
}

Line reflect(Line l, Point P) { return Line(reflect(l.P, P), l.v); }

Seg reflect(Seg l, Point P) {
    return Seg(reflect(l.A, P), reflect(l.B, P));
}

// 关于直线对称 depends V-V, V*V, d*V , pedal
Point reflect(Point A, Line ax) { return reflect(A, pedal(A, ax)); }

Vec reflect_v(Vec v, Line ax) {
    return reflect(v, ax) - reflect(O, ax);
}

Line reflect(Line l, Line ax) {
    return Line(reflect(l.P, ax), reflect_v(l.v, ax));
}

Seg reflect(Seg l, Line ax) {
    return Seg(reflect(l.A, ax), reflect(l.B, ax));
}
// 交点
// 直线与直线交点 depends eq, d*V, V*V, V+V, V^V
vector <Point> inter(Line a, Line b) {
    vector <Point> ans;
    double c = a.v ^ b.v;
    if (eq(c, 0)) return ans;
    Vec v = 1 / c * Vec(a.P ^ (a.P + a.v), b.P ^ (b.P + b.v));
    ans.emplace_back(v * Vec(-b.v.x, a.v.x), v * Vec(-b.v.y, a.v.y));
    return ans;
}

// 直线与圆交点 depends eg, gt, V+V, V-V, V*V, d*V, len, pedal
vector <Point> inter(Line l, Circle C) {
    vector <Point> ans;
    Point P = pedal(C.O, l);
    double h = len(P - C.O);
    if (gt(h, C.r)) return ans;
    if (eq(h, C.r)) {
        ans.emplace_back(P);
        return ans;
    }
    double d = sqrt(C.r * C.r - h * h);
    Vec vec = d / len(l.v) * l.v;
    ans.emplace_back(P + vec);
    ans.emplace_back(P - vec);
    return ans;
}

// 圆与圆的交点 depends eq, gt, V+V, V-V, d*V, len , r90c
vector <Point> inter(Circle C1, Circle C2) {
    vector <Point> ans;
    Vec v1 = C2.O - C1.O, v2 = r90c(v1);
    double d = len(v1);
    if (gt(d, C1.r + C2.r) || gt(abs(C1.r - C2.r), d)) return ans;
    if (eq(d, C1.r + C2.r) || eq(d, abs(C1.r - C2.r))) {
        ans.emplace_back(C1.O + C1.r / d * v1);
        return ans;
    }
    double a = ((C1.r * C1.r - C2.r * C2.r) / d + d) / 2;
    double h = sqrt(C1.r * C1.r - a * a);
    Vec av = a / len(v1) * v1, hv = h / len(v2) * v2;
    ans.emplace_back(C1.O + av + hv),ans.emplace_back(C1.O + av - hv);
    return ans;
}

// 三角形的四心
// 三角形重心
Point baryCenter(Point A, Point B, Point C) {
    return Point((A.x + B.x + C.x) / 3, (A.y + B.y + C.y) / 3);
}

// 三角形外心 depends r90c, V*V, d*V, V-V, V+V
// 给定三点求圆，要先判断是否三点共线
Point circumCenter(Point A, Point B, Point C) {
    double a = A * A, b = B * B, c = C * C;
    double d = 2 * (A.x*(B.y-C.y) + B.x*(C.y-A.y) + C.x*(A.y-B.y));
    return 1 / d * r90c(a * (B - C) + b * (C - A) + c * (A - B));
}

// 三角形内心 depends len, d*V, V-V, V+V
Point inCenter(Point A, Point B, Point C) {
    double a = len(B - C), b = len(A - C), c = len(A - B);
    double d = a + b + c;
    return 1 / d * (a * A + b * B + c * C);
}

// 三角形垂心 depends V*V, d*V, V-V, V^V, r90c
Point orthoCenter(Point A, Point B, Point C) {
    double n = B * (A - C), m = A * (B - C);
    double d = (B - C) ^ (A - C);
    return 1 / d * r90c(n * (C - B) - m * (C - A));
}

// 两圆相交的面积 depends V-V, dis
ldb areaInter(Circle c1, Circle c2) {
    ldb d = dis(c1.o, c2.o);
    auto &r1 = c1.r, r2 = c2.r;
    if (d >= r1 + r2) return 0.0;
    if (r1 + d <= r2) return Pi * r1 * r1;
    if (r2 + d <= r1) return Pi * r2 * r2;
    ldb ans = 0;

    ldb ang1 = acosl((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d));
    ans += ang1 * r1 * r1;
    ans -= r1 * sinl(ang1) * r1 * cosl(ang1);

    ldb ang2 = acosl((r2 * r2 + d * d - r1 * r1) / (2 * r2 * d));
    ans += ang2 * r2 * r2;
    ans -= r2 * sinl(ang2) * r2 * cosl(ang2);
    return ans;
}