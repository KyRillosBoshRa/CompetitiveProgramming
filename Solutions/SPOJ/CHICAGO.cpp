#include<bits/stdc++.h>
using namespace std;

const int N = 101;
int n, m, u, v;
double matrix[N][N];
void floyed(){
  for(int k = 1; k <= n; ++k){
    for(int i = 1; i <= n; ++i){
      for(int j = 1; j <= n; ++j){
        if(matrix[i][k] * matrix[k][j] > matrix[i][j]) matrix[i][j] = matrix[i][k] * matrix[k][j];
      }
    }    
  }
}
int main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif // ONLINE_JUDGE
  while(cin >> n && n){
    cin >> m;
    for(int i = 1; i <= n; ++i){
      for(int j = 1; j <= n; ++j){
        matrix[i][j] = 0;
      }
    }
    for(int i = 0; i < m; ++i){
      cin >> u >> v;
      cin >> matrix[u][v];
      matrix[u][v] /= 100;
      matrix[v][u] = matrix[u][v];
    }
    floyed();
    cout << fixed << setprecision(6) << 100 * matrix[1][n] << " percent\n";
  }
  return 0;
}
