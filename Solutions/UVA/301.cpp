//vector cities is the orders
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
const int N = 1e5+5;
const int MOD = 1e9+7;

template<class T> inline T mod(T a, T b){return (a%b + b) % b;} //for -ve numbers

struct data{
    int str, ed, val, cnt;
    friend istream& operator>>(istream& in, data& a){
        in >> a.str >> a.ed >> a.cnt;
        a.val = (a.ed-a.str)*a.cnt;
        return in;
    }
};

int n, m, t, ans;
data in;
vector<data> cities;
//int solve(int city, int rem, int idx, vi& ht5ls){
//    if(city == m)
//        return 0;
//    rem += ht5ls[city];
////    ht5ls[city] = 0;
//    int pick = 0;
//    for(int i = idx; i < cities[city].size(); ++i){
//        ht5ls[cities[city][i].ed] += cities[city][i].cnt;
//        if(rem - cities[city][i].cnt >= 0)
//            pick = cities[city][i].val + solve(city, rem-cities[city][i].cnt, idx+1, ht5ls);
//        ht5ls[cities[city][i].ed] -= cities[city][i].cnt;
//        int leave = solve(city, rem, idx+1, ht5ls);
//        return max(pick, leave);
//    }
//    return solve(city+1, rem, 0, ht5ls);
//}
int capacity[20];
void solve(int city, int v = 0){
    REP(i, 0, m)
        if(capacity[i] > n)
            return;
    if(city == t){
        ans = max(ans, v);
        return;
    }
    REP(x, cities[city].str, cities[city].ed)
        capacity[x] += cities[city].cnt;
    solve(city+1, v+cities[city].val);
    REP(x, cities[city].str, cities[city].ed)
        capacity[x] -= cities[city].cnt;
    solve(city+1, v);
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
	while(cin >> n >> m >> t && (n || m || t)){
        ans = 0;
        cities.clear();
        cities.resize(t+1);
        REP(i, 0, t){
            cin >> cities[i];
        }
        clr(capacity, 0);
        solve(0, 0);
        cout << ans << endl;
	}
	return 0;
}
