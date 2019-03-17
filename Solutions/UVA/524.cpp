#include <bits/stdc++.h>
//#include"stdafx.h"
using namespace std;

#define endl                           '\n'
#define mk                             make_pair
#define pb                             push_back
#define REP(i, a, b)                   for (int i = int(a); i < int(b); ++i)
#define rREP(i, a, b)                  for (int i = int(a); i > int(b); --i)
#define ALL(v)				           ((v).begin()), ((v).end())
#define toInt(x)                       (x - '0')
#define UNIQUE(c)                      (c).resize(unique(ALL(c)) - (c).begin())
#define clr(a, b)                      memset((a), (b), sizeof(a))
#define F                              first
#define S                              second
#define popcnt(x)                      __builtin_popcount(x)
#define WHITE 0
#define GRAY  1
#define BLACK 2
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
const int N = 6e4+5;
const int MOD = 1e9+7;

template<class T> inline T mod(T a, T b){return (a%b + b) % b;} //for -ve numbers

int t, w, n, c;
bitset<30> used;
bitset<100> P;
vi ans;
void Sieve() {
    P[0] = P[1] = false;
    for(int i=4; i<101; i+=2) P[i] = false;
    for(int i=3; i*i<101; i+=2)
        if (P[i])
            for(int j=i*i; j<101; j+=i+i)
                P[j] = false;
}
void solve(int idx = 1){
    if(idx == n){
        if(P[ans[idx-1]+1]){
            for(int i = 0; i < n; ++i)
                cout << ans[i] << " \n"[i+1 == n];
        }
        return;
    }
    REP(i, 2, n+1){
        if(!used[i] && P[i+ans[idx-1]]){
            used[i] = 1;
            ans.pb(i);
            solve(idx+1);
            used[i] = 0;
            ans.pop_back();
        }
    }
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
//    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
	P.set();
	Sieve();
	for(int c = 1; cin >> n; ++c){
        if(c != 1) cout << endl;
        cout << "Case " << c << ':' << endl;
        used.reset();
        ans.clear();
        ans.pb(1);
        solve();
	}
    return 0;
}
