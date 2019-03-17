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
const int MAX = 10009;

int n, m, x;
vi ans, vec;
vector<string> strings;
set<string> st;
void print() {
	string s = "";
	for (auto itr = ans.begin(); itr != ans.end(); ++itr) {
		s += to_string(*itr);
		if (itr + 1 != ans.end()) s += '+';
	}
	strings.pb(s);
}
void solve(int idx, int a) {
	if (idx == m) {
		if (a == n) print();
		return;
	}
	ans.pb(vec[idx]);
	solve(idx + 1, a + vec[idx]);
	ans.pop_back();
	solve(idx + 1, a);
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
	for (;;) {
		cin >> n >> m;
		if (!n && !m) break;
		cout << "Sums of " << n << ':' << endl;
		REP(i, 0, m) {
			cin >> x;
			vec.pb(x);
		}
		sort(ALL(vec), greater<int>());
		solve(0, 0);
		if (strings.empty()) cout << "NONE" << endl;
		for (string& s : strings){
			if(st.find(s) == st.end())
				cout << s << endl;
			st.insert(s);
		}
		ans.clear(); vec.clear(); strings.clear(); st.clear();
	}
//	system("pause");
	return 0;
}

