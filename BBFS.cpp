#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, m, s;
bool vis[N];
vector<int> adj[N];
int dis[N];
vector<pair<int, int> > a;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> s;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    q.push(s);
    vis[s] = true;
    dis[s] = 0;
    a.push_back(make_pair(dis[s], s));
    while (!q.empty()) {
        int p = q.front(); q.pop();
        for (int i = 0; i < adj[p].size(); ++i) {
            int v = adj[p][i];
            if (!vis[v]) {
                vis[v] = true;
                dis[v] = dis[p] + 1;
                a.push_back(make_pair(dis[v], v));
                q.push(v);
            }
        }
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); ++i) cout << a[i].second << " " << a[i].first << "\n";

    return 0;
}