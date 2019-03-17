#include<bits/stdc++.h>
using namespace std;
string s, ans; int n;
bool pla, mirrstr;
int main()
{
		string crap = "BCDFGKNPQR4679";
		unordered_map <char, char> dubl;
		dubl['E'] = '3';
		dubl['3'] = 'E';
		dubl['J'] = 'L';
		dubl['L'] = 'J';
		dubl['S'] = '2';
		dubl['2'] = 'S';
		dubl['Z'] = '5';
		dubl['5'] = 'Z';
        while(cin >> s)
        {
            pla = mirrstr = true;
            n = s.size()-1;
            for(int i = 0; i <= (n+1)/2; ++i)
        	    if(s[i] != s[n-i])
            	    pla = false;
                        
			for(int i = 0; i <= (n+1)/2; ++i)
				if(dubl.find(s[i]) != dubl.end()){
					if(dubl[s[i]] == s[n-i]) continue;
					else mirrstr = false;
				}
                else if(s[i] != s[n-i] || crap.find(s[i]) != string::npos)
            		mirrstr = false;
            		
            if(pla && mirrstr) ans = " -- is a mirrored palindrome.";
            else if(pla) ans = " -- is a regular palindrome."; 
            else if(mirrstr) ans = " -- is a mirrored string.";
            else ans = " -- is not a palindrome.";
            cout << s << ans << endl << endl;
        }
	return 0;
}
