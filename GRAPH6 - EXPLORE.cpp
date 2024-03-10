#include<bits/stdc++.h>
using namespace std;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool visit[1005][1005];
int dis[1005][1005];
int a[1005][1005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j =1 ; j  <= m; j++) cin >> a[i][j];
	}	
	
	queue<pair<int, int> > q;
	q.push(make_pair(1, 1));
	visit[1][1] = 1;
	dis[1][1] = 0;
	
	while(!q.empty()){
		pair<int, int> p = q.front();
		q.pop();
		for(int i = 0; i < 4; i++){
			int x = p.first + dx[i];
			int y = p.second + dy[i];
			if(x >= 1 && x <= n && y >= 1 && y <= m && !visit[x][y] && a[x][y] == 0){
				dis[x][y] = dis[p.first][p.second] + 1;
				visit[x][y] = 1;
				q.push(make_pair(x, y));
				if(x == n && y == m){

					cout << dis[x][y] - 1;
					return 0;
				}
			}
		}
	}
	
	if(!dis[n][m]) cout << -1 << '\n';
	return 0;
}