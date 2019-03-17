#include <bits/stdc++.h>

using namespace std;

#define endl                   '\n'
#define pb                     push_back
#define REP(i, a, b)           for (int i = int(a); i < int(b); ++i)
#define rREP(i, a, b)          for (int i = int(a); i > int(b); --i)
#define ALL(v)				   ((v).begin()), ((v).end())
#define toInt(x)               (x - '0')
#define UNIQUE(c)              (c).resize(unique(ALL(c)) - (c).begin())

typedef long long              ll;
typedef vector <int>           vi;

const int INF = (int)1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;
const int NPOS = -1;

const int MAX = 1000001;
int n, x, y, c;
string s, sub;
array<int, MAX> arr;
int main()
{
ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    while(cin >> s)
    {
        cin >> n;
        cout << "Case " << ++c << ":" << endl;
        arr[0] = toInt(s[0]);
        REP(i, 1, s.size())
            arr[i] = toInt(s[i]) + arr[i-1];
        while(n--)
        {
            cin >> x >> y;
            if(y > x) swap(x, y);
            if((s[y] == '0' && arr[x] == arr[y]) || (s[y] == '1' && arr[x]-arr[y] == x-y))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
	return 0;
}
