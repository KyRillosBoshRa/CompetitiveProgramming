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
const int N = 300;

struct word{
    string wo;
    int line, num;
};

unordered_set<string> st;
string s, x;
vector<string> title[N];
vector<word> srt;
int n;
void add_words(){
    bool repeat = true; word pab;
    int pos, lastPos = 0, c = -1;
    while(repeat){
        ++c;
        pos = x.find(" ", lastPos);
        if(pos != string::npos){
            string tmp = x.substr(lastPos, pos-lastPos);
            title[n].pb(tmp);
            lastPos = pos+1;
        }
        else
            repeat = false;
    }
    title[n].pb(x.substr(lastPos, x.size()-lastPos));
    REP(i, 0, title[n].size()){
        if(st.find(title[n][i]) != st.end()) continue;
        word tmp;
        tmp.line = n; tmp.wo = title[n][i]; tmp.num = i;
        srt.pb(tmp);
    }
}
int main()
{
ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    while(cin >> s && s != "::")
        st.insert(s);
    cin.ignore();
    while(getline(cin, x)){
        transform(x.begin(), x.end(), x.begin(), ::tolower);
        add_words();
        ++n;
    }
    sort(ALL(srt), [](const word& x, const word& y){
            if(x.wo == y.wo){
                if(x.line == y.line)
                    return x.num < y.num;
                return x.line < y.line;
            }
            return x.wo < y.wo;
        });
    for(word w:srt){
        REP(i, 0, title[w.line].size()-1){
            if(i == w.num){
                string tmp = title[w.line][i];
                transform(tmp.begin(), tmp.end(), tmp.begin(), ::toupper);
                cout << tmp << ' ';
            }
            else
                cout << title[w.line][i] << ' ';
        }
        if(title[w.line].size()-1 == w.num){
            string tmp = title[w.line].back();
            transform(tmp.begin(), tmp.end(), tmp.begin(), ::toupper);
            cout << tmp << endl;
        }
        else
            cout << title[w.line].back() << endl;
    }
	return 0;
}
