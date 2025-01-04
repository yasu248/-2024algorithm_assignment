/*
動的計画法（DP）
問題のリンク: 
https://atcoder.jp/contests/dp/tasks/dp_d
*/
#include <bits/stdc++.h>
using namespace std; 
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
typedef long long ll;
typedef vector<vector<int>> vv;

int n, W;

int main() {
    cin >> n >> W;
    vector<int> v(n), weight(n);
    rep(i, n) cin >> weight[i] >> v[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(W + 1, 0));
    
    rep(i, n) {
        rep(j, W + 1) {
            // そのままの状態を引き継ぐ
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            // 重さが許容範囲内ならば、アイテムを追加する
            if (j - weight[i] >= 0) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - weight[i]] + v[i]);
            }
        }
    }
    cout << dp[n][W] << endl;

    return 0;
}