#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int> >  vec;
int m, n, k;
bool visit[1005][1005];
void dfs(int x, int y, int k){
	if(k < 0 || x < 1 || x > n || y < 1 || y > m || visit[x][y])
		return;
	visit[x][y] = 1;
	vec.push_back(make_pair(x, y));
	dfs(x - 2, y + 1, k - 1);
	dfs(x - 2, y - 1, k - 1);
	dfs(x - 1, y + 2, k - 1);
	dfs(x - 1, y - 2, k - 1);
	dfs(x + 1, y + 2, k - 1);
	dfs(x + 1, y - 2, k - 1);
	dfs(x + 2, y - 1, k - 1);
	dfs(x + 2, y + 1, k - 1);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int x, y;
	cin >> n >> m >> k >> x >> y;	

	dfs(x, y, k);
	sort(vec.begin(), vec.end());
	cout << vec.size() << '\n';
	for(int i = 0; i < vec.size(); i++)
		cout << vec[i].first << ' ' << vec[i].second << '\n';
	return 0;
}