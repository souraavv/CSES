#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpi vector<pair<int, int> >
#define vvpi vector<vector<pair<int, int> > >
#define all(v) (v).begin(), (v).end()    
#define rall(v) (v).rbegin(), (v).rend()
#define pii pair<int, int>
#define pb push_back
#define SZ(x) (int)(x).size()
#define inf 1e16
#define F first
#define S second
#define bpc(x) __builtin_popcountll(x)
#define Cout cout << fixed << setprecision(12)
#define fast ios::sync_with_stdio(false); cin.tie(0);

const int N = 1e6 + 10;
const int mod = 1e9 + 7;
const double pi = acos(-1);

#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << "[";
    cout << vars << "] = [";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
    cout << "]\n";
}

void print(vi &a, int start = 0) {
    int n = a.size();
    for(int i = start; i < n; ++i) cerr << a[i] << ' ';
    cerr << "\n";
}

void print2D(vvi& a) {
    int n = a.size();
    for (int i = 0; i < n; ++i) print(a[i]);
}


int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int> > dp(n + 1, vector<int>(k + 1, 0));
    
    for (int j = 0; j <= k; ++j) {
        dp[0][j] = a[0] >= k - j; // If I can hold more than j, then sure.
        dp[0][j] += (j - 1 >= 0 ? dp[0][j - 1] : 0);
        dp[0][j] %= mod;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            int end = min(k, j + a[i]);
            int start = (j - 1 >= 0 ? dp[i - 1][j - 1] : 0);
            int total_prev = (mod + dp[i - 1][end] - start) % mod;
            int prefix = (j - 1 >= 0 ? dp[i][j - 1] %  mod : 0);
            dp[i][j] = (prefix + total_prev) % mod;
        }
    }
    cout << dp[n - 1][0] % mod << '\n';
    return 0;
}
