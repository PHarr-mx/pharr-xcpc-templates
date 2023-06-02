struct Trie {
    struct node {
        vector<int> nxt;
        bool exist;
        char val;

        node(char val = '@') : nxt(26, -1), exist(false), val(val) {};
    };

    vector <node> t;

    Trie() : t(1, node()) {};

    void insert(string s) {
        int pos = 0;
        for (auto c: s) {
            int x = c - 'a';
            if (t[pos].nxt[x] == -1)
                t[pos].nxt[x] = t.size(), t.emplace_back(c);
            pos = t[pos].nxt[x];
        }
        return;
    }

    bool find(string s) {
        int pos = 0;
        for (auto c: s) {
            int x = c - 'a';
            if (t[pos].nxt[x] == -1) return false;
            pos = t[pos].nxt[x];
        }
        return t[pos].exist;
    }

};