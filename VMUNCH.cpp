#include<bits/stdc++.h>
using namespace std;
int a[105][105];
int n, m, x, y, u, v;
bool visit[105][105];
int dis[105][105];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void bfs(){
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	visit[x][y] = 1;
	dis[x][y] = 0;
	while(!q.empty()){
		pair<int, int> p = q.front();
		q.pop();
		for(int i = 0; i < 4; i++){
			int l = p.first + dx[i];
			int r = p.second + dy[i];
			if(l >= 1 && l <= n && r >= 1 && r <= m && !visit[l][r] && a[l][r] == 1){
				dis[l][r] = dis[p.first][p.second] + 1;
				visit[l][r] = 1;
				q.push(make_pair(l, r));

			}
		}
	}
	if(!dis[u][v]) cout << -1;
	else cout << dis[u][v] << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++)
		{
			char ch;
			cin >> ch;
			if(ch == '.') a[i][j] = 1;
			else if(ch == 'C') {
				a[i][j] = 1;
				x = i;
				y = j;
			}
			else if(ch == 'B'){
				a[i][j] = 1;
			 	u = i;
			 	v = j;
			}
			else a[i][j] = 0;
		}
	}	

	bfs();

	return 0;
}