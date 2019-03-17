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
const int MAX = 10002;

int n, x, c, str;
array<int, MAX> prime;
vi p;
void DO()
{
    prime[0] = 1;
    for(int i = 4; i < MAX; i += 2)
        prime[i] = 1;
    for(int i = 3; i*i <= MAX; i +=2)
        if(!prime[i])
            for(int j = i*i; j<MAX; j += i*2)
                prime[j] = 1;
    REP(i, 0, MAX)
        if(!prime[i])
            p.pb(i);
}
int main()
{
ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    DO();
    while(cin >> n >> c)
    {
        cout << n << ' ' << c << ':';
        auto fnd = upper_bound(ALL(p), n)-p.begin();
        if(fnd%2) x = 2*c-1; else x = 2*c;
        str = (fnd/2)-(x/2);
        if(str < 0)
        {
            REP(i, 0, p.size())
                if(p[i] <= n)
                    cout << ' ' << p[i];
                else break;
        }
        else
        {
            while(x--)
            {
                cout << ' ' << p[str];
                ++str;
            }
        }
        cout << endl<< endl;
    }
	return 0;
}
