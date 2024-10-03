#include <bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = long long;
using vi = vector<int>;
using pii = pair<int,int>;

i32 main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    mt19937_64 rd(time(0));
    int n;
    cin >> n;
    map<i32,i64> val;
    vector<int> a(n + 1);
    set<int> vis;
    for(int i = 1, x; i <= n; i ++) {
        cin >> x;
        if(val.count(x) == 0) val[x] = rd();
        if(vis.insert(x).second == true) a[i] = val[x];
        a[i] ^= a[i - 1];
    }

    vector<int> b(n + 1);
    vis.clear();
    for(int i = 1, x; i <= n; i ++) {
        cin >> x;
        if(val.count(x) == 0) val[x] = rd();
        if(vis.insert(x).second == true) b[i] = val[x];
        b[i] ^= b[i - 1];
    }

    int q;
    cin >> q;
    for(int x, y; q; q --) {
        cin >> x >> y;
        if(a[x] == b[y]) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}