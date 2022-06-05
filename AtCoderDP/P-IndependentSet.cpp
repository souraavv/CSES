#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
const int MOD = 1e9 + 7;

int add(int i, int j) {
	if ((i += j) >= MOD)
		i -= MOD;
	return i;
}
int mul(int i, int j) {
	return int((long long) i * j % MOD);
}

vector<int> adj[MAXN];
int dp[MAXN][2];

void dfs(int i, int p) {
	dp[i][0] = dp[i][1] = 1;
	for (int j : adj[i]) if (j != p) {
		dfs(j, i);
		dp[i][0] = mul(dp[i][0], dp[j][1]);
		dp[i][1] = mul(dp[i][1], add(dp[j][0], dp[j][1]));
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;
	for (int i = 0, a, b; i + 1 < n; ++i) {
		cin >> a >> b, --a, --b;
		adj[a].push_back(b), adj[b].push_back(a);
	}
	dfs(0, 0);
	cout << add(dp[0][0], dp[0][1]) << '\n';
}
