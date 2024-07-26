struct Node {
    int l, r, value, square, add, mul;
    Node *left, *right;

    Node(int l, int r, int value, int square, Node *left, Node *right)
            : l(l), r(r), value(value), square(square), left(left), right(right) {
        add = 0, mul = 1;
    }
} *root;

Node *build(int l, int r, const vector<int> &v) {
    if (l == r) {
        return new Node(l, r, v[l], v[l] * v[l], nullptr, nullptr);
    }
    int mid = (l + r) / 2;
    Node *left = build(l, mid, v);
    Node *right = build(mid + 1, r, v);
    return new Node(l, r, left->value + right->value, left->square + right->square, left, right);
}

void markMul(int v, Node *cur) {
    cur->mul *= v;
    cur->add *= v;
    cur->value *= v;
    cur->square *= v * v;
    return;
}

void markAdd(int v, Node *cur) {
    cur->square += (cur->r - cur->l + 1) * v * v + 2 * v * cur->value;
    cur->value += v * (cur->r - cur->l + 1);
    cur->add += v;
    return;
}

void pushdown(Node *cur) {
    if (cur->mul != 1) {
        markMul(cur->mul, cur->left);
        markMul(cur->mul, cur->right);
        cur->mul = 1;
    }
    if (cur->add != 0) {
        markAdd(cur->add, cur->left);
        markAdd(cur->add, cur->right);
        cur->add = 0;
    }
    return;
}

int calcValue(int l, int r, Node *cur) {
    if (l > cur->r or r < cur->l) return 0;
    if (l <= cur->l and cur->r <= r) return cur->value;
    pushdown(cur);
    int mid = (cur->l + cur->r) / 2, sum = 0;
    if (l <= mid) sum += calcValue(l, r, cur->left);
    if (r > mid) sum += calcValue(l, r, cur->right);
    return sum;
}

int calcSquare(int l, int r, Node *cur) {
    if (l > cur->r or r < cur->l) return 0;
    if (l <= cur->l and cur->r <= r) return cur->square;
    pushdown(cur);
    int mid = (cur->l + cur->r) / 2, sum = 0;
    if (l <= mid) sum += calcSquare(l, r, cur->left);
    if (r > mid) sum += calcSquare(l, r, cur->right);
    return sum;
}

void modifyMul(int l, int r, int v, Node *cur) {
    if (l > cur->r or r < cur->l) return;
    if (l <= cur->l and cur->r <= r) {
        markMul(v, cur);
        return;
    }
    pushdown(cur);
    int mid = (cur->l + cur->r) / 2;
    if (l <= mid) modifyMul(l, r, v, cur->left);
    if (r > mid) modifyMul(l, r, v, cur->right);
    cur->value = cur->left->value + cur->right->value;
    cur->square = cur->left->square + cur->right->square;
    return;
}

void modifyAdd(int l, int r, int v, Node *cur) {
    if (l > cur->r or r < cur->l) return;
    if (l <= cur->l and cur->r <= r) {
        markAdd(v, cur);
        return;
    }
    pushdown(cur);
    int mid = (cur->l + cur->r) / 2;
    if (l <= mid) modifyAdd(l, r, v, cur->left);
    if (r > mid) modifyAdd(l, r, v, cur->right);
    cur->value = cur->left->value + cur->right->value;
    cur->square = cur->left->square + cur->right->square;
    return;
}