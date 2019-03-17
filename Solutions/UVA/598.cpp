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
#define clr(a, b)                      memset((a), (b), sizeof(a))
#define F                              first
#define S                              second
#define popcnt(x)                      __builtin_popcount(x)
#define WHITE                          0
#define GRAY                           1
#define BLACK                          2
#define bye                            exit(0)
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
const int N = (int)1e5+5;
const int MOD = (int)1e9+7;

int n, a, b, L;
string arr[N];
void loop(int lvl, int idx = 0, string ans = ""){
    if(lvl == L){
        ans.pop_back();
        ans.pop_back();
        cout << ans << endl;
        return;
    }
    REP(i, idx, n){
        loop(lvl+1, i+1, ans + arr[i]+", ");
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    int t; cin >> t; cin.ignore();
    while(t--){
        n = 0;
        cin.ignore();
        string tmp;
        getline(cin, tmp);
        int str[2] = {0}; // for start and end
        if(tmp == "*"){
            str[0] = 1;
            str[1] = -1;
        }
        else{
            stringstream ss;
            ss << tmp;
            int ii = 0;
            while(ss >> str[ii]) ++ii;
        }
        while(cin.peek() != '\n' && cin.peek() != EOF){
            getline(cin, arr[n]);
            ++n;
        }
        if(str[1] == -1) str[1] = n;
        else if(str[1] == 0) str[1] = str[0];
        REP(i, str[0], str[1]+1){
            cout << "Size " << i << endl;
            L = i;
            loop(0);
            cout << endl;
        }
        if(t)cout << endl;
    }
	return 0;
}
