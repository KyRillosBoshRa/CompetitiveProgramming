#include <bits/stdc++.h>

using namespace std;

#define endl                           '\n'
#define mk                             make_pair
#define pb                             push_back
#define REP(i, a, b)                   for (int i = int(a); i < int(b); ++i)
#define rREP(i, a, b)                  for (int i = int(a); i > int(b); --i)
#define ALL(v)				           ((v).begin()), ((v).end())
#define toInt(x)                       (x - '0')
#define UNIQUE(c)                      (c).resize(unique(ALL(c)) - (c).begin())
#define F                              first
#define S                              second
#define popcnt(x)                      __builtin_popcount(x)
//             bit masking
#define isOn(S, j)                     (S & (1 << j))
#define setBit(S, j)                   (S |= (1 << j))
#define clearBit(S, j)                 (S &= ~(1 << j))
#define toggleBit(S, j)                (S ^= (1 << j))
#define lowBit(S)                      (S & (-S))
#define setAll(S, n)                   (S = (1 << n) - 1)

#define modulo(S, N)                   ((S) & (N - 1))   // returns S % N, where N is a power of 2
#define isPowerOfTwo(S)                (!(S & (S - 1)))
#define nearestPowerOfTwo(S)           ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S)              ((S) & (S - 1))
#define turnOnLastZero(S)              ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S)  ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))

typedef long long              ll;
typedef vector <int>           vi;
typedef pair<int, int>         ii;
typedef vector <ii>            vii;

const int INF = (int)1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;
const int NPOS = -1;
const int N = 1000009;

struct team{
    int total_points_earned, games_played, wins, ties, losses, goals_scored, goals_against;
    string name;
    team(){
        total_points_earned=games_played=wins=ties=losses=goals_scored=goals_against=0;
    }
    bool operator > (const team& a) const{
        string n1 = name, n2 = a.name;
        transform(ALL(n1), n1.begin(), ::tolower);
        transform(ALL(n2), n2.begin(), ::tolower);
        if(total_points_earned != a.total_points_earned)
            return total_points_earned > a.total_points_earned;
        if(wins != a.wins)
            return wins > a.wins;
        if(goals_scored-goals_against != a.goals_scored-a.goals_against)
            return goals_scored-goals_against > a.goals_scored-a.goals_against;
        if(goals_scored != a.goals_scored)
            return goals_scored > a.goals_scored;
        if(games_played != a.games_played)
            return games_played < a.games_played;
        return n1 < n2;
    }
};
bool line;
vector<team> vec;
unordered_map<string, team> a;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    int T;
    cin >> T; cin.ignore();
    while(T--){
        vec.clear(); a.clear();
        string t;
        getline(cin, t);
        int nTeams;
        cin >> nTeams;
        cin.ignore();
        string s;
        REP(i, 0, nTeams)
            getline(cin, s), a[s].name = s;
        int q;
        cin >> q;
        cin.ignore();
        char shit;
        string s1, s2;
        int res1, res2;
        while(q--){
            getline(cin, s1, '#');
            cin >> res1 >> shit >> res2 >> shit;
            getline(cin, s2);
            a[s1].goals_scored += res1;
            a[s1].goals_against += res2;
            a[s2].goals_scored += res2;
            a[s2].goals_against += res1;
            ++a[s1].games_played;
            ++a[s2].games_played;
            if(res1 > res2){
                ++a[s1].wins;
                ++a[s2].losses;
                a[s1].total_points_earned += 3;
            }
            else if(res1 < res2){
                ++a[s2].wins;
                ++a[s1].losses;
                a[s2].total_points_earned += 3;
            }
            else{
                ++a[s2].ties;
                ++a[s1].ties;
                ++a[s2].total_points_earned;
                ++a[s1].total_points_earned;
            }
        }
        for(auto it = a.begin(); it != a.end(); ++ it)
            vec.pb(it->S);
        sort(ALL(vec), [](const team& a, const team& b){return a > b;});
        if(line) cout << endl;
        else line = true;
        cout << t << endl;
        REP(i, 0, nTeams){
            cout << i+1 << ") " << vec[i].name << ' ' << vec[i].total_points_earned << "p, " << vec[i].games_played
                 << "g (" << vec[i].wins << '-' << vec[i].ties << '-' << vec[i].losses << "), " << vec[i].goals_scored-vec[i].goals_against
                 << "gd (" << vec[i].goals_scored << '-' << vec[i].goals_against << ")" << endl;
        }
    }
    return 0;
}
