#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int m, n, u, v, res = 0;
int a[N][N];
bool vis[N][N];

int dx[] = {-1, 0, 1, 0};
int dy[] = { 0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> n >> u >> v;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) cin >> a[i][j];
    }

    if (a[u][v] == 0) {
        cout << 0;
        return 0;
    }

    queue<pair<int, int> > q;
    q.push(make_pair(u, v));
    vis[u][v] = true;
    res = 1;
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int x = p.first + dx[i];
            int y = p.second + dy[i];
            if (x >= 1 && x <= m && y >= 1 && y <= n && !vis[x][y] && a[x][y] == 1) {
                ++res;
                vis[x][y] = true;
                q.push(make_pair(x, y));
            }
        }
    }
    cout << res;

    return 0;
}