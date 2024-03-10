#include<bits/stdc++.h>
using namespace std;
vector<int> a[20005];
int dis[20005];
bool Visit[20005];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m, t;
	cin >> n >> m >> t;
	for(int i = 1; i <= m; i++){
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}	
	queue<int> q;
	q.push(1);
	Visit[1] = 1;
	dis[1] = 0;
	while(!q.empty()){
		int p = q.front();
		q.pop();
		for(int i = 0; i < a[p].size(); i++){
			if(!Visit[a[p][i]]){
				Visit[i] = 1;
				q.push(a[p][i]);
				dis[a[p][i]] = dis[p] + 1;
			}
		}
	}
	while(t--){
		int x;
		cin >> x;
		cout << dis[x] << '\n';
	}
	return 0;
}