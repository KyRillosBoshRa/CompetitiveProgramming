Example problem: http://codeforces.com/group/BDIXyZZHhT/contest/205512/problem/D
#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int MSQ = sqrt(N) + 5;
int arr[N];
int blocks[MSQ];

int bf(int x, int y) {
	int c = 0;
	for (int i = x; i <= y; ++i) {
		c += arr[i];
	}
	return c;
}
int n, q;
char t;
int x, y, v;
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
//    freopen("in.txt", "r", stdin);
#endif // ONLINE_JUDGE
	cin >> n >> q;
	int sq = sqrt(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		int bid = i / sq;
		blocks[bid] += arr[i];
	}
	while (q--) {
		cin >> t;
		if (t == '?') {
			cin >> x >> y; --x; --y;
			int xbid = x / sq, ybid = y / sq;
			if (xbid == ybid) {
				cout << bf(x, y) << '\n';
			} else {
				long long res = bf(x, xbid * sq + sq - 1) + bf(sq * ybid, y);
				for (int bi = xbid + 1; bi < ybid; ++bi) {
					res += blocks[bi];
				}
				cout << res << '\n';
            }
		}else{
            cin >> x >> v; --x;
            int xbid = x / sq;
            blocks[xbid] += v-arr[x];
            arr[x] = v;
		}
    }
    return 0;
}