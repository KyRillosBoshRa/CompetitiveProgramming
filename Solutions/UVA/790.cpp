#include <bits/stdc++.h>

using namespace std;

#define endl                           '\n'
#define mk                             make_pair
#define pb                             push_back
#define REP(i, a, b)                   for (int i = int(a); i < int(b); ++i)
#define rREP(i, a, b)                  for (int i = int(a); i > int(b); --i)
#define ALL(v)                           ((v).begin()), ((v).end())
#define toInt(x)                       (x - '0')
#define UNIQUE(c)                      (c).resize(unique(ALL(c)) - (c).begin())
#define F                              first
#define S                              second
//             bit masking
#define isOn(S, j)                     (S & (1 << j))
#define setBit(S, j)                   (S |= (1 << j))
#define clearBit(S, j)                 (S &= ~(1 << j))
#define toggleBit(S, j)                (S ^= (1 << j))
#define lowBit(S)                      (S & (-S))
#define setAll(S, n)                   (S = (1 << n) - 1)

#define modulo(S, N)                   ((S) & (N - 1))   // returns S % N, where N is a power of 2
#define isPowerOfTwo(S)                (!(S & (S - 1)))
#define nearestPowerOfTwo(S)           ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S)              ((S) & (S - 1))
#define turnOnLastZero(S)              ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S)  ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))

typedef long long              ll;
typedef vector <int>           vi;
typedef pair<int, int>         ii;

const int INF = (int)1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;
const int NPOS = -1;
const int N = 10005;

int t, n, h, m, mx;
char prob, status, sss;
struct ST{
    int c ,t;
    char prob, status;
};
struct Final{
    int c;
    int pen;
    int cnt;
};
bool cmp1(const ST& x, const ST& y){
    if(x.t == y.t)
        return x.status == 'N';
    return x.t < y.t;
}
bool cmp2(const Final& x, const Final& y){
    if(x.cnt == y.cnt){
        if(x.pen == y.pen)
            return x.c < y.c;
        return x.pen < y.pen;
    }
    return x.cnt > y.cnt;
}
bool isSame(const Final& x, const Final& y){
    if(x.cnt != y.cnt || x.pen != y.pen)
        return false;
    return true;
}
vector<ST> arr;
int a[30][9];
pair<int, int> ans[N];
void solve(){
    sort(ALL(arr), cmp1);
    REP(i, 0, arr.size()){
        if(arr[i].status == 'N' && a[arr[i].c][arr[i].prob-'A'] != -1){
            a[arr[i].c][arr[i].prob-'A']++;
        }
        else{
            if(a[arr[i].c][arr[i].prob-'A'] != -1 && arr[i].status == 'Y'){
                ++ans[arr[i].c].F;
                ans[arr[i].c].S += arr[i].t+a[arr[i].c][arr[i].prob-'A']*20;
                a[arr[i].c][arr[i].prob-'A'] = -1;
            }
        }
    }
    Final f[30];
    REP(i, 1, mx+1){
        f[i-1].c = i;
        f[i-1].pen = ans[i].S;
        f[i-1].cnt = ans[i].F;
    }
    sort(f, f+mx, cmp2);
    cout << "RANK TEAM PRO/SOLVED TIME" << endl;
    if(!f[0].cnt) cout << setw(4) << 1 << setw(5) << f[0].c << endl;
    else cout << setw(4) << 1 << setw(5) << f[0].c << setw(5) << f[0].cnt << setw(11) << f[0].pen << endl;
    int num = 2, a = 0;
    REP(i, 1, mx){
        if(isSame(f[i], f[i-1])) --num, ++a;
        else num += a, a = 0;
        if(!f[i].cnt) cout << setw(4) << num << setw(5) << f[i].c << endl;
        else cout << setw(4) << num << setw(5) << f[i].c << setw(5) << f[i].cnt << setw(11) << f[i].pen << endl;
        ++num;
    }
}
void init(){
    arr.clear();
    REP(i, 0, 30)
        REP(j, 0, 9)
            a[i][j] = 0;
    REP(i, 0, N)
        ans[i] = mk(0, 0);
    mx = 0;
}
int main()
{
ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> t;
    while(t--){
        while(cin >> n >> prob >> h >> sss >> m >> status){
            ST tmp;
            tmp.c = n; tmp.prob = prob; tmp.t = h*60+m; tmp.status = status;
            arr.pb(tmp);
            mx = max(mx, n);
            cin.ignore();
            if(cin.peek() == '\n') break;
        }
        solve();
        init();
        if(cin.peek() != EOF)cout << endl;
    }
    return 0;
}
