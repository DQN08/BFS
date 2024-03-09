#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int n, m, x, y, u, v;
bool vis[N][N];
int a[N][N];
int dx[] = {-1, 0, 1, 0};
int dy[] = { 0, 1, 0,-1};
char dir[] = {'U', 'R', 'D', 'L'};
int dis[N][N], trace[N][N];

void bfs() {
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    dis[x][y] = 0;
    vis[x][y] = true;
    while (!q.empty()) {
        pair<int, int> p = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            int r = p.first + dx[i];
            int c = p.second + dy[i];
            if (r >= 1 && r <= n && c >= 1 && c <= m && !vis[r][c] && a[r][c] == 1) {
                vis[r][c] = true;
                dis[r][c] = dis[p.first][p.second] + 1;
                q.push(make_pair(r, c));
                trace[r][c] = i;
                if (r == u && c == v) return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char c;
            cin >> c;
            if (c == 'A') {
                x = i; y = j;
                a[i][j] = 1;
            } else if (c == 'B') {
                u = i; v = j;
                a[i][j] = 1;
            } else if (c == '.') a[i][j] = 1;
            else a[i][j] = 0;
        }
    }

    bfs();
    if (dis[u][v] == 0) cout << "NO";
    else {
        cout << "YES\n" << dis[u][v] << "\n";
        string s = "";
        while (u != x || v != y) {
            s += dir[trace[u][v]];
            int uu = u, vv = v;
            u -= dx[trace[uu][vv]];
            v -= dy[trace[uu][vv]];
        }
        reverse(s.begin(), s.end());
        cout << s;
    }
    return 0;
}