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
const int MAX = 102;

class UnionFind {
private:
    vi p, Rank, setSize;
    int numSets;
public:
    UnionFind(int N)
    {
        setSize.assign(N, 1); numSets = N; Rank.assign(N, 0); p.assign(N, 0);
        for (int i = 0; i < N; i++) p[i] = i;
    }
    int findSet(int i) {return (p[i] == i) ? i : (p[i] = findSet(p[i]));}
    bool isSameSet(int i, int j) {return findSet(i) == findSet(j);}
    void unionSet(int i, int j)
    {
        if (!isSameSet(i, j))
        {
            --numSets;
            int x = findSet(i), y = findSet(j);
            if (Rank[x] > Rank[y]) {p[y] = x; setSize[x] += setSize[y];}
            else
            {
                p[x] = y; setSize[y] += setSize[x];
                if (Rank[x] == Rank[y]) Rank[y]++;
            }
        }
    }
    int numDisjointSets() { return numSets; }
    int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int n , s, x, y, c, q;
char ch;
void solve()
{
    c = q = 0;
    UnionFind uf(s);
    while(cin.peek() == 'q' || cin.peek() == 'c')
    {
        cin >> ch >> x >> y;
        --x; --y;
        cin.ignore();
        if(ch == 'c')
            uf.unionSet(x, y);
        else
        {
            ++q;
            if(uf.isSameSet(x, y))
                ++c;
        }
    }
    cout << c << ',' << q-c << endl;
}
int main()
{
ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> n;
    REP(i, 0, n)
    {
        cin >> s;
        cin.ignore();
        solve();
        if(i != n-1) cout << endl;
    }
	return 0;
}
