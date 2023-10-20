int qua(Point p) { // 求象限
    return lt(p.y, 0) << 1 | lt(p.x, 0) ^ lt(p.y, 0);
}

void psort(Points &ps, Point c = O) {
    sort(ps.begin(), ps.end(), [&](auto p1, auto p2) {
        return qua(p1-c) < qua(p2-c) || (qua(p1-c) == qua(p2-c) && lt((p1-c) ^ (p2-c), 0));
    });
}