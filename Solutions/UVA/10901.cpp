#include <bits/stdc++.h>

using namespace std;

#define endl                           '\n'
#define mk                             make_pair
#define pb                             push_back
#define REP(i, a, b)                   for (int i = int(a); i < int(b); ++i)
#define rREP(i, a, b)                  for (int i = int(a); i > int(b); --i)
#define ALL(v)				           ((v).begin()), ((v).end())
#define toInt(x)                       (x - '0')
#define UNIQUE(c)                      (c).resize(unique(ALL(c)) - (c).begin())
#define F                              first
#define S                              second
#define popcnt(x)                      __builtin_popcount(x)
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
typedef vector <ii>            vii;

const int INF = (int)1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;
const int NPOS = -1;
const int N = 1000009;

int T, n, l, m, x, timeNow, sum;
string s;
queue<pair<int, int> > Left, Right;
vi ans;
void go_left(){
    sum = 0;
    timeNow += l;
    while(!Right.empty() && Right.front().F <= timeNow-l && sum < n){
        ++sum;
        ans[Right.front().S] = timeNow;
        Right.pop();
    }
}
void go_right(){
    sum = 0;
    timeNow += l;
    while(!Left.empty() && Left.front().F <= timeNow-l && sum < n){
        ++sum;
        ans[Left.front().S] = timeNow;
        Left.pop();
    }
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> T;
    REP(a, 0, T){
        if(a) cout << endl;
        timeNow = 0;
        ans.clear();
        cin >> n >> l >> m;
        ans.resize(m);
        REP(i, 0, m){
            cin >> x >> s;
            if(s == "left") Left.push(mk(x, i));
            else Right.push(mk(x, i));
        }
        bool c = 1;
        while(!Left.empty() || !Right.empty()){
            int earliest_car = numeric_limits<int>::max();
            if(!Left.empty()) earliest_car = Left.front().F;
            if(!Right.empty()) earliest_car = min(Right.front().F, earliest_car);
            timeNow = max(timeNow, earliest_car);
            if(c)go_right();
            else go_left();
            c ^= 1;
        }
        for(int& a:ans) cout << a << endl;
    }
	return 0;
}
