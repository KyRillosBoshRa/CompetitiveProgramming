#include <bits/stdc++.h>

using namespace std;
string s;
vector<int> v;
vector<int> sign;
bool memo[31][32][6005];
bitset<6009> used;
void solve(int idx = 0, int open = 0, int val = 0){
    if(memo[idx][open][val+3000]) return;
    memo[idx][open][val+3000] = true;
    if(idx==v.size()){
        used[val+3000] = true;
        return;
    }
    int vv = val+v[idx]*sign[idx]*(open&1?-1:1);
    if(sign[idx] == -1)
        solve(idx+1, open+1, vv);
    if(open>0)
        solve(idx+1, open-1, vv);
    solve(idx+1, open, vv);
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    while(getline(cin, s)){
        v.clear();
        sign.clear();
        sign.push_back(1);
        int x; char c;
        stringstream ss;
        ss << s;
        while(ss >> x){
            v.push_back(x);
            ss >> c;
            sign.push_back(c=='-'?-1:1);
        }
        memset(memo, 0, sizeof(memo));
        used.reset();
        solve();
        cout << used.count() << '\n';
    }
    return 0;
}
