struct Basis {
    vector<ui64> B;
    bool zero, sorted;

    Basis() {
        B = vector<ui64>();
        zero = false, sorted = true;
    }

    void sort() {
        if (sorted) return;
        sorted = true;
        ranges::sort(B);
        return;
    }

    void insert(ui64 x) {
        for (auto b: B)
            x = min(x, b ^ x);
        if (x == 0) {
            zero = true;
            return;
        }
        for (auto &b: B)
            b = min(b, b ^ x);
        B.push_back(x), sorted = false;
        return;
    }

    int query(int kth = 1) { // query k-th smallest element
        sort();
        if (zero) kth--;
        ui64 ans = 0;
        for (auto b: B) {
            if (kth & 1) ans ^= b;
            kth >>= 1;
        }
        if (kth == 0) return ans;
        return -1;
    }

    ui64 max() {
        ui64 ans = 0;
        for (auto b: B)
            ans ^= b;
        return ans;
    }

    bool check(ui64 x) {
        for (auto b: B)
            x = min(x, b ^ x);
        return x == 0;
    }

    void merge(const Basis &oth) {
        for (auto x: oth.B)
            insert(x);
        return;
    }
};