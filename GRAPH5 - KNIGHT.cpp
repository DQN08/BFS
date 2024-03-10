#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int> > vec;
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int dis[1005][1005];
bool visit[1005][1005];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int x, y, n, m, k;

	cin >> n >> m >> k >> x >> y;	
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	visit[x][y] = 1;
	dis[x][y]=k;
	vec.push_back(make_pair(x, y));

	while(!q.empty()){
		pair<int, int> p = q.front();
		q.pop();
		for(int i = 0; i < 8; i++){
			int x = p.first + dx[i];
			int y = p.second + dy[i];
			if(x >= 1 && x <= n && y >= 1 && y <= m && !visit[x][y]&& dis[p.first][p.second]){
				visit[x][y] = 1;
				dis[x][y] = dis[p.first][p.second]-1;
				q.push(make_pair(x, y));
				vec.push_back(make_pair(x, y));
			}
		}
	}
	
	cout << vec.size() << '\n';
	sort(vec.begin(), vec.end());
	for(int i = 0; i < vec.size(); i++)
		cout << vec[i].first << ' ' << vec[i].second << '\n';
	return 0;
}