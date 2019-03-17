#include <bits/stdc++.h>
using namespace std;
typedef long long        ll;
typedef pair<int, int>   pii;
#define endl '\n'
int n, x, z; ll sum;
priority_queue<int, vector<int>, greater<int> > pq;
int main() {
    ios::sync_with_stdio(NULL);
//    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    cin >> n;
    while(n != 0)
    {
        sum = 0;
        while(n--) {cin >> z; pq.push(z);}
        while(pq.size() != 1)
        {
            x = pq.top(); pq.pop();
            x += pq.top(); pq.pop();
            pq.push(x);
            sum += x;
        }
        pq.pop();
        cout << sum << endl;
        cin >> n;
    }
    return 0;
}
