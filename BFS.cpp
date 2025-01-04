/*
幅優先探索
問題のリンク: 
https://atcoder.jp/contests/maximum-cup-2018/tasks/maximum_cup_2018_b
（DFSと同じ問題文）
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

int a,b;
int h,w;
vv fie(20,vector<int>(20,0));
int ok = 0;
int dy[] = {0,-1,0,1}; 
int dx[] = {1,0,-1,0}; 
int dp[20][20][20][20][2]; 

// BFSの関数
bool bfs() {
    queue<tuple<int, int, int, int, int>> q;
    q.push({1, 1, a, b, 0});  

    memset(dp, 0, sizeof(dp));

    dp[1][1][a][b][0] = 1;  

    while (!q.empty()) {
        auto [x, y, A, B, force] = q.front();
        q.pop();

        // ゴールに到達した場合
        if(x == h - 2 && y == w - 2) {
            if(A == 0 && B == 0) {
                return true; 
            }
        }
        // 到達できなかった場合
        // 1. 向きを変えずに進む
        int nx = x + dx[force];
        int ny = y + dy[force];
        if(fie[nx][ny] && !dp[nx][ny][A][B][force]) { 
            dp[nx][ny][A][B][force] = 1;
            q.push({nx, ny, A, B, force});
        }

        // 2. 左回転して進む
        if(A - 1 >= 0) {
            int next = (force + 3) % 4;  // 左回転
            nx = x + dx[next];
            ny = y + dy[next];
            if(fie[nx][ny] && !dp[nx][ny][A - 1][B][next]) {
                dp[nx][ny][A - 1][B][next] = 1;
                q.push({nx, ny, A - 1, B, next});
            }
        }

        // 3. 右回転して進む 
        if(B - 1 >= 0) {
            int next = (force + 1) % 4;  // 右回転
            nx = x + dx[next];
            ny = y + dy[next];
            if(fie[nx][ny] && !dp[nx][ny][A][B - 1][next]) {
                dp[nx][ny][A][B - 1][next] = 1;
                q.push({nx, ny, A, B - 1, next});
            }
        }
    }
    return false;  
}

int main() {
    cin >> a >> b >> h >> w;

    rep(i, h - 1) {
        string s;
        cin >> s;
        rep(j, w - 1) {
            if(s[j] == '.') {
                fie[i][j] = 1; 
            }
        }
    }

    // BFSで探索
    if(bfs()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}