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
const int N = 10009;

int n, c;
string title, x, dash = "----------------------------------------";
struct employee{
    string a[8] ;
};
vector<employee> vec;
void separate(){
    bool repeat = true; employee pab;
    int pos, lastPos = 0, c = 0;
    pab.a[0] = title;
    while(repeat){
        ++c;
        pos = x.find(",", lastPos);
        if(pos != string::npos){
            string tmp = x.substr(lastPos, pos-lastPos);
            pab.a[c] = tmp;
            lastPos = pos+1;
        }
        else
            repeat = false;
    }
    pab.a[c] = x.substr(lastPos, x.size()-lastPos);
    vec.pb(pab);
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> n;
    while(n--){
        cin.ignore();
        getline(cin, title);
        while(getline(cin, x)){
            separate();
            if (cin.peek() == '\n') break;
        }
    }
    sort(ALL(vec), [](const employee& x, const employee& y){
            return x.a[3] < y.a[3];
         });
    for(employee e:vec){
        cout << dash << endl;
        cout << e.a[1] << ' ' << e.a[2] << ' ' << e.a[3] << endl
             << e.a[4] << endl
             << "Department: " << e.a[0] << endl
             << "Home Phone: " << e.a[5] << endl
             << "Work Phone: " << e.a[6] << endl
             << "Campus Box: " << e.a[7] << endl;
    }
    return 0;
}
