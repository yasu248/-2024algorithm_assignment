/*
深さ優先探索
問題のリンク: 
https://atcoder.jp/contests/maximum-cup-2018/tasks/maximum_cup_2018_b
（BFSと同じ問題文）
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

//DFSの関数
bool dfs(int x,int y,int A,int B,int force){
  if(dp[x][y][A][B][force]) return false;
  dp[x][y][A][B][force] = 1;

// ゴールに到達した場合
  if(x == h - 2 && y == w - 2){
    if(A == 0 && B == 0){
      return true;
    }
  }

  {
    int nx = x + dx[force];
    int ny = y + dy[force];
    if(fie[nx][ny]){
      if(dfs(nx,ny,A,B,force)){
        return true;
      }
    }
  }

  if(A - 1 >= 0)
  {
    // 左回転
    int next = (force + 3) % 4;
    int nx = x + dx[next];
    int ny = y + dy[next];
    if(fie[nx][ny]){
      if(dfs(nx,ny,A - 1,B,next)){
        return true;
      }
    }
  }
  if(B - 1 >= 0)
  {
    // 右回転 
    int next = (force + 1) % 4;
    int nx = x + dx[next];
    int ny = y + dy[next];
    if(fie[nx][ny]){
      if(dfs(nx,ny,A,B - 1,next)){
        return true;
      }
    }
  }
  return false;
}


int main(){
  cin >> a >> b >> h >> w;

  rep(i,h - 1){
    string s;
    cin >> s;
    rep(j,w - 1){
      if(s[j] == '.'){
        fie[i][j] = 1;
      }
    }
  }

// (1,1)からDFS
  if(dfs(1,1,a,b,0)){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
  return 0;
}