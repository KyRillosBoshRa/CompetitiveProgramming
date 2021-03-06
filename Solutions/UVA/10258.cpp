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
const int N = 105;

int t, n, m, mx, prob;
char status;
struct ST{
    int c ,t, prob;
    char status;
};
struct Final{
    int c;
    int pen;
    int cnt;
};
bool cmp1(const ST& x, const ST& y){
    if(x.t == y.t)
        return x.status == 'C';
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
bool mark[N];
vector<ST> arr;
int a[101][10];
pair<int, int> ans[N];
vector<Final> f;
void solve(){
//    sort(ALL(arr), cmp1);
    REP(i, 0, arr.size()){
        if(arr[i].status == 'I' && a[arr[i].c][arr[i].prob] != -1){
            a[arr[i].c][arr[i].prob]++;
        }
        else{
            if(a[arr[i].c][arr[i].prob] != -1 && arr[i].status == 'C'){
                ++ans[arr[i].c].F;
                ans[arr[i].c].S += arr[i].t+a[arr[i].c][arr[i].prob]*20;
                a[arr[i].c][arr[i].prob] = -1;
            }
        }
    }
    REP(i, 1, N)
        if(mark[i]){
            Final tmp;
            tmp.c = i;
            tmp.cnt = ans[i].F;
            tmp.pen = ans[i].S;
            f.pb(tmp);
        }
    sort(ALL(f), cmp2);
    for(const Final &a: f)
        cout << a.c << ' ' << a.cnt << ' ' << a.pen << endl;
}
void init(){
    arr.clear();
    f.clear();
    REP(i, 0, N)
        REP(j, 0, 10)
            a[i][j] = 0;
    REP(i, 0, N)
        ans[i] = mk(0, 0), mark[i] = 0;
}
int main()
{
ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> t;
    init();
    while(t--){
        while(cin >> n >> prob >> m >> status){
            ST tmp;
            tmp.c = n; tmp.prob = prob; tmp.t = m; tmp.status = status;
            if(status == 'C' || status == 'I') arr.pb(tmp);
            mark[n] = 1;
            cin.ignore();
            if(cin.peek() == '\n') break;
        }
        solve();
        init();
        if(cin.peek() != EOF)cout << endl;
    }
    return 0;
}
