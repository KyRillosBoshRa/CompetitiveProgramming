#include <bits/stdc++.h>

using namespace std;
int t, n, h, f, a, x, acorn[2005][2005];
int dp[2009];
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> t;
    while(t--){
        memset(dp, 0, sizeof(dp));
        memset(acorn, 0, sizeof(acorn));
        cin >> n >> h >> f;
        for(int i = 0; i < n; ++i){
            cin >> a;
            while(a--){
                cin >> x;
                ++acorn[i][x];
            }
        }
        for(int i = 0; i < n; ++i)
            dp[h] = max(dp[h], acorn[i][h]);
        for (int ha = h-1; ha >= 0; --ha) {
            for(int tree = 0; tree < n; ++tree){
                acorn[tree][ha] += max(acorn[tree][ha+1], (ha+f <= h ?dp[ha+f]:0));
                dp[ha] = max(dp[ha], acorn[tree][ha]);
            }
        }
        cout << dp[0] << '\n';
    }
    return 0;
}
