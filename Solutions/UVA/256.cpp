// solve it by brute force then hard copy the answer because of the time limit
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
const int N = 1100009;

template<class T> inline T max(T a, T b, T c){return max(a, max(b, c));}

int n;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    while(cin >> n){
        if(n == 2)
            cout << "00" << endl
                 << "01" << endl
                 << "81" << endl;
        else if(n == 4)
            cout << "0000" << endl
                 << "0001" << endl
                 << "2025" << endl
                 << "3025" << endl
                 << "9801" << endl;
        else if(n == 6)
            cout << "000000" << endl
                 << "000001" << endl
                 << "088209" << endl
                 << "494209" << endl
                 << "998001" << endl;
        else if(n == 8)
            cout << "00000000" << endl
                 << "00000001" << endl
                 << "04941729" << endl
                 << "07441984" << endl
                 << "24502500" << endl
                 << "25502500" << endl
                 << "52881984" << endl
                 << "60481729" << endl
                 << "99980001" << endl;
    }
    return 0;
}
// the real sol and actually it seems to pass in 0.5 second
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
const int N = 1100009;

template<class T> inline T max(T a, T b, T c){return max(a, max(b, c));}

ll n, a, b, x;
vi u, i, o, p;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    for(ll m = 0; m < 1e8; ++m){
        a = m%10; b = m/10;
        if((a + b)*(a + b) == m && m != 100) u.pb(m);
        a = m%100; b = m/100;
        if((a + b)*(a + b) == m && m != 10000) i.pb(m);
        a = m%1000; b = m/1000;
        if((a + b)*(a + b) == m && m != 1000000) o.pb(m);
        a = m%10000; b = m/10000;
        if((a + b)*(a + b) == m && m != 100000000) p.pb(m);
    }
    while(cin >> n){
        if(n == 2)
            for(int& a:u)
                cout << setw(n) << setfill('0') << a << endl;
        else if(n == 4)
            for(int& a:i)
                cout << setw(n) << setfill('0') << a << endl;
        else if(n == 6)
            for(int& a:o)
                cout << setw(n) << setfill('0') << a << endl;
        else if(n == 8)
            for(int& a:p)
                cout << setw(n) << setfill('0') << a << endl;
    }
    return 0;
}
