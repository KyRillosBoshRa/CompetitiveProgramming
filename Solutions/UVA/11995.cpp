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

stack<int> stk;
queue<int> q;
priority_queue<int> pq;
int n, x, y;
bool S, Q, PQ;
int main()
{
ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    while(cin >> n)
    {
        S = Q = PQ = true;
        while(n--)
        {
            cin >> x >> y;
            if(x == 1)  stk.push(y), q.push(y), pq.push(y);
            else
            {
                if(!stk.empty() && stk.top() != y) S = false;
                if(!q.empty() && q.front() != y) Q = false;
                if(!pq.empty() && pq.top() != y) PQ = false;


                if(!q.empty()) q.pop();
                else Q = false;
                if(!pq.empty()) pq.pop();
                else PQ = false;
                if(!stk.empty()) stk.pop();
                else S = false;
            }
        }
        while(!q.empty()) q.pop();
        while(!pq.empty()) pq.pop();
        while(!stk.empty()) stk.pop();


        if(S + Q + PQ > 1) cout << "not sure" << endl;
        else if(S) cout << "stack" << endl;
        else if(Q) cout << "queue" << endl;
        else if(PQ) cout << "priority queue" << endl;
        else cout << "impossible" << endl;
    }
	return 0;
}
