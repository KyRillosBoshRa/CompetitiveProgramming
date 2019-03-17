#include <bits/stdc++.h>

using namespace std;

#define endl                   '\n'
#define pb                     push_back
#define REP(i, a, b)           for (int i = int(a); i < int(b); ++i)
#define rREP(i, a, b)          for (int i = int(a); i > int(b); --i)
#define ALL(x)                 (x).begin(), (x).end()

typedef long long              ll;
typedef vector <int>           vi;

const int INF = (int)1e9;
const double PI = 2 * acos(0.0);
const int NPOS = -1;
const int eps = (int)1e-9;

int c;
double H, D, ans, U, F;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> H >> U >> D >> F;
    while(H > eps)
    {
        F = U * F / 100.0;
        c = 1;
        ans = 0;
        while(true)
        {
            ans += U;
            U -= F;
            if (U < eps) U = 0;
            if (ans > H){cout << "success on day " << c << endl; break;}
            ans -= D;
            if (ans < 0) {cout << "failure on day " << c << endl; break;}
            ++c;
        }
        cin >> H >> U >> D >> F;
    }
    return 0;
}
