#include <bits/stdc++.h>
using namespace std;
typedef long long        ll;
typedef pair<int, int>   pii;
#define endl '\n'
int mx, n, x, c; string y;
array<pair<int, string>, 10> arr;
int main() {
    ios::sync_with_stdio(NULL);
//    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        mx = 0;
        for(int j = 0; j < 10; ++j)
        {
            cin >> y >> x;
            arr[j] = make_pair(x, y);
            mx = max(mx, x);
        }
        stable_sort(arr.begin(), arr.end(), [&](const pair<int, string>& a, const pair<int, string>& b){return a.first > b.first;});
        cout << "Case #" << ++c << ":" << endl;
        x = 0;
        while(x < 10 && arr[x].first == mx)
        {
            cout << arr[x].second << endl;
            ++x;
        }
    }
    return 0;
}
