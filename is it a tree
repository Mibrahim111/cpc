#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


void dfs(const vector<vector<int>>& g, int node, vector<bool>& vis){
	vis[node] = 1;
	for (auto ne : g[node]) {
		if (!vis[ne])
			dfs(g, ne, vis);
	}
}




int main() {

	int N, M;
	cin >> N >> M;

	if (M != N - 1)
	{
		cout << "NO\n";
		return 0;
	}

	vector<vector<int>> g(N);
	vector<bool> vis(N,0);
	int u, v;

	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		u--, v--;

		g[u].push_back(v);
		g[v].push_back(u);
	}

		dfs(g, 0, vis);
	for (int i = 0; i < N; i++) {
		if (!vis[i])
		{
		cout << "NO\n";
			return 0;
		}

	}
		cout << "YES\n";

	return 0;

}
