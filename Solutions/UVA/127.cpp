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
const int N = 1e6;

vi ans;
int cnt;
vector<stack<string> > vec;
string s;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    vec.resize(52);
	while (1) {
		cnt = 0;
		ans.clear();
		REP(i, 0, 52) {
			while (!vec[i].empty()) vec[i].pop();
			cin >> s;
			vec[i].push(s);
		}
		bool mv = true;
		int n = 52;
		while(mv){
            mv = false;
            REP(idx, 0, n){
                if (idx >= 3 && (vec[idx].top()[0] == vec[idx - 3].top()[0] || vec[idx].top()[1] == vec[idx - 3].top()[1])) {
                    string tmp = vec[idx].top(); vec[idx].pop();
                    vec[idx - 3].push(tmp);
                }
                else if (idx >= 1 && (vec[idx].top()[0] == vec[idx - 1].top()[0] || vec[idx].top()[1] == vec[idx - 1].top()[1])) {
                    string tmp = vec[idx].top(); vec[idx].pop();
                    vec[idx - 1].push(tmp);
                }
                else continue;
                if(vec[idx].empty()){
                    vec.erase(vec.begin()+idx);
                    --n;
                }
                mv = true;
                break;
            }
		}
		REP(i, 0, 52) {
			if (vec[i].empty()) continue;
			++cnt;
			ans.pb((int)vec[i].size());
		}
//		sort(ALL(ans), greater<int>());
		cout << cnt;
		cout << (cnt == 1 ? " pile ": " piles ") << "remaining:";
		for (int &a : ans) cout << ' ' << a;
		cout << endl;
		cin.ignore();
		if (cin.peek() == '#') break;
	}
//	system("pause");
	return 0;
}
