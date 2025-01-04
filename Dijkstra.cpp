/*
ダイクストラ法
問題のリンク: 
https://atcoder.jp/contests/abc362/tasks/abc362_d
*/
#include <bits/stdc++.h>
using namespace std; 
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> vv;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
//ここまでがマクロ

// ダイクストラ法
void dijkstra(int N, vector<vector<pair<int, ll>>>& adj, vector<ll>& result, vector<ll>& A) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    vector<ll> dist(N + 1, LINF);
    
    dist[1] = A[0];  
    pq.push({A[0], 1});  // (重み, 頂点)

    while (!pq.empty()) {
        auto [cur_dist, u] = pq.top();
        pq.pop();

        if (cur_dist > dist[u]) continue;

        for (auto [v, edge_weight] : adj[u]) {
            ll new_dist = dist[u] + edge_weight + A[v - 1];  // 現頂点の重み + 辺の重み + 隣接頂点の重み
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }

    for (int i = 2; i <= N; i++) {
        result.push_back(dist[i]);
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<ll> A(N);  // 頂点の重み
    rep(i, N) {
        cin >> A[i];
    }

    // 隣接リスト
    vector<vector<pair<int, ll>>> adj(N + 1);

    rep(i, M) {
        int u, v;
        ll b;
        cin >> u >> v >> b;
        adj[u].push_back({v, b});
        adj[v].push_back({u, b});
    }

    vector<ll> result;
    dijkstra(N, adj, result, A);

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}