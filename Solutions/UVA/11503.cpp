#include <bits/stdc++.h>
using namespace std;

unordered_map<string, string> parent;
unordered_map<string, int> Size;

string find_parent(string x){
    while(parent[x] != x) x = parent[x];
    return x;
}
void Union(string a, string b){
    a = find_parent(a);
    b = find_parent(b);
    if(a == b) return;
    if(Size[a] < Size[b]) swap(a, b);
    Size[a] += Size[b];
    parent[b] = a;
}
int T, n;
string x, y;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 0; i < n; ++i){
            cin >> x >> y;
            if(parent.find(x) == parent.end()) parent[x] = x, Size[x] = 1;
            if(parent.find(y) == parent.end()) parent[y] = y, Size[y] = 1;
            Union(x, y);
            cout << Size[find_parent(x)] << '\n';
        }
        parent.clear();
        Size.clear();
    }
    return 0;
}
