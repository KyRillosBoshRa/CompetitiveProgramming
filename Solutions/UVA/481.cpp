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
const int N = 6e5+5;
const int MOD = 1e9+7;

template<class T> inline T mod(T a, T b){return (a%b + b) % b;} //for -ve numbers

int n, a[N];
// this code provided by Po Qian
void calc_LIS(vector<int>& din, vector<int>& dout) {
	vector<int> M;  // M[j] store the index of the smallest tail of all LIS of length (j+1)
	M.push_back(0);  // M[0]
	vector<int> P(din.size());  // Predecessor of M[j]

	for (int i=0; i<din.size()-1; i++) {  // Calculate M for {din[0]..din[i]}
		if (din[M.back()] < din[i+1]) {
			M.push_back(i+1);
			P[i+1] = M[M.size()-2];
			continue;
		}

		vector<int>::iterator pos = lower_bound(M.begin(), M.end(), din[i+1], [&](int m, int val){return (din[m] < val);});
		if ( din[*pos] > din[i+1] ) {
			*pos = i+1;
			if (pos != M.begin())
				P[i+1] = *(pos - 1);
		}

	}

	int v = M.back();
	dout.resize(M.size());
	for (int u = M.size(); u!=0; u--) {
		dout[u-1] = din[v];
		v = P[v];
	}
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
	while(cin >> a[n]){++n;}
	vector<int> arr(a, a+n);
	vector<int> res;
	calc_LIS(arr, res);
	cout << res.size() << endl << '-' << endl;
	REP(i, 0, res.size())
        cout << res[i] << endl;
	return 0;
}
