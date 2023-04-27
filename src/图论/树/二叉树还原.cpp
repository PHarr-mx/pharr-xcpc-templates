struct Node {
    int v;
    Node *l, *r;
    Node(int v, Node *l, Node *r) : v(v), l(l), r(r) {};
};
// 根据中序、后序还原二叉树
Node *build(vector<int> mid, vector<int> suf) {
    int v = suf.back();
    Node *l = nullptr, *r = nullptr;
    int t;
    for (t = 0; t < mid.size(); t++)
        if (mid[t] == v) break;
    auto midll = mid.begin();
    auto midlr = mid.begin() + t;
    auto midrl = mid.begin() + t + 1;
    auto midrr = mid.end();
    auto sufll = suf.begin();
    auto suflr = suf.begin() + t;
    auto sufrl = suf.begin() + t;
    auto sufrr = suf.end() - 1;

    auto midl = vector<int>(midll, midlr);
    auto midr = vector<int>(midrl, midrr);
    auto sufl = vector<int>(sufll, suflr);
    auto sufr = vector<int>(sufrl, sufrr);

    if (!midl.empty()) l = build(midl, sufl);
    if (!midr.empty()) r = build(midr, sufr);

    return new Node(v, l, r);
}