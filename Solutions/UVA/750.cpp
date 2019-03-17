#include <bits/stdc++.h>

using namespace std;

#define endl                   '\n'
#define pb                     push_back
#define REP(i, a, b)           for (int i = int(a); i < int(b); ++i)
#define rREP(i, a, b)          for (int i = int(a); i > int(b); --i)
#define ALL(v)				   ((v).begin()), ((v).end())
#define toInt(x)               (x - '0')
#define UNIQUE(c)              (c).resize(unique(ALL(c)) - (c).begin())

typedef long long              ll;
typedef vector <int>           vi;

const int INF = (int)1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;
const int N = 9;

int row[N], col[N], diag1[N*2], diag2[N*2], tmp[N][N];
vector<vi> a;
void _8Queen(int n, int x = 1){
    if(!n){
        vi x; x.pb(0);
        REP(i, 1, N)
            REP(j, 1, N)
                if(tmp[j][i])
                    x.pb(j);
        a.pb(x);
        return;
    }
    REP(i, x, N){
        REP(j, 1, N){
            if(!row[j] && !col[i] && !diag1[i+j] && !diag2[N+(i-j)]){
                tmp[j][i] = row[j] = col[i] = diag1[i+j] = diag2[N+(i-j)] = 1;
                _8Queen(n-1, i);
                tmp[j][i] = row[j] = col[i] = diag1[i+j] = diag2[N+(i-j)] = 0;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    a.pb(vi(0));
    _8Queen(8);
    int T;cin >> T;
    int n, m;
    REP(c, 0, T){
        if(c) cout << endl;
        cout << "SOLN       COLUMN" << endl << " #      1 2 3 4 5 6 7 8" << endl << endl;
        cin >> n >> m;
        int cnt = 0;
        REP(i, 1, a.size()){
            if(a[i][m] != n) continue;
            cout << setw(2) << ++cnt << "      ";
            REP(j, 1, N)
                cout << a[i][j] << " \n"[j+1 == N];
        }
    }
	return 0;
}
