// depends eq , lt , cross , V-V , P < P , len
using Points = vector<Point>;

db theta(Point p) { // 极角
    return p == O ? -1 / 0. : atan2(p.y, p.x);
}

void psort(Points &ps, Point c = O) { // 极角序,先按照极角排序,再按照距离排序
    sort(ps.begin(), ps.end(), [&](auto p1, auto p2) {
        auto t1 = theta(p1 - c), t2 = theta(p2 - c);
        if (eq(t1, t2)) return lt(len(p1 - c), len(p2 - c));
        return lt(t1, t2);
    });
}

bool check(Point p, Point q, Point r) { // 检查是向量旋转方向是否为逆时针
    return lt(0, (q - p) ^ (r - q));
}

Points chull(Points &ps) {
    psort(ps, *min_element(ps.begin(), ps.end()));
    Points H{ps[0]};
    for (int i = 1; i < ps.size(); i++) {
        while (H.size() > 1 and !check(H[H.size() - 2], H.back(), ps[i]))
            H.pop_back();
        H.push_back(ps[i]);
    }
    return H;
}