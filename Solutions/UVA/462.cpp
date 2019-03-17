#include <bits/stdc++.h>

using namespace std;

#define endl                   '\n'
#define pb                     push_back
#define REP(i, a, b)           for (int i = int(a); i < int(b); ++i)
#define rREP(i, a, b)          for (int i = int(a); i > int(b); --i)
#define ALL(x)                 (x).begin(), (x).end()
#define toint(x)               (x - '0')

typedef long long              ll;
typedef vector <int>           vi;

const int INF = (int)1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;
const int NPOS = -1;

const int MAX = 13;
int S, H, D, C, score;
bool sS, sH, sD, sC; //stoped
string arr[MAX];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	while(cin.peek() != EOF)
	{
		REP(i, 0, MAX)
		{
			cin >> arr[i];
			arr[i][1] == 'S' ? ++S : arr[i][1] == 'H' ? ++H : arr[i][1] == 'D' ? ++D : ++C;
			arr[i][0] == 'A' ? score += 4 : arr[i][0] == 'K' ? score += 3 : arr[i][0] == 'Q' ? score += 2 : arr[i][0] == 'J' ? ++score : 0;
		}
		cin.ignore();
		REP(i, 0, MAX) // subtract
		{
			if(arr[i][0] == 'K')
				if(arr[i][1] == 'S') {
					if(S - 1 == 0) --score;
				}
				else if(arr[i][1] == 'H'){
					if(H - 1 == 0) --score;
				}
				else if(arr[i][1] == 'D'){
					if(D - 1 == 0) --score;
				}
				else {
					if(C - 1 == 0) --score;
				}
			if(arr[i][0] == 'Q')
				if(arr[i][1] == 'S') {
					if(S - 1 < 2) --score;
				}
				else if(arr[i][1] == 'H'){
					if(H - 1 < 2) --score;
				}
				else if(arr[i][1] == 'D'){
					if(D - 1 < 2) --score;
				}
				else {
					if(C - 1 < 2) --score;
				}
			if(arr[i][0] == 'J')
				if(arr[i][1] == 'S') {
					if(S - 1 < 3) --score;
				}
				else if(arr[i][1] == 'H'){
					if(H - 1 < 3) --score;
				}
				else if(arr[i][1] == 'D'){
					if(D - 1 < 3) --score;
				}
				else {
					if(C - 1 < 3) --score;
				}
		}
		REP(i, 0, MAX) // stoped?!
		{
			if(arr[i][0] == 'A')
				if(arr[i][1] == 'S') sS = true;
				else if(arr[i][1] == 'H') sH = true;
				else if(arr[i][1] == 'D') sD = true;
				else sC = true;
			if(arr[i][0] == 'K')
				if(arr[i][1] == 'S') {
					if(S - 1 >= 1) sS = true;
				}
				else if(arr[i][1] == 'H'){
					if(H - 1 >= 1) sH = true;
				}
				else if(arr[i][1] == 'D'){
					if(D - 1 >= 1) sD = true;
				}
				else {
					if(C - 1 >= 1) sC = true;
				}
			if(arr[i][0] == 'Q')
				if(arr[i][1] == 'S') {
					if(S - 1 >= 2) sS = true;
				}
				else if(arr[i][1] == 'H'){
					if(H - 1 >= 2) sH = true;
				}
				else if(arr[i][1] == 'D'){
					if(D - 1 >= 2) sD = true;
				}
				else {
					if(C - 1 >= 2) sC = true;
				}
		}
		if(score >= 16 && sC + sH + sD + sS == 4) cout << "BID NO-TRUMP" << endl;
		else
		{
			if(S == 2) ++score; else if(S <= 1) score += 2;
			if(C == 2) ++score; else if(C <= 1) score += 2;
			if(D == 2) ++score; else if(D <= 1) score += 2;
			if(H == 2) ++score; else if(H <= 1) score += 2;
			if (score < 14) cout << "PASS" << endl;
			else
			{
				if (max(S, max(D, max(H, C))) == S) cout << "BID S" << endl;
				else if (max(S, max(D, max(H, C))) == H) cout << "BID H" << endl;
				else if (max(S, max(D, max(H, C))) == D) cout << "BID D" << endl;
				else cout << "BID C" << endl;
			}
		}
		C = H = D = S = score = sC = sS = sH = sD = 0;
	}
	return 0;
}
