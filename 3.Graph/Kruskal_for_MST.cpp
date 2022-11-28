#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
using pii = pair<int, int>;
 
constexpr int N = 1e5 + 5;
// n^2 + m, Prim
// mlog(m), Kruskal
int fa[N];
 
int get(int x) {
    return fa[x] == x ? x : (fa[x] = get(fa[x]));
}
 
void run() {
    for (int i = 0; i < N; i++)
        fa[i] = i;
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edge;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge.emplace_back(w, u, v);
    }
    sort(edge.begin(), edge.end());
    int cc = n;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        // auto [w, u, v] = edge[i];
        int w = get<0>(edge[i]);
        int u = get<1>(edge[i]);
        int v = get<2>(edge[i]);
        int tx = get(u), ty = get(v);
        if (tx != ty) {
            fa[tx] = ty;
            cc--;
            ans = max(w, ans);
        }
    }
    if (cc == 1) {
        cout << ans << "\n";
    } else {
        cout << "Failure\n";
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
        run();
    
    return 0;
} 