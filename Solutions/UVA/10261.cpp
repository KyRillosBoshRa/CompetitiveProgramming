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
#define clr(a, b)                      memset((a), (b), sizeof(a))

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

const int INF = 0x3f3f3f3f;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;
const int NPOS = -1;
const int N = 1e5+5;

template<class T>inline T mod(T a, int b){return (b + (a%b)) % b;}

int t, n, arr[N], sum[N];
int memo[205][10005], path[205][10005];
int cz;
vi ans;
int solve(int idx, int rem){
    if(idx == n)
        return 0;
    int& ret = memo[idx][rem];
    if(~ret)
        return ret;
    int c1 = 0, c2 = 0;
    if(arr[idx]+rem <= cz)
        c1 = 1 + solve(idx+1, arr[idx]+rem);
    if(arr[idx]+(sum[idx]-rem) <= cz)
        c2 = 1 + solve(idx+1, rem);
    if(c1 > c2){
        path[idx][rem] = 1;
        return ret = c1;
    }else if(c1 <= c2 && c2 != 0){
        path[idx][rem] = 0;
        return ret = c2;
    }
    return ret = 0;
}
int print_path(int idx, int rem){
    int& x = path[idx][rem];
    if(x == -1)
        return 0;
    if(x){
        ans.pb(1);
        return 1 + print_path(idx+1, arr[idx]+rem);
    }
    else{
        ans.pb(0);
        return 1 + print_path(idx+1, rem);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> t;
    int c = 0;
    while(t--){
        if(c++)
            cout << endl;
        n = 0;
        ans.clear();
        cin >> cz; cz *= 100;
        while(cin >> arr[n] && arr[n])
            ++n;
        n = min(n, 201);
        REP(i, 1, n+1)
            sum[i] = sum[i-1]+arr[i-1];
        clr(memo, -1);
        clr(path, -1);
        solve(0, 0);
        print_path(0, 0);
        cout << ans.size() << endl;
        for(int a:ans)
            if(a)
                cout << "port" << endl;
            else
                cout << "starboard" << endl;
    }
    return 0;
}

