#includebitsstdc++.h
using namespace std;
vectorint a[1000005];
bool visit[1000005];
void bfs(int n){
	queueint q;
	q.push(n);
	while(!q.empty()){
		int p = q.front();
		q.pop();
		for(int i = 0; i  a[p].size(); i++){
			if(!visit[a[p][i]]){
				visit[a[p][i]] = 1;
				q.push(a[p][i]);
			}
		}
	}
}
int main(){
	ios_basesync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin   n  m;
	for(int i = 1; i = m; i++){
		int u, v;
		cin  u  v;
		a[u].push_back(v);
		a[v].push_back(u);
	}	
	int ans = 0;

	for(int i = 1; i = n; i++){
		if(!visit[i]){
			ans++;
			bfs(i);
		}
	}
	cout  ans  'n';
	return 0;
}