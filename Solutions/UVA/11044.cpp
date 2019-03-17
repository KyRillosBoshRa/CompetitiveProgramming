#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int n, x, y, k, ans;
int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	while(n--)
	{
		cin >> x >> y;
		if(y > x) swap(x, y);
		k = 4; ans = 1;
		while(k < y-1)
		{
			++ans;
			k += 3;
		}
		ans *= ceil((x-2)/3.0);
		cout << ans << endl;
	}
}