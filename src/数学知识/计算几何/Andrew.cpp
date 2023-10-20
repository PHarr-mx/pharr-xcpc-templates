// depends eq , lt , cross , V-V , P < P , len
using Points = vector<Point>;

bool check(Point p, Point q, Point r) { // 检查是向量旋转方向是否为逆时针
    return lt(0, (q - p) ^ (r - q));
}

Points chull(Points &ps) {
    sort(ps.begin(), ps.end());
    vector<int> I{0}, used(ps.size());

    for (int i = 1; i < ps.size(); i++) {
        while (I.size() > 1 and !check(ps[I[I.size() - 2]], ps[I.back()], ps[i]))
            used[I.back()] = 0, I.pop_back();
        used[i] = 1, I.push_back(i);
    }
    for (int i = ps.size() - 2, tmp = I.size(); i >= 0; i--) {
        if (used[i]) continue;
        while (I.size() > tmp and !check(ps[I[I.size() - 2]], ps[I.back()], ps[i]))
            I.pop_back();
        used[i] = 1, I.push_back(i);
    }
    Points H;
    I.pop_back();
    for (auto i: I)
        H.push_back(ps[i]);
    return H;
}