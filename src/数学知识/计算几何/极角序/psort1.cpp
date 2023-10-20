db theta(Vec v) {
    return atan2(v.y, v.x);
}

void psort(Points &ps, Point c = O) {
    sort(ps.begin(), ps.end(), [&](auto p1, auto p2) {
        return theta(p1 - c) < theta(p2 - c);
    });
}